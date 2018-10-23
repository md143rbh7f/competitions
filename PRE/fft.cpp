/*
 * The Fourier transform is, roughly speaking, a change-of-basis operation that
 * takes a function represented in the standard basis and returns a function
 * represented using the basis of periodic functions.
 *
 * The discrete case is useful for programming competitions because the basis
 * of periodic vectors is generated by the powers of the N-th roots of unity
 * (or a similar enough field). If we interpret a vector as a list of
 * polynomial coefficients, then the Fourier transform is equivalent to a list
 * of the polynomial's values on the roots of unity. Using this representation,
 * we can  trivially multiply two large polynomials in linear time.
 *
 * Furthermore, we can optimise the forward and inverse Fourier transforms on
 * vectors of length N = 2^K to run in O(N log N) time. I shall skip the proof
 * because it is pretty well known.
 *
 * The following code is largely based on e-maxx's article.
 *
 * Quick usage notes and gotchas:
 *
 *   * Obviously your vector needs to be of length 2^K for some K.
 *
 *   * This code works for most integer polynomials, but overflows if any
 *     coefficient is larger than P.
 *
 *	 * Note that for polynomial multiplication, we don't actually normalise
 *	   the forward Fourier transform, instead delaying normalisation till we do
 *	   the inverse Fourier transform. This makes the calculation slightly
 *	   easier, as we don't propagate extra constant factors when performing
 *	   polynomial multiplication.
 */

namespace FFT {
constexpr int P = 1053818881;
constexpr int K = 20, R = 526909441, E[2] = {933643223, 973782742};

template <typename T>
void fft(T s, T t, bool inv = false) {
	int n = t - s, k = 0;
	while (1 << k < n) k++;

	int j = 0;
	rep (i, n) {
		if (i < j) swap(s[i], s[j]);
		int b = n >> 1;
		while (j & b) b >>= 1;
		j ^= n - b;
	}

	rep (m, k) {
		int l = 1 << m, e = E[inv];
		rep (_, K - 1 - m) e = (ll) e * e % P;
		for (int i = 0; i < n; i += 2 * l) {
			int w = 1;
			rep (j, l) {
				int u = s[i + j], v = (ll) w * s[i + j + l] % P;
				s[i + j] = (u + v) % P;
				s[i + j + l] = (u - v + P) % P;
				w = (ll) w * e % P;
			}
		}
	}

	if (inv) {
		int r = 1;
		rep (_, k) r = (ll) r * R % P;
		rep (i, n) s[i] = (ll) r * s[i] % P;
	}
}
};
