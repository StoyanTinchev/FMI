module Main (main) where

import Task1
import Task2
import Task3
import Task4
import Task5
import Task6

main = do
  print $ mySumRecNonPM [] == 0
  print $ mySumRecNonPM [1, 2, 3] == 6

  print $ mySumRecPM [] == 0
  print $ mySumRecPM [1, 2, 3] == 6

  print $ mySumFunc [] == 0
  print $ mySumFunc [1, 2, 3] == 6

  print "End of task 1"

  print $ isPresentRecNonPM 0 [] == False
  print $ isPresentRecNonPM 0 [1, 2, 3] == False
  print $ isPresentRecNonPM 0 [0, -1, 2] == True

  print $ isPresentRecPM 0 [] == False
  print $ isPresentRecPM 0 [1, 2, 3] == False
  print $ isPresentRecPM 0 [0, -1, 2] == True

  print $ isPresentFunc 0 [] == False
  print $ isPresentFunc 0 [1, 2, 3] == False
  print $ isPresentFunc 0 [0, -1, 2] == True

  print "End of task 2"

  print $ primesInRangeLC 1 100 -- == []
  print $ primesInRangeLC 998 1042 == [1009, 1013, 1019, 1021, 1031, 1033, 1039]
  print $ primesInRangeLC 120 666 == [127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661]
  print $ primesInRangeLC 420 240 == [241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419]
  print $ primesInRangeHOF 1 100 == []
  print $ primesInRangeHOF 998 1042 == [1009, 1013, 1019, 1021, 1031, 1033, 1039]
  print $ primesInRangeHOF 120 666 == [127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661]
  print $ primesInRangeHOF 420 240 == [241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419]

  print "End of task 3"

  print $ sumUnevenLC 5 50 == 621
  print $ sumUnevenLC 50 1 == 625
  print $ sumUnevenLC 564 565 == 565

  print $ sumUnevenHOF 5 50 == 621
  print $ sumUnevenHOF 50 1 == 625
  print $ sumUnevenHOF 564 565 == 565

  print "End of task 4"

  print $ isAscending 0 == True
  print $ isAscending 10 == False
  print $ isAscending 123 == True
  print $ isAscending 1233 == True
  print $ isAscending 12332 == False

  print "End of task 5"

  print $ sumSpecialPrimes 5 2 == 392 -- n = 5, d = 2
  print $ sumSpecialPrimes 5 3 == 107
  print $ sumSpecialPrimes 10 3 == 462

  print "End of task 6"
