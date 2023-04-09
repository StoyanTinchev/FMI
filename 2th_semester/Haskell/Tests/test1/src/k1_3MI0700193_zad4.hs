-- Нека списък B от префиксни суми на списък A се дефинира като:
-- B[0] = A[0]
-- B[1] = A[0] + A[1]
-- B[2] = A[0] + A[1] + A[2]
-- ...
-- B[n-1] = A[0] + A[1] + ... + A[n-1]

-- Нека списък B от суфиксни суми на списък A се дефинира като:
-- B[0] = A[0] + A[1] + A[2] + ... + A[n-1]
-- B[1] = A[1] + A[2] + ... + A[n-1]
-- ...
-- B[n-2] = A[n-2] + A[n-1]
-- B[n-1] = A[n-1]

-- Да се дефинира функция prefixToSuffix :: (Num a) => [a] -> [a],
-- която приема списък от префиксни суми xs и връща списък от суфиксните суми на списъка, от който e образуван xs.

-- Примери:
-- prefixToSuffix [1, 3, 6, 10, 15] -> [15, 14, 12, 9, 5]
-- prefixToSuffix [0] -> [0]
-- prefixToSuffix [-1, -2, -3, -4, -5] -> [-5, -4, -3, -2, -1]
-- prefixToSuffix [1, -4, 2, 90, 100, -1] -> [-1, -2, 3, -3, -91, -101]
-- prefixToSuffix [1, 0, 1, 0, 1, 0, 1, 0] -> [0, -1, 0, -1, 0, -1, 0, -1]
-- prefixToSuffix [0, 0, 0, 0, 0, 0, 0, 0, 0, 1] -> [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
-- prefixToSuffix [0, 0, 0, 0, 0, 0, 1, 1, 1, 1] -> [1, 1, 1, 1, 1, 1, 1, 0, 0, 0]
listB :: (Num a) => [a] -> [a]
listB xs = reverse . fst $ foldl step ([], 0) xs
  where
    step (acc, prev) x = let s = x - prev in (s : acc, x)

prefixToSuffix :: (Num a) => [a] -> [a]
prefixToSuffix xs = helper 0
  where
    helper i
      | i == length xs = []
      | otherwise = (sum . drop i $ listB xs) : helper (i + 1)

main :: IO ()
main = do
  print $ prefixToSuffix [1, 3, 6, 10, 15] -- -> [15, 14, 12, 9, 5]
  print $ prefixToSuffix [0] -- -> [0]
  print $ prefixToSuffix [-1, -2, -3, -4, -5] -- -> [-5, -4, -3, -2, -1]
  print $ prefixToSuffix [1, -4, 2, 90, 100, -1] -- -> [-1, -2, 3, -3, -91, -101]
  print $ prefixToSuffix [1, 0, 1, 0, 1, 0, 1, 0] -- -> [0, -1, 0, -1, 0, -1, 0, -1]
  print $ prefixToSuffix [0, 0, 0, 0, 0, 0, 0, 0, 0, 1] -- -> [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
  print $ prefixToSuffix [0, 0, 0, 0, 0, 0, 1, 1, 1, 1] -- -> [1, 1, 1, 1, 1, 1, 1, 0, 0, 0]
