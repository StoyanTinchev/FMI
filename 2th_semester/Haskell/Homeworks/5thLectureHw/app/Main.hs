module Main (main) where

import Task1
import Task2
import Task3
import Task4
import Task5

main = do
  print $ getPrimesLC 1 100 == [7, 17, 37, 47, 67, 71, 73, 79, 97]
  print $ getPrimesLC 100 1 == [7, 17, 37, 47, 67, 71, 73, 79, 97]

  print $ getPrimesHOF 1 100 == [7, 17, 37, 47, 67, 71, 73, 79, 97]
  print $ getPrimesHOF 100 1 == [7, 17, 37, 47, 67, 71, 73, 79, 97]

  print "End of task 1"

  print $ getPalindromes 132465 == 8
  print $ getPalindromes 654546 == 8
  print $ getPalindromes 100001 == 100012
  print $ getPalindromes 21612 == 21614
  print $ getPalindromes 26362 == 26364

  print "End of task 2"

  print $ isArithmentic [3] == True
  print $ isArithmentic [3, 5] == True
  print $ isArithmentic [1, 2, 3, 4, 5] == True
  print $ isArithmentic [3, 5, 7, 9, 11] == True
  print $ isArithmentic [3, 5, 8, 9, 11] == False

  print "End of task 3"

  print $ specialSum 1 100 == 195 -- 61, 65, 69
  print "End of task 4"

  print $ (applyN (\x -> 2 * x) 5) 2 == 64
  print $ (applyN (\x -> div x 10) 2) 100 == 1

  print "End of task 5"
