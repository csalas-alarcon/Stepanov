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
    int result = multiply1(hal(n), a + a);
    if (odd(n)) result = result +a ;
    return result
}

// Hardcoded Mult Algo for 15

int multiply_by_15(int a) {
    int b = (a + a) + a;
    int c = b + b;
    return (c + c) + b;
}