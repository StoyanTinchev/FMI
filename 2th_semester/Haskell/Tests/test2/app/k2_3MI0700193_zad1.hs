prodOdds :: (Num a) => [a] -> a
prodOdds = foldr (\(i, v) acc -> if odd i then v * acc else acc) 1 . zip [0 ..]

main :: IO ()
main = do
  print "Task 1"
  print $ prodOdds [1, 2, 3, 4, 5, 6] == 48
  print $ prodOdds [7.66, 7, 7.99, 7] == 49.0
