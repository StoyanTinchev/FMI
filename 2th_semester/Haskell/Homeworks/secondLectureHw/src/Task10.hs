module Task10
  ( countPalindromes,
  )
where

isPalindrome :: Int -> Bool
isPalindrome number = helper number 0
  where
    helper 0 newNum = newNum == number
    helper num newNum = helper (div num 10) (10 * newNum + mod num 10)

-- (end + 1) and (start + 1) as start of the range because first number of the range
-- is excluded
countPalindromes :: Int -> Int -> Int
-- make the below two lines as one line
--  | start > end = helper (end + 1) start 0
--  | otherwise = helper (start + 1) end 0
countPalindromes start end = helper (min start end + 1) (max start end) 0
    where
      helper s e count
        | s == e = count
        | isPalindrome s = helper (s + 1) e (count + 1)
        | otherwise = helper (s + 1) e count