module Task4 (specialSum) where

specialSum :: Int -> Int -> Int
specialSum start end = sum [x | x <- [start .. end], elem '6' $ show x, mod (x - 1) 4 == 0]
