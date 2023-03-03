module Main (main) where

import Task1
import Task2
import Task3
import Task4
import Task5
import Task6
import Task7

main :: IO ()
main = do
  print $ isPalindrome 1 == True
  print $ isPalindrome 6 == True
  print $ isPalindrome 1010 == False
  print $ isPalindrome 505 == True
  print $ isPalindrome 123321 == True
  print $ isPalindrome 654 == False
  print $ isPalindrome 121 == True
  print $ isPalindrome 12 == False
  print $ isPalindrome 120 == False
  print $ isPalindrome 12321 == True
  print $ isPalindrome 1221 == True
  
  print "End of task 1"
  
  
  print $ sumDigitsRec 12345 == 15
  print $ sumDigitsRec 123 == 6
  
  print "End of task 2"
  
  
  print $ powRec 2 5 == 32
  print $ powRec 15 3 == 3375
  
  print $ powIter 2 5 == 32
  print $ powIter 15 3 == 3375
  
  --print $ powRec 2 0 == 1 -- should return an error (according to the task description)
  print "End of task 3"
  
  
  print $ isPrime 1 == False
  print $ isPrime 2 == True
  print $ isPrime 3 == True
  print $ isPrime 6 == False
  print $ isPrime 61 == True
  
  print "End of task 4"
  
  
  print $ sumDivs 0 == 0
  print $ sumDivs 1 == 1
  print $ sumDivs 6 == 12 -- 1 + 2 + 3 + 6
  print $ sumDivs 12345 == 19776

  print "End of task 5"


  print $ isPerfect 1 == False -- the sum of the divisors is 0, because of the hint
  print $ isPerfect 6 == True -- 1 + 2 + 3 = 6 = 6
  print $ isPerfect 495 == False
  print $ isPerfect 33550336 == True
  
  print "End of task 6"
  
  
  print $ hasIncDigits 1244 == True
  print $ hasIncDigits 12443 == False
  
  print "End of task 7"