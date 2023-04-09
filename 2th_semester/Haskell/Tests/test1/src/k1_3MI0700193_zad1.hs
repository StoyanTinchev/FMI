numDrink :: Int -> Int -> Int
numDrink numBottles numExchange
  | numBottles < 0 = error "numBottles must be >= 0"
  | numExchange <= 0 = error "numExchange must be > 0"
  | otherwise = numDrink' numBottles 0
  where
    numDrink' :: Int -> Int -> Int
    numDrink' nBottles numDrinks
      | nBottles < numExchange = numDrinks + nBottles
      | otherwise = numDrink' (nBottles - numExchange + 1) (numDrinks + numExchange)

main :: IO ()
main = do
  print $ numDrink 9 3 -- 13
  print $ numDrink 15 4 -- 19
  print $ numDrink 761 3 -- 1141
