import Data.List (nub)

data NTree a = Nil | Node a [NTree a] deriving (Eq, Show)

mapLevel :: NTree a -> [(a -> b)] -> NTree b
mapLevel tree fs = mapLevel' tree fs 1
  where
    mapLevel' :: NTree a -> [(a -> b)] -> Int -> NTree b
    mapLevel' Nil _ _ = Nil
    mapLevel' (Node x children) fs height
      | height > length fs = Nil
      | otherwise = Node ((fs !! (height - 1)) x) (mapChild (map (\child -> mapLevel' child fs (height + 1)) children))
    mapChild [] = []
    mapChild (Nil : xs) = mapChild xs
    mapChild (x : xs) = x : mapChild xs

main :: IO ()
main = do
  let t1 = Node 10 [Node 10 [Node 10 [], Node 8 [Node 10 []], Node 2 []], Node 10 [Node 11 [], Node 10 [], Node 6 []]]
  let t2 = Node 's' [Node 's' [Node 's' [], Node 's' []]]
  let t11Result = Node 20 [Node 40 [Node 0 [], Node 0 [], Node 0 []], Node 40 [Node 0 [], Node 0 [], Node 0 []]]
  let t12Result = Node "10" [Node "10" [], Node "10" []]
  let t2Result = Node "r" [Node "w_s" [Node "l_s" [], Node "l_s" []]]

  print $ mapLevel t1 [(* 2), (* 4), (`div` 100)] == t11Result
  print $ mapLevel t1 [show, (nub . show . (* 1000))] == t12Result
  print $ mapLevel t2 [(\_ -> "r"), (\char -> "w_" ++ [char]), (\char -> "l_" ++ [char])] == t2Result
