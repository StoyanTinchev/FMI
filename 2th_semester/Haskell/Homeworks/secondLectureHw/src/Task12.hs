module Task12
  ( findSum,
  )
where

findSum :: Int -> Int -> Int -> Int
findSum a b n = helper 0 a 0
  where
    helper count sum res
      | count > n = res
      | count > (n - 3) && count <= n = helper (count + 1) (sum + 2 ^ count * b) (res + sum)
      | otherwise = helper (count + 1) (sum + 2 ^ count * b) 0
