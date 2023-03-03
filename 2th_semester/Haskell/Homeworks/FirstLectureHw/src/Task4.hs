module Task4
  ( myGcdG,
    myGcdPM,
  )
where
  
myGcdG :: Int -> Int -> Int
myGcdG x y = if y == 0 then x else myGcdG y (x `mod` y)

-- with pattern matching
myGcdPM :: Int -> Int -> Int
myGcdPM x 0 = x
myGcdPM x y = myGcdPM y (x `mod` y)