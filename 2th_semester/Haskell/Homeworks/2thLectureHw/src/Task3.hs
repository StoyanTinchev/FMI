module Task3
  ( isPrime,
    sumPrimeDivs,
  )
where

isPrime :: Int -> Bool
isPrime num = helper (num - 1)
  where
    helper :: Int -> Bool
    helper 1 = True
    helper prime
      | mod num prime == 0 = False
      | otherwise = helper $ prime - 1

sumPrimeDivs :: Int -> Int
-- sumPrimeDivs 0 = 0
sumPrimeDivs num = helper num 0
  where
    helper 0 sum = 0
    helper 1 sum = sum
    helper n sum
      | isPrime n && mod num n == 0 = helper (n - 1) (sum + n)
      | otherwise = helper (n - 1) sum
