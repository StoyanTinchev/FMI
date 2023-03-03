module Task7
  ( hasIncDigits,
  )
where

hasIncDigits :: Integer -> Bool
hasIncDigits 0 = True
--hasIncDigits num = hasIncDigits (div num 10) && mod num 10 >= mod (div num 10) 10
hasIncDigits num = (hasIncDigits $ div num 10) && mod num 10 >= mod (div num 10) 10 -- the better way