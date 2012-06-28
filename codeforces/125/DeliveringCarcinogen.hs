eps = 1e-9
tMax = 1e13
tau = 2 * pi

hypot a b = sqrt ( a^2 + b^2 )
fix q = q - tau * ( fromIntegral $ floor $ q / tau )

solve [xp0,yp0,vp,x,y,v,rs] = let
	r = hypot x y
	q = atan2 y x
	rp = hypot xp0 yp0
	qp0 = atan2 yp0 xp0
	wp = vp / rp
	arc = pi - asin ( rs / r ) - asin ( rs / rp )
	tans = sqrt ( r^2 - rs^2 ) + sqrt ( rp^2 - rs^2 )
	search a b = if b - a < eps then a else let
		t = ( a + b ) / 2
		qp = fix ( qp0 + wp * t )
		xp = rp * cos qp
		yp = rp * sin qp
		dq = min ( fix $ qp - q ) ( fix $ q - qp )
		dist = if dq <= arc then hypot ( xp - x ) ( yp - y ) else tans + ( dq - arc ) * rs
		in if dist <= t * v then search a t else search t b
	in search 0 tMax

main = interact $ show . solve . map read . words
