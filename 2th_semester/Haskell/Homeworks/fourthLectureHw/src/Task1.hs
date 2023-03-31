module Task1
  ( mySumRecNonPM,
    mySumRecPM,
    mySumFunc,
  )
where

mySumRecNonPM :: (Num a) => [a] -> a
mySumRecNonPM xs
  | null xs = 0
  | otherwise = head xs + mySumRecNonPM (tail xs)

mySumRecPM :: (Num a) => [a] -> a
mySumRecPM [] = 0
mySumRecPM (x : xs) = x + mySumRecPM xs

mySumFunc :: (Num a) => [a] -> a
mySumFunc = sum
