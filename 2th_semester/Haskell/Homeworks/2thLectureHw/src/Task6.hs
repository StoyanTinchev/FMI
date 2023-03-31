module Task6
  ( isInteresting,
  )
where

import Task2

isInteresting :: Int -> Bool
isInteresting num = mod num (sumDigitsIter num) == 0
