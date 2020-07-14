#include <iostream>

using namespace std;

void* mycalloc(size_t nmemb, size_t size) {
    if (nmemb == 0 || size == 0) return NULL;
    size_t cap = nmemb * size;
    if (cap / nmemb == size) {
        void* p = malloc(cap);
        if (p != NULL) memset(p, 0, cap);
        return p;
    }
    return NULL;
}

int main() {
    void* p;
    p = mycalloc(0x1234, 1);
    cout << (p != NULL) << endl;
    free(p);

    p = mycalloc(SIZE_MAX, 2);
    cout << (p == NULL) << endl;
    free(p);
    return 0;
}