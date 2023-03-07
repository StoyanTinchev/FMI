module Task8
  ( removeD,
  )
where

removeD :: Int -> Int -> Int
removeD toRemove number = helper number 0 0
  where
    helper 0 newNum _ = newNum
    helper num newNum i
      | mod num 10 == toRemove = helper (div num 10) newNum i
      | otherwise = helper (div num 10) (10^i * mod num 10 + newNum) (i + 1)
      
-- helper 656 0 0
-- helper 65 6 1
-- helper 6 6 1
-- helper 0 66 2