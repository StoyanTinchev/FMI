-- Дадени са numBottles бутилки за вода, които първоначално са пълни.
-- Всеки numExchange празни бутилки могат да бъдат заменени с една пълна бутилка.
-- Ако пълна бутилка бъде изпита, тя става празна.
-- Да се дефинира функция numDrink :: Int -> Int -> Int, която приема две естествени
-- числа numBottles и numExchange и намира максималния брой бутилки вода, които могат
-- да бъдат изпити. Да се реализира линеен рекурсивен процес!
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
