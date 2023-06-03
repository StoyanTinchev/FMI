import Data.Char (intToDigit)

data Direction = Up | Down deriving (Eq, Show)

data State = Moving Direction Int | Paused Direction Int | Closed | Opened deriving (Eq, Show)

nextState :: State -> Char -> State
nextState Closed 'P' = Moving Up 1
nextState Closed _ = Closed
nextState (Moving Up pos) 'P' = Paused Up pos
nextState (Moving Up 5) _ = Opened
nextState (Moving Up pos) _ = Moving Up (pos + 1)
nextState (Paused Up pos) 'P' = Moving Up pos
nextState (Paused Up pos) _ = Paused Up pos
nextState Opened 'P' = Moving Down 4
nextState Opened _ = Opened
nextState (Moving Down pos) 'P' = Paused Down pos
nextState (Moving Down 0) _ = Closed
nextState (Moving Down pos) _ = Moving Down (pos - 1)
nextState (Paused Down pos) 'P' = Moving Down pos
nextState (Paused Down pos) _ = Paused Down pos
nextState (Moving Up pos) 'O' = Moving Down (pos - 1)
nextState (Moving Down pos) 'O' = Moving Up (pos + 1)
nextState (Paused Down pos) 'O' = Moving Up (pos + 1)
nextState (Paused Up pos) 'O' = Moving Down (pos - 1)

statePosition :: State -> Char
statePosition Closed = '0'
statePosition Opened = '5'
statePosition (Moving Up pos) = intToDigit pos
statePosition (Moving Down pos) = intToDigit pos
statePosition (Paused Up pos) = intToDigit pos
statePosition (Paused Down pos) = intToDigit pos

controller :: String -> String
controller = map statePosition . tail . scanl nextState Closed

main :: IO ()
main = do
  print $ controller "" == ""
  print $ controller ".........." == "0000000000"
  print $ controller "P...." == "12345"
  print $ controller "P.P.." == "12222"

  print $ controller "..P...O..." -- == (right output: "0012343210") -- (error output: "0012345555")
  print $ controller "P......P......" == "12345554321000"

  print $ controller "P.P.P...." -- == (right output: "122234555") -- (error output: "122223455")
  print $ controller ".....P.P........P...." -- == (right output: "000001222222222234555") -- (error output: "000001222222222223455")
  print $ controller ".........." == "0000000000"
  print $ controller "P.." == "123"
  print $ controller "P...." == "12345"
  print $ controller "P......P......" == "12345554321000"
  print $ controller "P.P.." == "12222"

  print $ controller "P.P.P...." -- == (right output: "122234555") -- (error output: "122223455")
  print $ controller ".....P.P........P...." -- == (right output: "000001222222222234555") -- (error output: "000001222222222223455")
  print $ controller ".....P......P.P..P...." -- == (right output: "0000012345554333321000") -- (error output: "0000012345554333332100")
  print $ controller "P.O...." -- == (right output: "1210000") -- (error output: "1234555")
  print $ controller "P......P.O...." -- == (right output: "12345554345555") -- (error output: "12345554321000")
  print $ controller "P..OP..P.." -- == (right output: "1232222100") -- (error output: "1234444455")
  print $ controller "P......P..OP..P..." -- == (right output: "123455543233334555") -- (error output: "123455543211111000")
  print $ controller "..P...O....." -- == (right output: "001234321000") -- (error output: "001234555555")
