type Position = Int

type Direction = Int

controller :: String -> String
controller input = processEvents input 0 0 ""

processEvents :: String -> Position -> Direction -> String -> String
processEvents [] _ _ output = output
processEvents ('.' : xs) position direction output = processEvents xs (updatePosition position direction) direction (output ++ (show (updatePosition position direction)))
processEvents ('P' : xs) position direction output
  | (position == 5 && direction == 1) || (position == 0 && direction == -1) = processEvents xs position (-direction) (output ++ (show position))
  | otherwise = processEvents xs (updatePosition position newDirection) newDirection (output ++ (show (updatePosition position newDirection)))
  where
    newDirection = if direction == 0 then 1 else 0
processEvents ('O' : xs) position direction output = processEvents xs (updatePosition position newDirection) newDirection (output ++ (show (updatePosition position newDirection)))
  where
    newDirection = -direction

updatePosition :: Position -> Direction -> Position
updatePosition position direction
  | newPosition < 0 = 0
  | newPosition > 5 = 5
  | otherwise = newPosition
  where
    newPosition = position + direction

main :: IO ()
main = do
  print $ controller "" == ""
  print $ controller ".........." == "0000000000"
  print $ controller "P...." == "12345"
  print $ controller "P.P.." == "12222"
  print $ controller "..P...O..." == "0012343210"

  print $ controller "P......P......" -- == "12345554321000"
  print $ controller "P.P.P...." == "122234555"
  print $ controller ".....P.P........P...." == "000001222222222234555"
  print $ controller ".........." == "0000000000"
  print $ controller "P.." == "123"
  print $ controller "P...." == "12345"

  print $ controller "P......P......" -- == "12345554321000"
  print $ controller "P.P.." == "12222"
  print $ controller "P.P.P...." == "122234555"
  print $ controller ".....P.P........P...." == "000001222222222234555"

  print $ controller ".....P......P.P..P...." -- == "0000012345554333321000"
  print $ controller "P.O...." == "1210000"

  print $ controller "P......P.O...." -- ==  "12345554345555"
  print $ controller "P..OP..P.." -- ==  "1232222100"
  print $ controller "P......P..OP..P..." -- ==  "123455543233334555"
  print $ controller "..P...O....." == "001234321000"
