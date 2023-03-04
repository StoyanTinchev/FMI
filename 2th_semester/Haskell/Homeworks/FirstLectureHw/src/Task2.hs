module Task2
  ( sumCubesPow,
    sumCubesNoPow,
  )
where

sumCubesPow :: Integer -> Integer -> Integer
sumCubesPow a b = a ^ (3 :: Int) + b ^ (3 :: Int)

sumCubesNoPow :: Integer -> Integer -> Integer
sumCubesNoPow a b = a * a * a + b * b * b
