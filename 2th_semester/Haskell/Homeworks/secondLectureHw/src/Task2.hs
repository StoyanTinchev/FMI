module Task2
  ( sumDigitsIter,
  )
where

sumDigitsIter :: Int -> Int
sumDigitsIter num = helper num 0
  where
    helper 0 sum = sum
    helper curr sum = helper (div curr 10) (sum + mod curr 10)