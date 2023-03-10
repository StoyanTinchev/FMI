module Task5
  ( areAmicable,
  )
where

sumDivs :: Int -> Int
sumDivs num = helper (div num 2) 0
  where
    helper 0 sum = sum
    helper curr sum
      | mod num curr == 0 = helper (curr - 1) (sum + curr)
      | otherwise = helper (curr - 1) sum

areAmicable :: Int -> Int -> Bool
areAmicable n1 n2 = sumDivs n1 == n2 || sumDivs n2 == n1