module Task4
  ( countOccurences,
  )
where

countOccurences :: Int -> Int -> Int
countOccurences num occ
  | num == occ = 1
  | otherwise = helper num 0
  where
    helper 0 sum = sum
    helper n sum
      | mod n 10 == occ = helper (div n 10) (sum + 1)
      | otherwise = helper (div n 10) sum