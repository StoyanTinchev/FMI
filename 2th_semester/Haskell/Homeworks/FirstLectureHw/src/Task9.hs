module Task9
  ( rev,
  )
where

rev :: Integer -> Integer
rev num = helper num 0
  where
    helper :: Integer -> Integer -> Integer
    helper currNum newNum
      | mod currNum 10 == 0 = newNum
      | otherwise = helper (div currNum 10) (10 * newNum + mod currNum 10)