#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long num;

int calc_bits(num reference) {
    int bits = 1;
    num pow2 = 1;

    while (pow2 < reference) {
        bits++;
        pow2 <<= 1;
    }

    if (pow2 > reference) {
        bits--;
    }

    return bits;
}

num f(num X, num A[], int N) {
    num result = 0;

    for (int i = 0; i < N; i++) {
        result += (X ^ A[i]);
    }

    return result;
}

bool majority_of_bits_is_one(num A[], int N, int bit_pos) {
    int ones = 0;

    for (int i = 0; i < N; i++) {
        ones += ((A[i] >> bit_pos) & 1LL)? 1 : 0;
    }

    return ones > N / 2;
}

int main() {
    ios::sync_with_stdio(false);

    int N;
    num K;
    cin >> N >> K;

    num A[N], X = 0, temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        A[i] = temp;
    }

    // Instead of computing how many bits does K have
    // we may iterate over all bits in a long long (64 bits)
    // int bits = calc_bits(K);

    for (int i = 63; i >= 0; i--) {
        X |= majority_of_bits_is_one(A, N, i)? 0 : (1LL << i);

        // If X gets greater than K, just invert the last changed bit
        if (X > K) {
            X ^= (1LL << i);
        }
    }

    cout << f(X, A, N) << endl;
    return 0;
}