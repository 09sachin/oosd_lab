--Name : Sachin 18NA30015
sum_cube ::  Int -> [(Int , Int)] -- function that return list tuple of two possible integers whose sum of cubes is the number given
sum_cube n =  [(a,b) | a <- [1..n], b <- [1..n], a*a*a + b*b*b == n] -- check all possible cases taking numbers for two different lists running from 1 to n continousaly

main = do 
    print $ sum_cube 9 -- call function
