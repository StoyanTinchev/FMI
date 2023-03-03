module Task2
  (
    sumCubesPow,
    sumCubesNoPow,
  )
 where

sumCubesPow :: Integer -> Integer -> Integer
sumCubesPow a b = sum [x ^ (3 :: Int) | x <- [a, b]]
  
sumCubesNoPow :: Integer -> Integer -> Integer
sumCubesNoPow a b = sum [x * x * x | x <- [a, b]]