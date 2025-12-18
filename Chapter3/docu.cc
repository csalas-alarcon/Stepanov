
// The Sieving Method Itself 
template <RandomAccessIterator I, Integer N>
void mark_sieve(I first, I last, N factor) {
	// assert (first != last)
	*first = false;
	while (last - first > factor) {
		first = first + factor;
		*first = false;
	}
}

// Sieve of Erathostenes .1v
template <RandomAccessIterator I, Integer N>
void sift0(I first, N n) {
	std::fill(first, first + n, true);
	N i(0);
	N index_square(3);
	while (index_square < n) {
		// invariant: index_square = 2i^2 + 6i + 3
		if (first[i]) {
			mark_sieve(first + index_square, first + n, i +i + 3);
		}
		++i;
		index_square = 2*i*(i + 3) + 3;
	}
}

// Sieve of Erathostenes .2v
template <RandomAccessIterator I, Integer N>
void sift1( I first, N n) {
	I last = first + n;
	std::fill(first, last, true);
	N i(0);
	N index_square(3);
	N factor(3);
	while (index_square < n) {
		// invariant: index_square = 2i^2 + 6i + 3,
		// 			  factor = 2i + 3
		if (first[i]) {
			mark_sieve(first + index_square, last, factor);
		}
		++i;
		factor = i + i + 3;
		index_square = 2*i*(i+3) + 3;
	}
}

// Sieve of Erathostenes .3v
template <RandomAccessIterator I, Integer N>
void sift( I first, N n) {
	I last = first + n;
	std::fill(first, last, true);
	N i(0);
	N index_square(3);
	N factor(3);

	while (index_square < n) {
		// invariant: index_square = 2i^2 + 6i + 3,
		// 			  factor = 2i + 3
		if (first[i]) {
			mark_sieve( first + index_square, last, factor);
		}
		++i;
		index_square += factor;
		factor += N(2);
		index_square += factor;
	}
}

// Euclids Perfect : if S (i=0, n) (2**i) is prime then 2**n * S (i=0, n) (n**i)

#include <cmath>
template <RandomAccessIterator I, Integer N>
void shiffUntilNth( I first, N n) {
	size_t limit = n * (std:log(n) + std::log(std::log(n)));
	std::vector<bool> sieve(limit, true);
	N i(0);
	N index_square(3);
	N factor(3);

	while (index_square < n) {
		if (first[i]) {
			mark_sieve( first + index_square, first + limit, factor);
		}
		++i;
		index_square += factor;
		factor += N(2);
		index_square += factor;
	}
}

int sumatorium(int n) {
	if (n == 0) return 1;
	else return 2**n + sumatorium(n-1);
}

int perfect(int n) {
	int limit = n *
	std::vector<bool> my_sieve(100);
	return 0;
}

