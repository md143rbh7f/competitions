object Dijkstra extends App {
	val I = 2
	val J = 3
	val K = 4

	val _mulQ = Array(
		Array(0,  0,  0,  0,  0),
		Array(0,  1,  I,  J,  K),
		Array(0,  I, -1,  K, -J),
		Array(0,  J, -K, -1,  I),
		Array(0,  K,  J, -I, -1)
	)

	def mulQ (x : Int, y : Int) : Int = {
		if (x < 0) -mulQ(-x, y) else if (y < 0) -mulQ(x, -y) else _mulQ(x)(y)
	}

	def toQ (c : Char) : Int = {
		if (c == 'i') I else if (c == 'j') J else K
	}

	def product (l : Int, m : Long, xs : IndexedSeq[Int]) : Int = {
		var p = 1
		for (i <- 0 to l - 1) {
			p = mulQ(p, xs(i))
		}
		var q = 1
		for (i <- 0 to (m % 4).toInt - 1) {
			q = mulQ(q, p)
		}
		q
	}

	def lo (l : Int, m : Long, xs : IndexedSeq[Int]) : Int = {
		var p = 1
		for (i <- 0 to (l * math.min(m, 4l)).toInt - 1) {
			p = mulQ(p, xs(i % l))
			if (p == I) {
				return i + 1
			}
		}
		-1
	}

	def hi (l : Int, m : Long, xs : IndexedSeq[Int]) : Int = {
		var p = 1
		for (i <- 0 to (l * math.min(m, 4l)).toInt - 1) {
			p = mulQ(xs(l - 1 - (i % l)), p)
			if (p == K) {
				return i + 1
			}
		}
		-1
	}

	def work () : Boolean = {
		val lm = io.StdIn.readLine.split(" ");
		val l = lm(0).toInt
		val m = lm(1).toLong
		val xs = io.StdIn.readLine.map(toQ)
		if (product(l, m, xs) != -1) {
			return false
		}
		val a = lo(l, m, xs)
		val b = hi(l, m, xs)
		a != -1 && b != -1 && a + b < m * l
	}

	val t = io.StdIn.readInt
	for (i <- 1 to t) {
		println("Case #" + i + ": " + (if (work) "YES" else "NO"))
	}
}
