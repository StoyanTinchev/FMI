module Main (main) where

import Task1
import Task10
import Task2
import Task3
import Task4
import Task5
import Task6
import Task7
import Task8
import Task9

main :: IO ()
main = do
  print $ isEvenIf 2 == "Yes"
  print $ isEvenIf 15452 == "Yes"
  print $ isEvenIf 321 == "No"

  print $ isEvenGuards 2 == "Yes"
  print $ isEvenGuards 15452 == "Yes"
  print $ isEvenGuards 321 == "No"

  print "End of task 1"
  --
  --
  print $ sumCubesPow 5 1 == 126
  print $ sumCubesPow 10 50 == 126000

  print $ sumCubesNoPow 5 1 == 126
  print $ sumCubesNoPow 10 50 == 126000

  print "End of task 2"
  --
  --
  print $ sqAvg 5 0 == 12.5
  print $ sqAvg 10 13 == 134.5

  print "End of task 3"
  --
  --
  print $ myGcdG 5 13 == 1
  print $ myGcdG 13 1235 == 13

  print $ myGcdPM 5 13 == 1
  print $ myGcdPM 13 1235 == 13

  print "End of task 4"
  --
  --

  print $ isLeapYearOneLine 2020 == True
  print $ isLeapYearOneLine 1988 == True
  print $ isLeapYearOneLine 1600 == True
  print $ isLeapYearOneLine 2400 == True
  print $ isLeapYearOneLine 2023 == False
  print $ isLeapYearOneLine 1700 == False
  print $ isLeapYearOneLine 1800 == False
  print $ isLeapYearOneLine 2100 == False

  print $ isLeapYearGuards 2020 == True
  print $ isLeapYearGuards 1988 == True
  print $ isLeapYearGuards 1600 == True
  print $ isLeapYearGuards 2400 == True
  print $ isLeapYearGuards 2023 == False
  print $ isLeapYearGuards 1700 == False
  print $ isLeapYearGuards 1800 == False
  print $ isLeapYearGuards 2100 == False

  print "End of task 5"
  --
  --
  print $ canCarry 5 15 3 == "Yes"
  print $ canCarry 1 5 4 == "Yes"
  print $ canCarry 13 25 2 == "No"
  print $ canCarry 24 104.44 21.12 == "No"
  print $ canCarry 51 34.75 19.852 == "No"
  print $ canCarry 42 95.11 0.51 == "Yes"

  --  print $ canCarry (-13) 25 2 -- error: The number of products was negative
  --  print $ canCarry 13 (-25) 2 -- error: John's hosting capacity was negative
  --  print $ canCarry 13 25 (-2) -- error: The weight of a product was negative
  print "End of task 6"

  print $ growingPlant 5 2 5 == 1
  print $ growingPlant 5 2 6 == 2
  print $ growingPlant 10 9 4 == 1
  print $ growingPlant 100 10 910 == 10 -- upSpeed=100, downSpeed=10, desiredHeight=910
  print "End of task 7"

  print $ snail 3 2 1 == 2
  print $ snail 10 3 1 == 5
  print $ snail 10 3 2 == 8
  print $ snail 100 20 5 == 7
  print $ snail 5 10 3 == 1

  print "End of task 8"

  print $ rev 1 == 1
  print $ rev 123 == 321
  print $ rev 987654321 == 123456789

  print "End of taks 9"

  print $ finalGrade 3 4 4 4.25 4.50 3.75 4.25 5 4.25 == 4.34
  print $ finalGrade 6 6 6 4.50 5 4.50 4.75 5 4.75 == 4.95
  print $ finalGrade 6 0 4 6 6 5 4.75 6 4.75 == 5.14
  print $ finalGrade 4.25 0 3 2 0 0 0 0 0 == 2
  print $ finalGrade 5.50 6 6 6 5.50 5.25 4 5.50 4 == 5.05
  print $ finalGrade 6 6 6 5.50 5.50 4 5 5.50 5 == 5.25
  print $ finalGrade 6 6 6 5.25 6 4 4 5.63 3.50 == 4.84

  print "End of task 10"
