import Data.Char (ord, toLower)

solve :: [String] -> [Int]
solve = map (\word -> length . filter id $ zipWith (\i c -> ord c - ord 'a' == i) [0 ..] $ map toLower word)

main :: IO ()
main = do
  print "Task 2"
  print $ solve ["abode", "ABc", "xyzD"] == [4, 3, 1]
  print $ solve ["abide", "ABc", "xyz"] == [4, 3, 0]
  print $ solve ["IAMDEFANDJKL", "thedefgh", "xyzDEFghijabc"] == [6, 5, 7]
  print $ solve ["encode", "abc", "xyzD", "ABmD"] == [1, 3, 1, 3]
