module Task6
  ( canCarry,
  )
where
  
canCarry :: Double -> Double -> Double -> String
canCarry c k w 
--  | [x | x <- [c, k, w], x < 0] /= [] = error "Error negative number given"
  | c < 0 = error "The number of products was negative"
  | k < 0 = error "John's hosting capacity was negative"
  | w < 0 = error "The weight of a product was negative"
  | c * w <= k = "Yes"
  | otherwise = "No"
