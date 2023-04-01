module Task1
  ( getPrimesLC,
    getPrimesHOF,
  )
where

import Data.Char (digitToInt)

getPrimesLC :: Int -> Int -> [Int]
getPrimesLC start end = filter (elem 7 . map digitToInt . show) (filter (\num -> [y | y <- [1 .. num], mod num y == 0] == [1, num]) [min start end .. max start end])

getPrimesHOF :: Int -> Int -> [Int]
getPrimesHOF start end = [x | x <- [min start end .. max start end], elem 7 (map digitToInt (show x)), [y | y <- [1 .. x], mod x y == 0] == [1, x]]
