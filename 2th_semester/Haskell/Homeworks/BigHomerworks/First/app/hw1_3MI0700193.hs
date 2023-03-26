--  First task
eqSumPowDig :: Int -> Int -> Int
eqSumPowDig hMax power
  | hMax < 1 || power < 1 = error "Invalid arguments: Both hMax and power must be greater than 0"
  | otherwise = helper 2 0 0
  where
    helper iter currSum res
      | iter > hMax = res
      | iter == currSum = helper (iter + 1) (digitsSum $ iter + 1) (res + currSum)
      | otherwise = helper (iter + 1) (digitsSum $ iter + 1) res
      where
        digitsSum num
          | num < 0 = error "num was negative"
          | otherwise = helper num 0
          where
            helper 0 sum = sum
            helper curr sum = helper (div curr 10) (sum + mod curr 10 ^ power)

-- |
-- The following function, eqSumPowDig, is commented out because its usage
-- might not be allowed in this context. If allowed, this function computes
-- the sum of all numbers up to 'n' that satisfy the condition where the sum
-- of their digits raised to the power 'p' equals the number itself.

-- eqSumPowDig :: Int -> Int -> Int
-- eqSumPowDig n p = sum [x | x <- [2 .. n], sum (map (^ p) (digits x)) == x]
--  where
--    digits :: Int -> [Int]
--    digits 0 = []
--    digits x = digits (x `div` 10) ++ [x `mod` 10]

--  Second task
--  My logic explanation:

-- |
--  The function is based on the observation that every positive integer has
--  a unique binary representation. It generates the nth seven-like number by
--  interpreting the binary representation of the input number as a sum of unique powers of 7.
--
--  Here's a step-by-step explanation of how the function works:
--
--  1. The function takes an integer 'num' as input and initializes the helper
--     function with 'num', a power of 0, and a sum of 0.
--
--  2. The base case of the helper function is when 'shiftR' becomes 0. At this point,
--     the function returns the accumulated sum.
--
--  3. If 'shiftR' is odd (i.e., mod shiftR 2 == 1), it means that the current power of 7
--     should be included in the sum. So, the helper function is called
--     recursively with (div shiftR 2), (power + 1), and (sum + 7 ^ power).
--
--  4. If 'shiftR' is even (i.e., mod shiftR 2 == 0), it means that the current power of 7
--     should not be included in the sum. So, the helper function is called
--     recursively with (div shiftR 2), (power + 1), and sum.
--
--  As the helper function proceeds, it effectively checks each bit of the binary
--  representation of 'num'. If the bit is set (1), it adds the corresponding power
--  of 7 to the sum. If the bit is not set (0), it skips the corresponding power
--  of 7. This way, the function constructs the nth seven-like number by summing
--  up unique powers of 7 according to the binary representation of 'num'.
getNthSevenlikeNum :: Int -> Int
getNthSevenlikeNum num
  | num <= 0 = error "Invalid argument: the provided number must be a positive integer"
  | otherwise = helper num 0 0
  where
    helper 0 _ sum = sum
    helper shiftR power sum
      | mod shiftR 2 == 1 = helper (div shiftR 2) (power + 1) (sum + 7 ^ power)
      | otherwise = helper (div shiftR 2) (power + 1) sum

main :: IO ()
main = do
  print "Task 1:"
  print $ eqSumPowDig 100 2 -- == 0
  print $ eqSumPowDig 1000 2 -- == 0
  print $ eqSumPowDig 2000 2 -- == 0
  print $ eqSumPowDig 200 3 -- == 153
  print $ eqSumPowDig 370 3 -- == 523
  print $ eqSumPowDig 370 3 -- == 523
  print $ eqSumPowDig 400 3 -- == 894
  print $ eqSumPowDig 500 3 -- == 1301
  print $ eqSumPowDig 1000 3 -- == 1301
  print $ eqSumPowDig 1500 3 -- == 1301
  print "Task 2:"
  print $ getNthSevenlikeNum 1 -- == 1
  print $ getNthSevenlikeNum 2 -- == 7
  print $ getNthSevenlikeNum 3 -- == 8 -- not unique
  print $ getNthSevenlikeNum 4 -- == 49
  print $ getNthSevenlikeNum 5 -- == 50 -- not unique
  print $ getNthSevenlikeNum 6 -- == 56 -- not unique
  print $ getNthSevenlikeNum 7 -- == 57 -- not unique
  print $ getNthSevenlikeNum 8 -- == 343
  print $ getNthSevenlikeNum 9 -- == 344 -- not unique
  print $ getNthSevenlikeNum 10 -- == 350 -- not unique
