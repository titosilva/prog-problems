#include <stdio.h>

int main() {
    int M, N, i;
    scanf("%d %d", &N, &M);

    int jack[10000000], value;
    for (i = 0; i < N; i++) {
        scanf("%d", &value);
        jack[i] = value;
        printf("%d\n", jack[i]);
    }

    int pos = 0, count = 0;
    for (i = 0; i < M; i++) {
        scanf("%d", &value);

        while (jack[pos] < value && pos < N - 1) {
            pos++;
        }

        if (jack[pos] == value) {
            count++;

            if (pos < N - 1) {
                pos++;
            }
        }
    }

    printf("%d", count);

    return 0;
}