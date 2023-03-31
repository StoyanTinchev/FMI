module Task4
  ( sumUnevenLC,
    sumUnevenHOF,
  )
where

sumUnevenLC :: Int -> Int -> Int
sumUnevenLC start end = sum [x | x <- [min start end .. max start end], odd x]

sumUnevenHOF :: Int -> Int -> Int
sumUnevenHOF start end = sum $ filter odd [min start end .. max start end]
