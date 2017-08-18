pows n p q = if q <= n then pows n p ( p * q ) . ( q : ) else id
rec n (q:qs) = a * ( q - m - 1 ) + ( a + 1 ) * ( rec m qs ) where ( a, m ) = divMod n q
rec _ _ = 0
run [n, p] = rec n $ pows n p 1 []
main = interact $ unlines . map ( show . run . map read . words ) . tail . lines
