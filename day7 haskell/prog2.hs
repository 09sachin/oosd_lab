-- function to removes inner brackets
remove_bracket :: [[Int]] -> [Int] -- take list of list as input and give list as output
remove_bracket t =  [y | x <- t, y <- x] --Using list comprehension


main = do
    print $ remove_bracket[[1,2],[2,4],[4,1]] --print new list