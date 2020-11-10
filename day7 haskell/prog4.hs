quicksort ::  [Int] -> [Int]  --Quicksort function declaration from int list to int list
quicksort [] = []  -- for empty list case
quicksort (x:xs) = quicksort small ++ (x : quicksort large) -- final sorted list 
   where small = [y | y <- xs, y <= x] --smaller sorted list than pivot
         large = [y | y <- xs, y > x] -- larger sorted list than pivot

main = do 
    print $ quicksort[7,6,5,4,3,2,1] -- caling quicksort