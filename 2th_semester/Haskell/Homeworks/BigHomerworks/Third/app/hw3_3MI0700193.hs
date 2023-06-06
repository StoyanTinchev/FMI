data NTree a = T a [NTree a] deriving (Show)

isStick :: NTree a -> Bool
isStick (T _ ts) = length ts < 2 && all isStick ts

prune :: NTree a -> NTree a
prune (T x ts)
  | isStick (T x ts) = T x (take 1 $ map pruneChild ts)
  | otherwise = T x (map prune ts)
  where
    pruneChild (T y _) = T y []

main :: IO ()
main = do
  print $ prune (T 1 [T 2 [T 3 []], T 4 [T 5 [T 6 []]], T 7 [T 8 [], T 9 [T 10 [T 11 []]]]])
