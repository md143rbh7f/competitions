solve [n, m, k] = if n + m - 2 < k then -1 else max (get l) (get r) where
	get a = (n `div` (a + 1)) * (m `div` (k - a + 1))
	l = max 0 (k + 1 - m)
	r = min k (n - 1)
main = interact $ show . solve . map read . words
