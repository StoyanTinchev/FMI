module Task3
  ( sqAvg,
  )
where

sqAvg :: Int -> Int -> Double
sqAvg x y = fromIntegral (x * x + y * y) / 2
