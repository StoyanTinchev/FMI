data NTree a = T a [(NTree a)] deriving (Show)

prune :: NTree a -> NTree a
prune (T x children) = T x (map pruneHelper children)
  where
    pruneHelper (T y [c]) = T y [prune c]
    pruneHelper (T y cs) = T y (take 1 cs)

main :: IO ()
main = do
  print $ "Hello, world!"

  print $ prune T 1 [T 2 [T 3 []], T 4 [T 5 [T 6 []]], T 7 [T 8 [], T 9 [T 10 [T 11 []]]]] == T 1 [T 2 [T 3 []], T 4 [T 5 []], T 7 [T 8 [], T 9 [T 10 []]]]
