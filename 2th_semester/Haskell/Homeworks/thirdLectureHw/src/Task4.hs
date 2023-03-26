module Task4 (sumDivisibleNumbers) where

--  Define a function sumDivisibleNumbers start finish k
--  that returns the sum of all numbers from the interval
--  [start, finish] whose digits sum up to a number that
--  is evenly divisible by k.
sumDivisibleNumbers :: Int -> Int -> Int -> Int
sumDivisibleNumbers x y k = helper (min x y) (max x y)
  where
    helper :: Int -> Int -> Int
    helper start finish
      | start == finish = 0
      | mod start k == 0 = start + helper (start + 1) finish
      | otherwise = helper (start + 1) finish

-- print $ sumDivisibleNumbers 0 10 5 -- == 5
--  print $ sumDivisibleNumbers 0 100 5 -- == 990
--  print $ sumDivisibleNumbers 100 0 5 -- == 990
