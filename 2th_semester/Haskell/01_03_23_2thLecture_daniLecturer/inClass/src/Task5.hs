module Task5
  ( sumDivs,
  )
where

sumDivs :: Int -> Int
sumDivs number = helper 1 
  where
    helper :: Int -> Int
    helper currNum
      | currNum > number = 0
      | mod number currNum == 0 = currNum + helper (currNum + 1)
      | otherwise = helper (currNum + 1)