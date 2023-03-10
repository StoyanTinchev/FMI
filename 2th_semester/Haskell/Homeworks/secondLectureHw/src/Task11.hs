module Task11
  ( truncatablePrime,
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
      
truncatablePrime :: Int -> Bool
truncatablePrime 0 = True
truncatablePrime number = isPrime number && truncatablePrime (div number 10)