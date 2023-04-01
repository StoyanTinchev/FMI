module Task2 (getPalindromes) where

getPalindromes :: Int -> Int
getPalindromes n = let d = [x | x <- [2 .. n], mod n x == 0, show x == reverse (show x)] in minimum d + maximum d
