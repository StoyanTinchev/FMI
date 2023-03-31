module Task7
  ( maxMultiple,
  )
where

maxMultiple :: Int -> Int -> Int
maxMultiple divisor bound
  | divisor < 1 = error "Divisor must be greater than 0"
  | bound < divisor = error "Bound must be greater than divisor"
  | otherwise = helper bound
  where
    helper num
      | mod num divisor == 0 = num
      | otherwise = helper $ num - 1
