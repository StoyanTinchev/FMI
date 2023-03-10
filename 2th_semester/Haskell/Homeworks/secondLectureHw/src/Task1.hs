module Task1
  ( countDigitsIter,
    countDigitsRec,
  )
where

countDigitsIter :: Int -> Int
countDigitsIter num = helper num 0
  where
    helper 0 count = count
    helper curr count = helper (div curr 10) (count + 1)

countDigitsRec :: Int -> Int
countDigitsRec num
  | num < 0 = error "n was negative"
  | otherwise = helper num 0
  where
    helper 0 count = count
    helper curr count = helper (div curr 10) (count + 1)
