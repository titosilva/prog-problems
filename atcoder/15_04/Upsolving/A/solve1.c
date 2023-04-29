#include <stdio.h>

int main() {

    // Caution: remember to add a space for the \0
    // int N;
    // char S[N];

    // Caution: remember to read N
    // int N;
    // char S[N + 1];

    int N;
    scanf("%d", &N);

    char S[N + 1];
    // S is already a pointer, no need to add &
    scanf("%s", S);

    // Caution: remember to initialize x and o
    // int x, o;
    int x = 0, o = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'x') x++;
        if (S[i] == 'o') o++;
    }

    if (x > 0 && o == 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
