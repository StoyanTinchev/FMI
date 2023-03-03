module Task2
  ( sumDigitsIter,
  )
where

sumDigitsIter :: Int -> Int
sumDigitsIter num = helper num 0
  where
    helper curr sum
      | curr == 0 = sum
      | otherwise = helper (div curr 10) (sum + mod curr 10)