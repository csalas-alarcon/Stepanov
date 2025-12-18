// Raw Multiplication Algo

int multiply0(int n, int a) {
    if (n==1) return a;
    return multiply0(n-1, a) + a;
}

// Greek Multiplication Algo

bool odd(int n) { return n & 0x1; }
int half(int n) { return n >> 1; }

int multiply1(int n, int a) {
    if (n==1) return a;
    int result = multiply1(half(n), a + a);
    if (odd(n)) result = result +a ;
    return result;
}

// Hardcoded Mult Algo for 15

int multiply_by_15(int a) {
    int b = (a + a) + a;
    int c = b + b;
    return (c + c) + b;
}

// Multiply Accumulative Algo .1v

int mult_acc0( int r, int n, int a) {
    if (n==1) return r + a;
    if (odd(n)) {
        return mult_acc0( r + a, half(n), a + a );
    } else {
        return mult_acc0( r, half(n), a + a);
    }
}

// Multiply Accumulative Algo .2v

int mult_acc1( int r, int n, int a) {
    if ( n==1 ) return r +a;
    if (odd(n)) r = r + a;
    return mult_acc1(r, half(n), a + a);
}

// Multiply Accumulative Algo .3v

int mult_acc2( int r, int n, int a) {
    if (odd(n)) {
        r = r + a;
        if (n ==1) return n;
    }
    return mult_acc2( r, half(n), a + a);
}

// Multiply Accumulative Algo .4v

int mult_acc3( int r, int n, int a) {
    if (odd(n)) {
        r = r + a;
        if (n==1) return r;
    }
    n = half(n);
    a = a + a;
    return mult_acc3( r, n , a);
}

// Multiply Accumulative Algo .5v

int mult_acc4( int r, int n, int a) {
    while (true) {
        if (odd(n)) {
            r = r + a;
            if (n==1) return r;
        }
        n = half(n);
        a = a + a;
    }
}

// Multiply w Integrated Accumulative Function Algo .1v

int multiply2( int n, int a) {
    if (n==1) return a;
    return mult_acc4( a, n+1, a);
}

// Multiply w Integrated Accumulative Function Algo .2v

int multiply3( int n, int a) {
    while (!odd(n)) {
        a = a + a;
        n = half(n);
    }
    if (n==1) return a;
    return mult_acc4( a, n-1, a);
}

// Multiply w Integrated Accumulative function Algo .2v
int multiply4( int n, int a) {
    while (!odd(n)) {
        a = a + a;
        n = half(n);
    }
    if (n==1) return a;
    return mult_acc4( a, half(n-1), a + a);
}
