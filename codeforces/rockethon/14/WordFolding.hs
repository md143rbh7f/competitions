best c ((x, a) : _ : xs) = if x == c then a else best c xs
best _ _ = 0

acc c ans = (c, 1 + best c ans) : ans

main = interact $ show . maximum . map snd . foldr acc []
