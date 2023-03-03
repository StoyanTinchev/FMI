module Task4
  ( isPrime,
  )
where

isPrime :: Int -> Bool
isPrime n = n > 1 && helper 2
  where
    helper d
      | d >= n = True
      | mod n d == 0 = False
      | otherwise = helper (d + 1)