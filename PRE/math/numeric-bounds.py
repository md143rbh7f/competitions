DESCRIPTION = """
Calculate for all integers less than or equal to the input integer N:

    1.  The smallest integer with the most distinct prime factors.

        This is the inverse of the primorial.

    2.  The smallest integer with the most total prime factors.

        This is the largest power of 2.

    3.  The smallest integer with the most divisors.

        This is the largest highly composite number. (A number is called highly
        composite if it has more factors than any number less than it.) Due to
        the low recursion depth and branching factor, this calculation is
        practically instantaneous for all 64-bit integers.
"""

import argparse
import math


# Arbitrary magic number
C = 5


def log2(n):
    return int(math.log2(n))


def sieve(n):
    prime = [True for _ in range(n + 1)]
    prime[0] = prime[1] = False
    for i in range(2, n + 1):
        if prime[i]:
            yield i
            for j in range(2 * i, n + 1, i):
                prime[j] = False


def max_distinct_prime_factors(n):
    ans, cnt = 1, 0
    for p in sieve(log2(n) + C):
        if ans * p > n:
            return ans, cnt
        ans *= p
        cnt += 1


def max_total_prime_factors(n):
    l = log2(n)
    return 1 << l, l


def max_divisors(n):
    primes = list(sieve(log2(n) + C))

    def rec(idx, cur, max_e):
        ans, cnt, e = cur, 1, 0
        while True:
            cur *= primes[idx]
            e += 1

            if e > max_e or cur > n:
                break

            nxt_ans, nxt_cnt = rec(idx + 1, cur, e)
            if (e + 1) * nxt_cnt > cnt:
                ans, cnt = nxt_ans, (e + 1) * nxt_cnt

        return ans, cnt

    return rec(0, 1, float('inf'))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        description=DESCRIPTION,
        formatter_class=argparse.RawDescriptionHelpFormatter
    )
    parser.add_argument('N', type=int, help='Must be >= 2')
    n = parser.parse_args().N
    assert(n >= 2)

    print('For integers less than or equal to {}:'.format(n))
    print(
        'Smallest integer with most distinct prime factors: {} ({}).'
        .format(*max_distinct_prime_factors(n))
    )
    print(
        'Smallest integer with most total prime factors: {} ({}).'
        .format(*max_total_prime_factors(n))
    )
    print(
        'Smallest integer with most divisors: {} ({}).'
        .format(*max_divisors(n))
    )
