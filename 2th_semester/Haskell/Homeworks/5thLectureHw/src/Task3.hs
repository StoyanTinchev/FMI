module Task3 (isArithmentic) where

isArithmentic :: [Int] -> Bool
isArithmentic [] = True
isArithmentic [_] = True
isArithmentic [_, _] = True
isArithmentic (x : y : xs) = (y - x) == (head xs - y) && isArithmentic (y : xs)
