/* 
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */ 
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);



/* 
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started. 
 */ 

/* 
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }    

}

char b1_desc[] = "bsize = 1";
void b1(int M, int N, int A[N][M], int B[M][N]) {
    int bsize, i, j, ii, jj;
    bsize = 1;

    for (ii = 0; ii + bsize < N; ii += bsize) {
        for (jj = 0; jj + bsize < M; jj += bsize) {
            for (i = ii; i < ii + bsize; ++i) {
                for (j = jj; j < jj + bsize; ++j) {
                    B[j][i] = A[i][j];
                }
            }
        }
        for (i = ii; i < ii + bsize; ++i) {
            for (j = jj; j < M; ++j) {
                B[j][i] = A[i][j];
            }
        }
    }
    for (jj = 0; jj + bsize < M; jj+= bsize) {
        for (i = ii; i < N; ++i) {
            for (j = jj; j < jj + bsize; ++j) 
            B[j][i] = A[i][j];
        }
    }
    for (i = ii; i < N; ++i) {
        for (j = jj; j < M; ++j) {
            B[j][i] = A[i][j];
        }
    }
}

char b2_desc[] = "bsize = 2";
void b2(int M, int N, int A[N][M], int B[M][N]) {
    int bsize, i, j, ii, jj;
    bsize = 2;

    for (ii = 0; ii + bsize < N; ii += bsize) {
        for (jj = 0; jj + bsize < M; jj += bsize) {
            for (i = ii; i < ii + bsize; ++i) {
                for (j = jj; j < jj + bsize; ++j) {
                    B[j][i] = A[i][j];
                }
            }
        }
        for (i = ii; i < ii + bsize; ++i) {
            for (j = jj; j < M; ++j) {
                B[j][i] = A[i][j];
            }
        }
    }
    for (jj = 0; jj + bsize < M; jj+= bsize) {
        for (i = ii; i < N; ++i) {
            for (j = jj; j < jj + bsize; ++j) 
            B[j][i] = A[i][j];
        }
    }
    for (i = ii; i < N; ++i) {
        for (j = jj; j < M; ++j) {
            B[j][i] = A[i][j];
        }
    }
}

char b3_desc[] = "bsize = 3";
void b3(int M, int N, int A[N][M], int B[M][N]) {
    int bsize, i, j, ii, jj;
    bsize = 3;

    for (ii = 0; ii + bsize < N; ii += bsize) {
        for (jj = 0; jj + bsize < M; jj += bsize) {
            for (i = ii; i < ii + bsize; ++i) {
                for (j = jj; j < jj + bsize; ++j) {
                    B[j][i] = A[i][j];
                }
            }
        }
        for (i = ii; i < ii + bsize; ++i) {
            for (j = jj; j < M; ++j) {
                B[j][i] = A[i][j];
            }
        }
    }
    for (jj = 0; jj + bsize < M; jj+= bsize) {
        for (i = ii; i < N; ++i) {
            for (j = jj; j < jj + bsize; ++j) 
            B[j][i] = A[i][j];
        }
    }
    for (i = ii; i < N; ++i) {
        for (j = jj; j < M; ++j) {
            B[j][i] = A[i][j];
        }
    }
}

char b4_desc[] = "bsize = 4";
void b4(int M, int N, int A[N][M], int B[M][N]) {
    int bsize, i, j, ii, jj;
    bsize = 4;

    for (ii = 0; ii + bsize < N; ii += bsize) {
        for (jj = 0; jj + bsize < M; jj += bsize) {
            for (i = ii; i < ii + bsize; ++i) {
                for (j = jj; j < jj + bsize; ++j) {
                    B[j][i] = A[i][j];
                }
            }
        }
        for (i = ii; i < ii + bsize; ++i) {
            for (j = jj; j < M; ++j) {
                B[j][i] = A[i][j];
            }
        }
    }
    for (jj = 0; jj + bsize < M; jj+= bsize) {
        for (i = ii; i < N; ++i) {
            for (j = jj; j < jj + bsize; ++j) 
            B[j][i] = A[i][j];
        }
    }
    for (i = ii; i < N; ++i) {
        for (j = jj; j < M; ++j) {
            B[j][i] = A[i][j];
        }
    }
}

char b4_2_desc[] = "bsize = 4, version2";
void b4_2(int M, int N, int A[N][M], int B[M][N]) {
    int i, j, ii, jj;
    int a1, a2, a3, a4, a5, a6;

    for (ii = 0; ii < 56; ii += 8) {
        for (jj = 0; jj < 64; jj += 8) {
            for (i = ii; i < ii + 4; ++i) {
                a1 = A[i][jj];
                a2 = A[i][jj + 1];
                a3 = A[i][jj + 2];
                a4 = A[i][jj + 3];
                a5 = A[i][jj + 4];
                a6 = A[i][jj + 5];
                M = A[i][jj + 6];
                N = A[i][jj + 7];
                B[jj][i] = a1;
                B[jj + 1][i] = a2;
                B[jj + 2][i] = a3;
                B[jj + 3][i] = a4;
                B[jj][i + 8] = a5;
                B[jj + 1][i + 8] = a6;
                B[jj + 2][i + 8] = M;
                B[jj + 3][i + 8] = N;
            }

            for (i = ii + 4; i < ii + 8; ++i) {
                a1 = A[i][jj];
                a2 = A[i][jj + 1];
                a3 = A[i][jj + 2];
                a4 = A[i][jj + 3];
                a5 = A[i][jj + 4];
                a6 = A[i][jj + 5];
                M = A[i][jj + 6];
                N = A[i][jj + 7];
                B[jj][i] = a1;
                B[jj + 1][i] = a2;
                B[jj + 2][i] = a3;
                B[jj + 3][i] = a4;
                B[jj][i + 8] = a5;
                B[jj + 1][i + 8] = a6;
                B[jj + 2][i + 8] = M;
                B[jj + 3][i + 8] = N;
            }
            for (j = jj; j < jj + 4; ++j) {
                for (i = ii; i < ii + 8; ++i) {
                    B[j + 4][i] = B[j][i + 8];
                }
            }
        }
    }

    ii = 56;
    for (jj = 0; jj < 64; jj += 8) {
        for (i = ii; i < ii + 4; ++i) {
            a1 = A[i][jj];
            a2 = A[i][jj + 1];
            a3 = A[i][jj + 2];
            a4 = A[i][jj + 3];
            a5 = A[i][jj + 4];
            a6 = A[i][jj + 5];
            M = A[i][jj + 6];
            N = A[i][jj + 7];
            B[jj][i] = a1;
            B[jj + 1][i] = a2;
            B[jj + 2][i] = a3;
            B[jj + 3][i] = a4;
            B[jj][i + 4] = a5;
            B[jj + 1][i + 4] = a6;
            B[jj + 2][i + 4] = M;
            B[jj + 3][i + 4] = N;
        }

        for (j = jj; j < jj + 4; ++j) {
            a1 = B[j][ii + 4];
            a2 = B[j][ii + 5];
            a3 = B[j][ii + 6];
            a4 = B[j][ii + 7];
            B[j + 4][ii] = a1;
            B[j + 4][ii + 1] = a2;
            B[j + 4][ii + 2] = a3;
            B[j + 4][ii + 3] = a4;
        }

        for (i = ii + 4; i < ii + 8; ++i) {
            a1 = A[i][jj];
            a2 = A[i][jj + 1];
            a3 = A[i][jj + 2];
            a4 = A[i][jj + 3];
            B[jj][i] = a1;
            B[jj + 1][i] = a2;
            B[jj + 2][i] = a3;
            B[jj + 3][i] = a4;
        }

        for (i = ii + 4; i < ii + 8; ++i) {
            a1 = A[i][jj + 4];
            a2 = A[i][jj + 5];
            a3 = A[i][jj + 6];
            a4 = A[i][jj + 7];
            B[jj + 4][i] = a1;
            B[jj + 5][i] = a2;
            B[jj + 6][i] = a3;
            B[jj + 7][i] = a4;
        }
    }
}

char b5_desc[] = "bsize = 5";
void b5(int M, int N, int A[N][M], int B[M][N]) {
    int bsize, i, j, ii, jj;
    bsize = 5;

    for (ii = 0; ii + bsize < N; ii += bsize) {
        for (jj = 0; jj + bsize < M; jj += bsize) {
            for (i = ii; i < ii + bsize; ++i) {
                for (j = jj; j < jj + bsize; ++j) {
                    B[j][i] = A[i][j];
                }
            }
        }
        for (i = ii; i < ii + bsize; ++i) {
            for (j = jj; j < M; ++j) {
                B[j][i] = A[i][j];
            }
        }
    }
    for (jj = 0; jj + bsize < M; jj+= bsize) {
        for (i = ii; i < N; ++i) {
            for (j = jj; j < jj + bsize; ++j) 
            B[j][i] = A[i][j];
        }
    }
    for (i = ii; i < N; ++i) {
        for (j = jj; j < M; ++j) {
            B[j][i] = A[i][j];
        }
    }
}

char b6_desc[] = "bsize = 6";
void b6(int M, int N, int A[N][M], int B[M][N]) {
    int bsize, i, j, ii, jj;
    bsize = 6;

    for (ii = 0; ii + bsize < N; ii += bsize) {
        for (jj = 0; jj + bsize < M; jj += bsize) {
            for (i = ii; i < ii + bsize; ++i) {
                for (j = jj; j < jj + bsize; ++j) {
                    B[j][i] = A[i][j];
                }
            }
        }
        for (i = ii; i < ii + bsize; ++i) {
            for (j = jj; j < M; ++j) {
                B[j][i] = A[i][j];
            }
        }
    }
    for (jj = 0; jj + bsize < M; jj+= bsize) {
        for (i = ii; i < N; ++i) {
            for (j = jj; j < jj + bsize; ++j) 
            B[j][i] = A[i][j];
        }
    }
    for (i = ii; i < N; ++i) {
        for (j = jj; j < M; ++j) {
            B[j][i] = A[i][j];
        }
    }
}

char b7_desc[] = "bsize = 7";
void b7(int M, int N, int A[N][M], int B[M][N]) {
        int bsize, i, j, ii, jj;
    bsize = 7;

    for (ii = 0; ii + bsize < N; ii += bsize) {
        for (jj = 0; jj + bsize < M; jj += bsize) {
            for (i = ii; i < ii + bsize; ++i) {
                for (j = jj; j < jj + bsize; ++j) {
                    B[j][i] = A[i][j];
                }
            }
        }
        for (i = ii; i < ii + bsize; ++i) {
            for (j = jj; j < M; ++j) {
                B[j][i] = A[i][j];
            }
        }
    }
    for (jj = 0; jj + bsize < M; jj+= bsize) {
        for (i = ii; i < N; ++i) {
            for (j = jj; j < jj + bsize; ++j) 
            B[j][i] = A[i][j];
        }
    }
    for (i = ii; i < N; ++i) {
        for (j = jj; j < M; ++j) {
            B[j][i] = A[i][j];
        }
    }
}

char b8_desc[] = "bsize = 8";
void b8(int M, int N, int A[N][M], int B[M][N]) {
        int bsize, i, j, ii, jj;
    bsize = 8;

    for (ii = 0; ii + bsize < N; ii += bsize) {
        for (jj = 0; jj + bsize < M; jj += bsize) {
            for (i = ii; i < ii + bsize; ++i) {
                for (j = jj; j < jj + bsize; ++j) {
                    B[j][i] = A[i][j];
                }
            }
        }
        for (i = ii; i < ii + bsize; ++i) {
            for (j = jj; j < M; ++j) {
                B[j][i] = A[i][j];
            }
        }
    }
    for (jj = 0; jj + bsize < M; jj+= bsize) {
        for (i = ii; i < N; ++i) {
            for (j = jj; j < jj + bsize; ++j) 
            B[j][i] = A[i][j];
        }
    }
    for (i = ii; i < N; ++i) {
        for (j = jj; j < M; ++j) {
            B[j][i] = A[i][j];
        }
    }
}

char b8_2_desc[] = "bsize = 8 ,version2";
void b8_2(int M, int N, int A[N][M], int B[M][N]) {
    int i, j, ii, jj;
    int a1, a2, a3, a4, a5, a6;

    for (ii = 0; ii < N; ii += 8) {
        for (jj = 0; jj < M; jj += 8) {
            for (i = ii; i < ii + 8; ++i) {
                if (ii == jj) continue;
                for (j = jj; j < jj + 8; ++j) {
                    B[j][i] = A[i][j];
                }
            }
        }
    }
    for (ii = 0; ii < N; ii += 8) {
        for (i = ii; i < ii + 8; ++i) {
                a1 = A[i][ii];
                a2 = A[i][ii + 1];
                a3 = A[i][ii + 2];
                a4 = A[i][ii + 3];
                a5 = A[i][ii + 4];
                a6 = A[i][ii + 5];
                j = A[i][ii + 6];
                jj = A[i][ii + 7];
                B[ii][i] = a1;
                B[ii + 1][i] = a2;
                B[ii + 2][i] = a3;
                B[ii + 3][i] = a4;
                B[ii + 4][i] = a5;
                B[ii + 5][i] = a6;
                B[ii + 6][i] = j;
                B[ii + 7][i] = jj;
        }
    }
}

char b9_desc[] = "bsize = 9";
void b9(int M, int N, int A[N][M], int B[M][N]) {
        int bsize, i, j, ii, jj;
    bsize = 9;

    for (ii = 0; ii + bsize < N; ii += bsize) {
        for (jj = 0; jj + bsize < M; jj += bsize) {
            for (i = ii; i < ii + bsize; ++i) {
                for (j = jj; j < jj + bsize; ++j) {
                    B[j][i] = A[i][j];
                }
            }
        }
        for (i = ii; i < ii + bsize; ++i) {
            for (j = jj; j < M; ++j) {
                B[j][i] = A[i][j];
            }
        }
    }
    for (jj = 0; jj + bsize < M; jj+= bsize) {
        for (i = ii; i < N; ++i) {
            for (j = jj; j < jj + bsize; ++j) 
            B[j][i] = A[i][j];
        }
    }
    for (i = ii; i < N; ++i) {
        for (j = jj; j < M; ++j) {
            B[j][i] = A[i][j];
        }
    }
}

char b10_desc[] = "bsize = 10";
void b10(int M, int N, int A[N][M], int B[M][N]) {
        int bsize, i, j, ii, jj;
    bsize = 10;

    for (ii = 0; ii + bsize < N; ii += bsize) {
        for (jj = 0; jj + bsize < M; jj += bsize) {
            for (i = ii; i < ii + bsize; ++i) {
                for (j = jj; j < jj + bsize; ++j) {
                    B[j][i] = A[i][j];
                }
            }
        }
        for (i = ii; i < ii + bsize; ++i) {
            for (j = jj; j < M; ++j) {
                B[j][i] = A[i][j];
            }
        }
    }
    for (jj = 0; jj + bsize < M; jj+= bsize) {
        for (i = ii; i < N; ++i) {
            for (j = jj; j < jj + bsize; ++j) 
            B[j][i] = A[i][j];
        }
    }
    for (i = ii; i < N; ++i) {
        for (j = jj; j < M; ++j) {
            B[j][i] = A[i][j];
        }
    }
}

char b11_desc[] = "bsize = 11";
void b11(int M, int N, int A[N][M], int B[M][N]) {
        int bsize, i, j, ii, jj;
    bsize = 11;

    for (ii = 0; ii + bsize < N; ii += bsize) {
        for (jj = 0; jj + bsize < M; jj += bsize) {
            for (i = ii; i < ii + bsize; ++i) {
                for (j = jj; j < jj + bsize; ++j) {
                    B[j][i] = A[i][j];
                }
            }
        }
        for (i = ii; i < ii + bsize; ++i) {
            for (j = jj; j < M; ++j) {
                B[j][i] = A[i][j];
            }
        }
    }
    for (jj = 0; jj + bsize < M; jj+= bsize) {
        for (i = ii; i < N; ++i) {
            for (j = jj; j < jj + bsize; ++j) 
            B[j][i] = A[i][j];
        }
    }
    for (i = ii; i < N; ++i) {
        for (j = jj; j < M; ++j) {
            B[j][i] = A[i][j];
        }
    }
}

char b12_desc[] = "bsize = 12";
void b12(int M, int N, int A[N][M], int B[M][N]) {
        int bsize, i, j, ii, jj;
    bsize = 12;

    for (ii = 0; ii + bsize < N; ii += bsize) {
        for (jj = 0; jj + bsize < M; jj += bsize) {
            for (i = ii; i < ii + bsize; ++i) {
                for (j = jj; j < jj + bsize; ++j) {
                    B[j][i] = A[i][j];
                }
            }
        }
        for (i = ii; i < ii + bsize; ++i) {
            for (j = jj; j < M; ++j) {
                B[j][i] = A[i][j];
            }
        }
    }
    for (jj = 0; jj + bsize < M; jj+= bsize) {
        for (i = ii; i < N; ++i) {
            for (j = jj; j < jj + bsize; ++j) 
            B[j][i] = A[i][j];
        }
    }
    for (i = ii; i < N; ++i) {
        for (j = jj; j < M; ++j) {
            B[j][i] = A[i][j];
        }
    }
}

char b13_desc[] = "bsize = 13";
void b13(int M, int N, int A[N][M], int B[M][N]) {
        int bsize, i, j, ii, jj;
    bsize = 13;

    for (ii = 0; ii + bsize < N; ii += bsize) {
        for (jj = 0; jj + bsize < M; jj += bsize) {
            for (i = ii; i < ii + bsize; ++i) {
                for (j = jj; j < jj + bsize; ++j) {
                    B[j][i] = A[i][j];
                }
            }
        }
        for (i = ii; i < ii + bsize; ++i) {
            for (j = jj; j < M; ++j) {
                B[j][i] = A[i][j];
            }
        }
    }
    for (jj = 0; jj + bsize < M; jj+= bsize) {
        for (i = ii; i < N; ++i) {
            for (j = jj; j < jj + bsize; ++j) 
            B[j][i] = A[i][j];
        }
    }
    for (i = ii; i < N; ++i) {
        for (j = jj; j < M; ++j) {
            B[j][i] = A[i][j];
        }
    }
}

char b14_desc[] = "bsize = 14";
void b14(int M, int N, int A[N][M], int B[M][N]) {
        int bsize, i, j, ii, jj;
    bsize = 14;

    for (ii = 0; ii + bsize < N; ii += bsize) {
        for (jj = 0; jj + bsize < M; jj += bsize) {
            for (i = ii; i < ii + bsize; ++i) {
                for (j = jj; j < jj + bsize; ++j) {
                    B[j][i] = A[i][j];
                }
            }
        }
        for (i = ii; i < ii + bsize; ++i) {
            for (j = jj; j < M; ++j) {
                B[j][i] = A[i][j];
            }
        }
    }
    for (jj = 0; jj + bsize < M; jj+= bsize) {
        for (i = ii; i < N; ++i) {
            for (j = jj; j < jj + bsize; ++j) 
            B[j][i] = A[i][j];
        }
    }
    for (i = ii; i < N; ++i) {
        for (j = jj; j < M; ++j) {
            B[j][i] = A[i][j];
        }
    }
}

char b15_desc[] = "bsize = 15";
void b15(int M, int N, int A[N][M], int B[M][N]) {
        int bsize, i, j, ii, jj;
    bsize = 15;

    for (ii = 0; ii + bsize < N; ii += bsize) {
        for (jj = 0; jj + bsize < M; jj += bsize) {
            for (i = ii; i < ii + bsize; ++i) {
                for (j = jj; j < jj + bsize; ++j) {
                    B[j][i] = A[i][j];
                }
            }
        }
        for (i = ii; i < ii + bsize; ++i) {
            for (j = jj; j < M; ++j) {
                B[j][i] = A[i][j];
            }
        }
    }
    for (jj = 0; jj + bsize < M; jj+= bsize) {
        for (i = ii; i < N; ++i) {
            for (j = jj; j < jj + bsize; ++j) 
            B[j][i] = A[i][j];
        }
    }
    for (i = ii; i < N; ++i) {
        for (j = jj; j < M; ++j) {
            B[j][i] = A[i][j];
        }
    }
}

char b16_desc[] = "bsize = 16";
void b16(int M, int N, int A[N][M], int B[M][N]) {
        int bsize, i, j, ii, jj;
    bsize = 16;

    for (ii = 0; ii + bsize < N; ii += bsize) {
        for (jj = 0; jj + bsize < M; jj += bsize) {
            for (i = ii; i < ii + bsize; ++i) {
                for (j = jj; j < jj + bsize; ++j) {
                    B[j][i] = A[i][j];
                }
            }
        }
        for (i = ii; i < ii + bsize; ++i) {
            for (j = jj; j < M; ++j) {
                B[j][i] = A[i][j];
            }
        }
    }
    for (jj = 0; jj + bsize < M; jj+= bsize) {
        for (i = ii; i < N; ++i) {
            for (j = jj; j < jj + bsize; ++j) 
            B[j][i] = A[i][j];
        }
    }
    for (i = ii; i < N; ++i) {
        for (j = jj; j < M; ++j) {
            B[j][i] = A[i][j];
        }
    }
}

char b32_desc[] = "bsize = 32";
void b32(int M, int N, int A[N][M], int B[M][N]) {
        int bsize, i, j, ii, jj;
    bsize = 32;

    for (ii = 0; ii + bsize < N; ii += bsize) {
        for (jj = 0; jj + bsize < M; jj += bsize) {
            for (i = ii; i < ii + bsize; ++i) {
                for (j = jj; j < jj + bsize; ++j) {
                    B[j][i] = A[i][j];
                }
            }
        }
        for (i = ii; i < ii + bsize; ++i) {
            for (j = jj; j < M; ++j) {
                B[j][i] = A[i][j];
            }
        }
    }
    for (jj = 0; jj + bsize < M; jj+= bsize) {
        for (i = ii; i < N; ++i) {
            for (j = jj; j < jj + bsize; ++j) 
            B[j][i] = A[i][j];
        }
    }
    for (i = ii; i < N; ++i) {
        for (j = jj; j < M; ++j) {
            B[j][i] = A[i][j];
        }
    }
}
/* 
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded. 
 */

 char transpose_submit_desc[] = "Transpose submission";
 void transpose_submit(int M, int N, int A[N][M], int B[M][N])
 {
	if (M == 32) b8_2(M, N, A, B);
	else if (M == 61) b16(M, N, A, B);
	else b4_2(M, N, A, B);
 }
/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc); 

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc); 
    registerTransFunction(b1, b1_desc); 
    registerTransFunction(b2, b2_desc); 
    registerTransFunction(b3, b3_desc); 
    registerTransFunction(b4, b4_desc);
    registerTransFunction(b4_2, b4_2_desc); 
    registerTransFunction(b5, b5_desc); 
    registerTransFunction(b6, b6_desc); 
    registerTransFunction(b7, b7_desc); 
    registerTransFunction(b8, b8_desc);
    registerTransFunction(b8_2, b8_2_desc); 
    registerTransFunction(b9, b9_desc); 
    registerTransFunction(b10, b10_desc); 
    registerTransFunction(b11, b11_desc); 
    registerTransFunction(b12, b12_desc); 
    registerTransFunction(b13, b13_desc); 
    registerTransFunction(b14, b14_desc); 
    registerTransFunction(b15, b15_desc); 
    registerTransFunction(b16, b16_desc);
    registerTransFunction(b32, b32_desc);  
}

/* 
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

