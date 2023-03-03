module Task2
  ( sumDigitsRec,
  )
where

  
sumDigitsRec :: Int -> Int
sumDigitsRec 0 = 0
sumDigitsRec num = sumDigitsRec (div num 10) + mod num 10