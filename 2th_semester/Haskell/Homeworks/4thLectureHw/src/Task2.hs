module Task2
  ( isPresentRecNonPM,
    isPresentRecPM,
    isPresentFunc,
  )
where

isPresentRecNonPM :: (Eq a) => a -> [a] -> Bool
isPresentRecNonPM x xs
  | null xs = False
  | x == head xs = True
  | otherwise = isPresentRecNonPM x (tail xs)

isPresentRecPM :: (Eq a) => a -> [a] -> Bool
isPresentRecPM _ [] = False
isPresentRecPM x (y : ys)
  | x == y = True
  | otherwise = isPresentRecPM x ys

isPresentFunc :: (Eq a) => a -> [a] -> Bool
isPresentFunc = elem
