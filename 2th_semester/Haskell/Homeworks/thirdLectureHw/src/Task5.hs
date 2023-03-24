module Task5 (p) where

--A number - x, is a pentagonal number if we 
-- can plot x points in the form of a pentagon on a plain.

--Implementation detail: Create a linearly iterative process.
p :: Int -> Int
p n = helper 1 1
  where
    helper :: Int -> Int -> Int
    helper i acc
      | i == n = acc
      | otherwise = helper (i + 1) (acc + 3 * i + 1)
      
-- p n = n * (3 * n - 1) `div` 2
