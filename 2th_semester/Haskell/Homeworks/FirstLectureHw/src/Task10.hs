module Task10
  ( finalGrade,
  )
where

finalGrade :: Double -> Double -> Double -> Double -> Double -> Double -> Double -> Double -> Double -> Double
finalGrade d1 d2 d3 kz1 kz2 kt1 kt2 iz it =
  roundTwoDig $
    (1 / 2)
      * ( (1 / 4) * ((d1 + d2 + d3) / 3)
            + (3 / 8) * ((kt1 + kt2) / 2)
            + (3 / 8) * ((kz1 + kz2) / 2)
        )
      + (1 / 4)
      * it
      + (1 / 4)
      * iz

roundTwoDig :: Double -> Double
roundTwoDig n
  | (fromIntegral $ round $ n * 100) / 100 < 2 = 2
  | otherwise = (fromIntegral $ round $ n * 100) / 100
