module Task3
  ( sqAvg,
  )
where
  
sqAvg :: Integer -> Integer -> Double
sqAvg a b = fromIntegral (a * a + b * b) / 2
