module Task2 (sortN, findMax) where

import Task1

findMax :: Int -> Int
findMax n = helper (div n 10) (mod n 10)
  where
    helper :: Int -> Int -> Int
    helper 0 result = result
    helper leftover result
      | mod leftover 10 > result = helper (div leftover 10) (mod leftover 10)
      | otherwise = helper (div leftover 10) result

--Define a function that sorts a number in descending order.
sortN :: Int -> Int
sortN num = helper num 0
  where
    helper :: Int -> Int -> Int
    helper 0 descNum
      | descNum < num = 10 * descNum
      | otherwise = descNum
    helper currNum descNum =
      helper (removeFistOccurrence currNum (findMax currNum)) (10 * descNum + findMax currNum)
