module Task5 (applyN) where

applyN :: (a -> a) -> Int -> a -> a
applyN _ 0 x = x
applyN f n x = f (applyN f (n - 1) x)
