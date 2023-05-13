module Task6 (pairCompose) where

pairCompose :: [Int -> Int] -> (Int -> Int)
pairCompose fs x = sum [(f1 . f2) x | (f1, f2) <- pairs fs]

pairs :: [Int -> Int] -> [(Int -> Int, Int -> Int)]
pairs [] = []
pairs [f] = [(f, id)]
pairs (f1 : f2 : fs) = (f1, f2) : pairs fs
