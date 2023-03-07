module Task1
  ( isEvenIf,
    isEvenGuards,
  )
where

isEvenIf :: Int -> String
isEvenIf num = if mod num 2 == 0 then "Yes" else "No"

isEvenGuards :: Int -> String
isEvenGuards num
  | mod num 2 == 0 = "Yes"
  | otherwise = "No"