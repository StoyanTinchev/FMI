module Task1
  ( isPalindrome,
  )
where

isPalindrome :: Int -> Bool
isPalindrome num = rev num == num

rev :: Int -> Int
rev currNum = helper currNum 0
  where
    helper 0 result = result
    helper leftover result = helper (div leftover 10) (10 * result + mod leftover 10)