solve [ n, m, a ] = ceiling( n / a ) * ceiling( m / a )
main = interact $ show . solve . map read . words
