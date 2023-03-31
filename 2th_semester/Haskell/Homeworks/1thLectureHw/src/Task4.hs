module Task4
  ( myGcdG,
    myGcdPM,
  )
where

myGcdG :: Int -> Int -> Int
myGcdG x y
  | y == 0 = x
  | otherwise = myGcdG y (mod x y)

-- with pattern matching
myGcdPM :: Int -> Int -> Int
myGcdPM x 0 = x
myGcdPM x y = myGcdPM y (mod x y)
