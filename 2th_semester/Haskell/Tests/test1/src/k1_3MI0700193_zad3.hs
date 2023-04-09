import Data.List (sort)

numContentChildren :: [Int] -> [Int] -> Int
numContentChildren gs ss = go (sort gs) (sort ss) 0
  where
    go [] _ satisfied = satisfied
    go _ [] satisfied = satisfied
    go (g : igs) (s : iss) satisfied
      | s >= g = go igs iss (satisfied + 1)
      | otherwise = go (g : igs) iss satisfied

main :: IO ()
main = do
  print $ numContentChildren [1, 2, 3] [1, 1] -- → 1
  print $ numContentChildren [1, 2] [1, 2, 3] -- → 2
