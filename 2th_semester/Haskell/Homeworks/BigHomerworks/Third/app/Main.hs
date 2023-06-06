import Data.Char (isDigit, isLetter)
import Data.List (sort)
import Data.Maybe (fromMaybe)

type Variable = (Char, Int)

simplify :: String -> String
simplify = printExpr . foldl eval (0, []) . parse . removeParens
  where
    -- Evalutes an expression by maintaining a sum and a list of variables.
    eval :: (Int, [Variable]) -> Either Int Variable -> (Int, [Variable])
    eval (sum, vars) (Left n) = (sum + n, vars)
    eval (sum, vars) (Right v) = (sum, mergeVariable v vars)

    -- Merges a variable into a list by adding or subtracting it from an existing variable.
    mergeVariable :: Variable -> [Variable] -> [Variable]
    mergeVariable (c, n) vars =
      let (pre, rest) = span ((c /=) . fst) vars
       in case rest of
            [] -> sort $ (c, n) : vars -- Variable not found: append and sort.
            (_, m) : vs -> pre ++ (c, m + n) : vs -- Variable found: add/subtract it.

    -- Parses a string into numbers and variables.
    parse :: String -> [Either Int Variable]
    parse "" = []
    parse (c : cs)
      | c == '+' = parse cs
      | c == '-' = let (n, rest) = parseNumVar cs in mapLeft negate n : parse rest
      | otherwise = let (n, rest) = parseNumVar (c : cs) in n : parse rest

    mapLeft f (Left x) = Left (f x)
    mapLeft _ (Right x) = Right x

    -- Parses a number or a variable.
    parseNumVar :: String -> (Either Int Variable, String)
    parseNumVar (c : cs)
      | isDigit c = let (n, rest) = span isDigit cs in (Left $ read (c : n), rest)
      | isLetter c =
          case span isDigit cs of
            ("", rest) -> (Right (c, 1), rest)
            (n, rest) -> (Right (c, read n), rest)

    -- Removes parentheses by repeatedly applying basic arithmetic.
    removeParens :: String -> String
    removeParens expr =
      if '(' `elem` expr
        then removeParens $ evalParens expr
        else expr

    -- Evaluates the first parenthesized expression it finds.
    evalParens :: String -> String
    evalParens expr = pre ++ show (foldl eval (0, []) $ parse inner) ++ post
      where
        (pre, rest) = break (== '(') expr
        (inner, post) = let (a, b) = span (/= ')') rest in (a, tail b)

    -- Prints an expression.
    printExpr :: (Int, [Variable]) -> String
    printExpr (sum, vars) =
      let vs = concatMap printVar $ filter ((/= 0) . snd) vars
       in vs ++ (if sum == 0 && vs /= "" then "" else show sum)

    -- Prints a variable.
    printVar :: Variable -> String
    printVar (c, n) = show n ++ [c]

main :: IO ()
main = do
  print $ simplify "1+2+x" -- ➝ "x+3"
  print $ simplify "x+2+x-2" -- ➝ "2x"
  print $ simplify "x+2-(x-2)" -- ➝ "4"
  print $ simplify "y+2+x-2" -- ➝ "x+y"
  print $ simplify "1+2+x+y+x+z+5-x-x-x+y" -- ➝ "-x+2y+z+8"
  print $ simplify "1+2+x+y+x-(x-x-x)+z+y-9" -- ➝ "3x+2y+z-6"
  print $ simplify "1+2-(3-(3-2))-9" -- ➝ "-8"
