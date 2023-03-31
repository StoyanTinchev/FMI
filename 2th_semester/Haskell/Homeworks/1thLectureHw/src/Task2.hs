module Task2
  ( sumCubesPow,
    sumCubesNoPow,
  )
where

sumCubesPow :: Int -> Int -> Int
sumCubesPow x y = x^3 + y^3

sumCubesNoPow :: Int -> Int -> Int
sumCubesNoPow x y = x * x * x + y * y * y
