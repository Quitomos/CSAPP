#include <stdio.h>
#define BUFF_SIZE 8
void good_echo(void) {
    char buff[BUFF_SIZE];
    while (1) {
        char* p = fgets(buff, BUFF_SIZE, stdin);
        if (!p) break;
        printf("%s", p);
    }
}

int main() {
    good_echo();
    return 0;
}