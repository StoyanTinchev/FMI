module Task8
  ( snail,
  )
where

snail :: Int -> Int -> Int -> Int
snail colHeight distanceCrawled distanceSlidedDown = helper 0 0 True
  where 
    helper :: Int -> Int -> Bool -> Int
    helper currHeight days isDay
      | currHeight >= colHeight = days
      | isDay = helper (currHeight + distanceCrawled) (days + 1) False
      | otherwise = helper (currHeight - distanceSlidedDown) days True
      