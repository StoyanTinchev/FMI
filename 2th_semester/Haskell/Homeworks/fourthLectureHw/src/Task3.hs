module Task3
  ( primesInRangeLC,
    primesInRangeHOF,
  )
where

primesInRangeLC :: Int -> Int -> [Int]
primesInRangeLC start end = [x | x <- [min start end .. max start end], [y | y <- [1 .. x], mod x y == 0] == [1, x]]

primesInRangeHOF :: Int -> Int -> [Int]
primesInRangeHOF start end = filter (\num -> [y | y <- [1 .. num], mod num y == 0] == [1, num]) [x | x <- [min start end .. max start end], length (show x) > 2]
