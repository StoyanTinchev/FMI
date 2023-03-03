--module Main (main) where
--
--import Lib
--
--main :: IO ()
--main = print (fact 0 :: Int)


main :: IO ()
main = do print (myMin 1.2 1.5 :: Double)
          print (isInside 1 2 3)
          print (calcAverage 1 2 :: Double)
          print (fibRec 3 :: Integer)
          print (fibIter 3 :: Integer)

myMin :: Ord a => a -> a -> a
myMin a b = if a < b then a else b
  
isInside :: Int -> Int -> Int -> Bool
isInside x y z = x <= y && y <= z
  
calcAverage :: Double -> Double -> Double
calcAverage a b = (a ^ (2 :: Int) + b ^ (2 :: Int)) / 2
  
fibRec :: Int -> Integer
fibRec n = if n == 0 then 0 else if n == 1 then 1 else fibRec (n - 1) + fibRec (n - 2)

fibIter :: Int -> Integer
fibIter n = helper 0 1 0 n

helper :: Integer -> Integer -> Int -> Int -> Integer
helper prev cur i n = 
  if i == n then cur
  else helper cur (prev + cur) (i + 1) n

--  1 + 2  <=> (+) 1 2
--  1 - 2  <=> (-) 1 2
--  1 * 2  <=> (*) 1 2
--  1 / 2  <=> (/) 1 2  (only for doubles)
--  1 `div` 2  <=> div 1 2 (only for integers)
--  1 `mod` 2  <=> mod 1 2
--  1 ^ 2  <=> (^) 1 2
--  1 == 2  <=> (==) 1 2
--  1 /= 2  <=> (/=) 1 2  (not equal (!=))


--  1 ** 2 <=> (^) 1 2
-- ** is for real numbers, while ^ is for integers
