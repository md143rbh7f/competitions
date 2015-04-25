I, J, K = 2, 3, 4

MUL_Q = [
	[0,  0,  0,  0,  0],
	[0,  1,  I,  J,  K],
	[0,  I, -1,  K, -J],
	[0,  J, -K, -1,  I],
	[0,  K,  J, -I, -1],
]

def mul_q(x, y)
	x < 0 ? -mul_q(-x, y) : y < 0 ? -mul_q(x, -y) : MUL_Q[x][y]
end

def product(l, m, xs)
	p, q = 1, 1
	l.times do |i|
		p = mul_q(p, xs[i])
	end
	(m % 4).times do |i|
		q = mul_q(q, p)
	end
	q
end

def lo(l, m, xs)
	n, p = l * [m, 4].min, 1
	n.times do |i|
		p = mul_q(p, xs[i % l])
		if p == I
			return i + 1
		end
	end
	-1
end

def hi(l, m, xs)
	n, p = l * [m, 4].min, 1
	n.times do |i|
		p = mul_q(xs[l - 1 - (i % l)], p)
		if p == K
			return i + 1
		end
	end
	-1
end

def solve
	l, m = gets.split.map { |x| x.to_i }
	xs = gets.rstrip.chars.map { |x| x == 'i' ? I : x == 'j' ? J : K }
	if product(l, m, xs) != -1
		return false
	end
	a, b = lo(l, m, xs), hi(l, m, xs)
	a != -1 && b != -1 && a + b < m * l
end

gets.to_i.times do |i|
	puts 'Case #%d: %s' % [i + 1, solve ? 'YES' : 'NO']
end
