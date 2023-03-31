module Task5 (isAscending) where

import Data.Char (digitToInt)
import Data.List (sort)

isAscending :: Int -> Bool
isAscending num = map digitToInt (show num) == sort (map digitToInt (show num))
