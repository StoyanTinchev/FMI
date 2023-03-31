module Task1
  ( countDigitsIter,
    countDigitsRec,
  )
where

countDigitsIter :: Int -> Int
countDigitsIter num
  | num < 0 = error "n was negative"
  | otherwise = helper num 0
  where
    helper 0 count = count
    helper curr count = helper (div curr 10) (count + 1)

-- countDigitsRec with linear recursion
countDigitsRec :: Int -> Int
countDigitsRec num
  | num < 0 = error "n was negative"
  | div num 10 == 0 = 1
  | otherwise = 1 + countDigitsRec (div num 10)
