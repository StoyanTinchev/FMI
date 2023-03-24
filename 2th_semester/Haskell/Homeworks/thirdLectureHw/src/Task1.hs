module Task1 (removeFistOccurrence) where

--Define a function that removes the first occurrence of a digit in a number by going from right to left.
--For example, removeFistOccurrence 110 1 == 10
removeFistOccurrence :: Int -> Int -> Int
removeFistOccurrence num occ = helper num 0 0
  where
    helper :: Int -> Int -> Int -> Int
    helper curr pastNum iter
      | mod curr 10 == occ = 10 ^ iter * div curr 10 + pastNum
      | otherwise = helper (div curr 10) (10 ^ iter * mod curr 10 + pastNum) (iter + 1)
