module Task3 (calcSeriesSum) where

-- Define a function that accepts two real numbers and calculates the n-th partial sum from the following sequence:
calcSeriesSum :: Double -> Int -> Double
calcSeriesSum x n = helper 1 1
  where
    helper :: Int -> Int -> Double
    helper count prevDivider
      | count > n =
          ((-1)^count * 2^count * x^(count - 1))
            / fromIntegral (prevDivider * (2 * count - 1))
      | otherwise =
          ((-1)^count * (2^count * x^(count - 1)))
            / fromIntegral (prevDivider * (2 * count - 1))
            + helper (count + 1) (prevDivider * (2 * count - 1))

-- print $
--    ((-1)^1 * 2^1 * 1^0) / (1 * (2 * 1 - 1)) -- = -2
--  + ((-1)^2 * 2^2 * 1^1) / (1 * (2 * 2 - 1)) -- = 1.3333333333333333
--  + ((-1)^3 * 2^3 * 1^2) / (3 * (2 * 3 - 1)) -- = -0.5333333333333333
