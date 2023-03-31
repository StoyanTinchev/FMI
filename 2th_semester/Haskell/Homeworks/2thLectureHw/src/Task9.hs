module Task9
  ( everyOther,
  )
where

everyOther :: Int -> Int
everyOther number = helper number 0 True
  where
    helper 0 newNum _ = newNum
    helper num newNum skip
      | skip = helper (div num 10) newNum False
      | otherwise = helper (div num 10) (10 * newNum + mod num 10) True
