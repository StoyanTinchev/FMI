module Main (main) where

import Task1
import Task2
import Task3
import Task4
import Task5

main :: IO ()
main = do
  print $ removeFistOccurrence 110 1 == 10
  print $ removeFistOccurrence 15365 5 == 1536
  print $ removeFistOccurrence 15360 0 == 1536
  print $ removeFistOccurrence 15300 0 == 1530
  print $ removeFistOccurrence 15365 1 == 5365
  print $ removeFistOccurrence 35365 3 == 3565
  print $ removeFistOccurrence 1212 1 == 122
  print $ removeFistOccurrence 1212 2 == 121
  print $ removeFistOccurrence (removeFistOccurrence 1212 1) 1 == 22

  print "End of task 1"

  print $ sortN 1714 == 7411
  print $ sortN 123450 == 543210
  print $ sortN 123405 == 543210
  print $ sortN 123045 == 543210
  print $ sortN 120345 == 543210
  print $ sortN 102345 == 543210
  print $ sortN 8910 == 9810
  print $ sortN 321 == 321
  print $ sortN 29210 == 92210
  print $ sortN 1230 == 3210
  print $ sortN 55345 == 55543
  print $ sortN 14752 == 75421
  print $ sortN 329450 == 954320
  print $ sortN 9125 == 9521

  print "End of task 2"

  -- you may get slightly different results eg. -1.047619047619100 on test 4 <- not a problem
  print $ calcSeriesSum 1 0 == -2.0 -- x = 1, n = 0
  print $ calcSeriesSum 1 1 == -0.6666666666666667
  print $ calcSeriesSum 1 2 == -1.2000000000000002
  print $ calcSeriesSum 1 3 == -1.047619047619048
  print $ calcSeriesSum 1 4 == -1.0814814814814817
  print $ calcSeriesSum 1 5 == -1.0753246753246755
  print $ calcSeriesSum 1 6 == -1.0762718762718764
  print "End of task 3"

  print $ sumDivisibleNumbers 0 10 5 == 5
  print $ sumDivisibleNumbers 0 100 5 == 990
  print $ sumDivisibleNumbers 100 0 5 == 990

  print "End of task 4"

  print $ p 1 == 1
  print $ p 2 == 5
  print $ p 3 == 12
  print $ p 4 == 22
  print $ p 5 == 35
  print $ p 6 == 51

  print "End of task 5"
