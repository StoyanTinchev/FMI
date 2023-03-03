import Task1
import Task2

main :: IO ()
main = do
  print $ isEvenIf 1 == "No"
  print (isEvenGuards 1) 
  print (sumCubesPow 1 2)