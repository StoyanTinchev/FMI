-- Родител иска да даде по една бисквитка на всяко от децата си.
-- Всяко дете i има изискване g[i], което е минималният размер на бисквитката,
-- с която то ще се задоволи. Всяка бисквитка j има размер s[j]. Ако s[j] >= g[i],
-- можем да дадем бисквитката j на детето i и то ще бъде доволно.
--
-- Да се дефинира функция numContentChildren :: [Int] -> [Int] -> Int,
-- която приема списък gs с изискванията на децата и списък ss с размерите на бисквитките
-- и намира максималния брой на децата, които ще бъдат доволни.
--
-- Примери:
-- numContentChildren [1, 2, 3] [1, 1] → 1
-- numContentChildren [1, 2] [1, 2, 3] → 2
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
