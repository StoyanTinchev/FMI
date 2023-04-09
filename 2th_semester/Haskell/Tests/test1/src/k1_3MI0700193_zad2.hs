import Data.List (group, sort)

fib :: Integer -> Integer
fib n = fib' n 0 1
  where
    fib' 0 a _ = a
    fib' num a b = fib' (num - 1) b (a + b)

maxPair :: String -> (Char, Int)
maxPair s = foldr maxByCountAndChar ('0', 0) $ map (\c -> (head c, length c)) $ group $ sort s
  where
    maxByCountAndChar p1 p2
      | count1 > count2 = p1
      | count1 < count2 = p2
      | char1 < char2 = p1
      | otherwise = p2
      where
        (char1, count1) = p1
        (char2, count2) = p2

splitIntoChunks :: Int -> String -> [String]
splitIntoChunks _ [] = []
splitIntoChunks k s = take k s : splitIntoChunks k (drop k s)

aroundFib :: Integer -> (Int -> [(Char, Int)])
aroundFib n = \k -> map maxPair $ splitIntoChunks k (show $ fib n)

main :: IO ()
main = do
  print $ aroundFib 100 25
  print $ aroundFib 180 25
  print $ aroundFib 1700 25
  print $ aroundFib 500 42
  print $ aroundFib 6000 242

-- (aroundFib 100) 25 → [('1',3)]
-- (aroundFib 180) 25 → [('1',5),('7',3)]
-- (aroundFib 1700) 25 → [('1',4),('2',5),('0',6),('4',5),('5',7),('2',4),('6',7),('3',5),('0',4),('8',5),('4',5),('4',4),('7',7),('7',6),('2',2)]
-- (aroundFib 500) 42 → [('0',6),('2',7),('2',6)]
-- (aroundFib 6000) 242 → [('5',31),('8',33),('8',31),('7',35),('7',31),('4',7)]
