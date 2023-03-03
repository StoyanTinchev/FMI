module Task3
  ( sqAvg,
  )
where
  
sqAvg :: Integer -> Integer -> Double
sqAvg a b = fromIntegral (sum [x * x | x <- [a, b]]) / 2
