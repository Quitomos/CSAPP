//A.
//E = 2, M = 1.11, f = 0.11, V = 1.11 * 2 ^ 2;
//0 100...001 1100...00

//B. assuming 2^(k - 1) - 1 > n
// E = n, M = 1.11...11, f = 0.11...11, V = 1.11...11 * 2 ^ n;
//0 (n)d + bias 11..11

//C.
//E = 2^(k - 1) - 2, M = 1, f = 0, V = 1 * 2 ^ (2 ^ (k - 1) - 2);
//0 11...1101 00...00