module Task7
  ( growingPlant,
  )
where

growingPlant :: Int -> Int -> Int -> Int
growingPlant upSpeed downSpeed desiredHeight = helper 0 0 True
  where
    helper :: Int -> Int -> Bool -> Int
    helper currentHeight days isDay
      | currentHeight >= desiredHeight = days
      | isDay = helper (currentHeight + upSpeed) (days + 1) False
      | otherwise = helper (currentHeight - downSpeed) days True
      