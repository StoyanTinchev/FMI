module Lib
    ( fact
    ) where
      
fact :: (Eq t, Num t) => t -> t
fact n = if n == 0 then 1 else n * fact (n - 1)


fib :: (Eq t, Num t, Num a) => t -> a
fib n
  | n == 0 = 0
  | n == 1 = 1
  | otherwise = fib (n - 1) + fib (n - 2)
