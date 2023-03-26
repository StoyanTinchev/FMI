module Main (main) where

import Lib

-- Задача 3. Да се дефинира функция, която намира дали даден елемент се съдържа в списък.
contains :: (Eq a) => a -> [a] -> Bool
contains _ [] = False
contains x (y : ys) = x == y || contains x ys

-- Задача 4. Да се дефинира функция, която генерира списък с простите числа в интервала [a,b].
generate :: Int -> Int -> [Int]
generate a b = [x | x <- [a .. b], [y | y <- [1 .. x], mod x y == 0] == [1, x]]

isPrime :: Int -> Bool
isPrime n = [y | y <- [1 .. n], mod n y == 0] == [1, n]

-- Задача 5. Да се дефинира функция, която премахва първия елемент, равен на x, от даден списък.
removeFirst :: (Eq a) => a -> [a] -> [a]
removeFirst _ [] = []
removeFirst d (x : xs)
  | d == x = xs
  | otherwise = x : removeFirst d xs

-- Задача 6. Да се дефинира функция, която премахва всички елементи на даден списък, които са равни на x.
removeEvery :: (Eq a) => a -> [a] -> [a]
removeEvery _ [] = []
removeEvery d (x : xs)
  | d == x = removeEvery d xs
  | otherwise = x : removeEvery d xs

-- Задача 7. Да се дефинира функция incrementAllBy :: [Int] -> Int -> [Int],
-- която получава списък и число и го добавя към всеки елемент на списъка.
incrementAllBy :: [Int] -> Int -> [Int]
incrementAllBy xs num = [x + num | x <- xs]

main :: IO ()
main = do
  print $ isPrime 1
  print $ contains 5 [1 .. 5]

  print $ generate 1 100

  print $ removeFirst 4 [1, 4, 5, 4]

  print $ removeEvery 4 [1, 4, 5, 4]

  print $ incrementAllBy [1 .. 3] 1
