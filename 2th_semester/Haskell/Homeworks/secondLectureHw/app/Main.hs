module Main (main) where

import Task1
import Task2
import Task3
import Task4
import Task5
import Task6
import Task7
import Task8
import Task9
import Task10
import Task11
import Task12

main :: IO ()
main = do
--  print $ countDigitsIter (-13) -- error "n was negative"
  print $ countDigitsIter 12345 == 5
  print $ countDigitsIter 123 == 3

  --print $ countDigitsRec (-13) -- error "n was negative"
  print $ countDigitsRec 12345 == 5
  print $ countDigitsRec 123 == 3

  print "End of task 1"


  -- print $ sumDigitsIter (-13) -- error "n was negative"
  print $ sumDigitsIter 12345 == 15
  print $ sumDigitsIter 123 == 6
--
  print "End of task 2"


  print $ sumPrimeDivs 0 == 0
  print $ sumPrimeDivs 6 == 5 -- 2 + 3
  print $ sumPrimeDivs 18 == 5 -- 2 + 3
  print $ sumPrimeDivs 19 == 19
  print $ sumPrimeDivs 45136 == 53

  print "End of task 3"
  
  
  print $ countOccurences 121 1 == 2
  print $ countOccurences 222 1 == 0
  
  print "End of task 4"
  
  
  print $ areAmicable 200 300 == False
  print $ areAmicable 220 284 == True
  print $ areAmicable 284 220 == True
  print $ areAmicable 1184 1210 == True
  print $ areAmicable 2620 2924 == True
  print $ areAmicable 6232 6368 == True
  
  print "End of task 5"
  

  print $ isInteresting 410 == True
  print $ isInteresting 212 == False
  print $ isInteresting 567 == False
  print $ isInteresting 70 == True 
  print $ isInteresting 5 == True 
  print $ isInteresting 4 == True 
  
  print "End of task 6"
  
  
  print $ maxMultiple 2 7 == 6
  print $ maxMultiple 3 10 == 9
  print $ maxMultiple 7 17 == 14
  print $ maxMultiple 10 50 == 50
  print $ maxMultiple 37 200 == 185
  print $ maxMultiple 7 100 == 98  
  print $ maxMultiple 7 10 == 7
  print $ maxMultiple 4 4 == 4
  
  print "End of task 7"


  print $ removeD 1 656 == 656
  print $ removeD 5 656 == 66
  print $ removeD 6 656 == 5
  print $ removeD 0 606 == 66
  print $ removeD 0 600 == 6
  print $ removeD 6 600 == 0
  print $ removeD 2 1234 == 134

  print "End of task 8"
  
  
  print $ everyOther 12 == 1
  print $ everyOther 852369 == 628
  print $ everyOther 1714 == 11
  print $ everyOther 12345 == 42
  print $ everyOther 891 == 9
  print $ everyOther 123 == 2
  print $ everyOther 2121 == 22
  print $ everyOther 4736778 == 767
  print $ everyOther 448575 == 784
  print $ everyOther 4214 == 14
  
  print "End of task 9"
  
  
  print $ countPalindromes 5 13 == 5 -- 6 7 8 9 11
  print $ countPalindromes 13 5 == 5 -- 6 7 8 9 11
  
  print "End of task 10"
  
  
  print $ truncatablePrime 3797 == True -- 3797, 379, 37 and 3 are all prime
  print $ truncatablePrime 47 == False -- 47 is prime, but 4 is not
  
  print "End of task 11"
  
  
  print $ findSum 0 2 10 == 3578 -- 510 + 1022 + 2046
  print $ findSum 5 3 5 == 174 -- 26 + 50 + 98
  
  print "End of task 12"