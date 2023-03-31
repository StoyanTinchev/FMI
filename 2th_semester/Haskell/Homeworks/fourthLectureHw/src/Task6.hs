module Task6 (sumSpecialPrimes) where

import Data.Char (digitToInt)

sumSpecialPrimes :: Int -> Int -> Int
sumSpecialPrimes n d = sum $ take n $ filter (elem d . map digitToInt . show) (filter (\num -> [y | y <- [1 .. num], mod num y == 0] == [1, num]) [1 ..])
