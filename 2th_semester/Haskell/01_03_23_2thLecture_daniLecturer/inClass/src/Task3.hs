module Task3
  ( powRec,
    powIter,
  )
where

powRec :: Double -> Int -> Double
powRec _ 0 = error "0 is not allowed"
powRec x 1 = x
powRec x n = x * powRec x (n - 1)

powIter :: Double -> Int -> Double
powIter _ 0 = error "0 is not allowed"
powIter x 1 = x
powIter x n = helper n x
  where
    helper :: Int -> Double -> Double
    helper 1 res = res
    helper n res = helper (n - 1) (res * x)
