#include "cachelab.h"
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

typedef unsigned us;

us hits, misses, evictions;
int verbose;

typedef enum{
    hit, miss, eviction
} _STATE;

struct _CACHE {
    us S, E, B;
    us s, b;
    us*** c;
} cache;

void init(us s, us E, us b) {
    us S, B, i, j;
    hits = 0;
    misses =0;
    evictions = 0;
    S = 1 << s;
    B = 1 << b;
    cache.S = S;
    cache.B = B;
    cache.E = E;
    cache.s = s;
    cache.b = b;
    cache.c = malloc(S * sizeof(us**));
    for (i = 0; i < S; ++i) {
        cache.c[i] = malloc(E * sizeof(us*));
        for (j = 0; j < E; ++j) {
            cache.c[i][j] = malloc(3 * sizeof(us));
            cache.c[i][j][0] = 0;   //flag
            cache.c[i][j][1] = 0;   //t
            cache.c[i][j][2] = 0;   //Time
        }
    }
}

void visit(us add) {
    us S, t, i, insert, mint, mintidx, curt;
    us maxt = cache.E;
    _STATE state;

    insert = -1;
    mint = maxt + 1;
    S = (add >> cache.b) & ((1 << cache.s) - 1);
    t = add >> (cache.b + cache.s);
    for (i = 0; i < maxt; ++i) {
        if (cache.c[S][i][0] == 0) {
            insert = i;
            state = miss;
            continue;
        }
        else if (cache.c[S][i][1] == t) {
            insert = i;
            state = hit;
            break;
        }
        else if (mint >= cache.c[S][i][2]) {
            mint = cache.c[S][i][2];
            mintidx = i;
        }
    }
    if (insert == -1) {
        state = eviction;
        insert = mintidx;
    }
    curt = cache.c[S][insert][2];
    cache.c[S][insert][0] = 1;
    cache.c[S][insert][1] = t;
    for (i = 0; i < maxt; ++i) {
        if (cache.c[S][i][2] > curt) --cache.c[S][i][2];
    }
    cache.c[S][insert][2] = maxt;
    switch (state) {
        case eviction:  ++evictions;
        case miss:  ++misses; break;
        case hit:   ++hits; break;
        default:    break;
    }
    if (verbose == 1) {
        switch (state) {
            case miss:  printf(" miss"); break;
            case hit:   printf(" hit"); break;
            case eviction:  printf(" miss eviction"); break;
            default:    break;
        }
    }
}
void printHelp() {
    printf("Usage: ./csim-ref [-hv] -s <num> -E <num> -b <num> -t <file>\n");
    printf("Options:\n");
    printf("  -h         Print this help message.\n");
    printf("  -v         Optional verbose flag.\n");
    printf("  -s <num>   Number of set index bits.\n");
    printf("  -E <num>   Number of lines per set.\n");
    printf("  -b <num>   Number of block offset bits.\n");
    printf("  -t <file>  Trace file.\n\n");
    printf("Examples:\n");
    printf("  linux>  ./csim-ref -s 4 -E 1 -b 4 -t traces/yi.trace\n");
    printf("  linux>  ./csim-ref -v -s 8 -E 2 -b 4 -t traces/yi.trace");
}
void freeCache() {
    int i, j;
    int imax = cache.S, jmax = cache.E;
    for (i = 0; i < imax; ++i) {
        for (j = 0; j < jmax; ++j) {
            free(cache.c[i][j]);
        }
        free(cache.c[i]);
    }
    free(cache.c);
}
int main(int argc, char* const argv[])
{
    char opt, type;
    long int add;
    int size;
    FILE* fp = NULL;
    int s = -1, E = -1, b = -1;
    int error = 0, help = 0;
    verbose = 0;
    while ((opt = getopt(argc, argv, "hvs:E:b:t:")) != -1) {
        switch(opt) {
            case 'h':   printHelp(); help = 1; break;
            case 'v':   verbose = 1; break;
            case 's':   s = atoi(optarg); break;
            case 'E':   E = atoi(optarg); break;
            case 'b':   b = atoi(optarg); break;
            case 't':   fp = fopen(optarg, "r"); break;
            default:    error = 1;
        }
    }
    if (s <= 0 || E <= 0 || b <= 0 || fp == NULL || error) {
        if (!help) printHelp();
        return 0;
    }
    init(s, E, b);
    while (fscanf(fp, " %c %lx,%d", &type, &add, &size) > 0) {
        if (type == 'I') continue;
        if (verbose) printf("%c %lx,%d", type, add, size);
        if (type == 'M') visit(add);
        visit(add);
        if (verbose) printf("\n");
    }
    printSummary(hits, misses, evictions);
    freeCache();
    return 0;
}
