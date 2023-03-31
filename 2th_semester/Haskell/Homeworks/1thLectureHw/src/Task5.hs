module Task5
  ( isLeapYearOneLine,
    isLeapYearGuards,
  )
where

isLeapYearOneLine :: Int -> Bool
isLeapYearOneLine year =
  (mod year 4 == 0 && mod year 100 /= 0) || (mod year 400 == 0)

isLeapYearGuards :: Int -> Bool
isLeapYearGuards year
  | mod year 400 == 0 = True
  | mod year 100 == 0 = False
  | mod year 4 == 0 = True
  | otherwise = False
