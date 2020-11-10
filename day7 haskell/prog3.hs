quicksort [] = []  --quicksort
quicksort (p:xs) = (quicksort lesser) ++ [p] ++ (quicksort greater)
    where
        lesser = filter (< p) xs -- filter for lesser values than pivot
        greater = filter (>= p) xs -- fiter for larger values than pivot

main = do
    print $ quicksort [9,8,7,6,5,4,3] --calling quicksort