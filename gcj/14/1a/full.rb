def sz(u, v)
	$sz[u][v] ||= 1 + $g[v].map { |w| w != u ? sz(v, w) : 0 }.inject(:+)
end

def rec(u, v)
	$rec[u][v] ||= sz(u, v) - 1 + ($g[v].select { |w| w != u }.combination(2).map { |w, x| c(v, w) + c(v, x) }.min || 0)
end

def c(u, v)
	rec(u, v) - sz(u, v)
end

def solve
	n = gets.to_i
	$g = Array.new(n) { Array.new() }
	$sz = Array.new(n + 1) { Array.new(n) }
	$rec = Array.new(n + 1) { Array.new(n) }
	(n - 1).times do
		x, y = gets.split.map { |a| a.to_i - 1 }
		$g[x] << y
		$g[y] << x
	end
	(0 ... n).map { |i| rec(n, i) }.min
end

t = gets.to_i
t.times do |i|
	puts 'Case #%d: %d' % [i + 1, solve]
end
