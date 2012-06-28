dist ( [x0,y0], [x1,y1] ) = sqrt ( ( x1 - x0 )^2 + ( y1 - y0 )^2 )
angle (a,b,c) = acos ( ( c^2 + b^2 - a^2 ) / 2 / b / c )
isInteger x = abs ( x - fromIntegral ( round x ) ) <= 1e-5

solve [p0,p1,p2] = let
	[a,b,c] = map dist [ (p0,p1), (p1,p2), (p2,p0) ]
	[x,y,z] = map angle [ (a,b,c), (b,c,a), (c,a,b) ]
	r = a / 2 / sin x
	ok a = all isInteger $ map (/a) [x,y,z]
	q = 2 * ( head $ filter ok $ map (pi/) [3..100] )
	in r^2 * sin q * pi / q

main = interact $ show . solve . map ( map read . words ) . lines
