#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long num;

num gen_mask(num reference) {
    num pow2 = 1;

    while (pow2 < reference) {
        pow2 <<= 1;
    }

    if (pow2 > reference) {
        pow2 >>= 1;
    }

    // cout << "Num: " << reference << "; Pow: " << pow2 << "; Result: " << (pow2 | (pow2 - 1)) << endl;
    return pow2 | (pow2 - 1);
}

int main() {
    ios::sync_with_stdio(false);

    unsigned int N;
    num L, U, M, mask, required_bits;

    while (cin >> N >> L >> U) {
        if (L == U) {
            cout << L << endl;
            continue;
        }

        if (L > U) {
            swap(L, U);
        }

        mask = gen_mask(L ^ U);
        required_bits = (mask & ~(N & mask));
        M = (U & ~mask) | required_bits;

        // cout << "Mask: " << mask << "; N: " << N << "; N & mask: " << (N & mask) << endl;

        if (M > U) {
            M = U & ~(N & mask);
        }

        if (M < L) {
            M |= (L & mask);
        }

        cout << M << endl;
    }

    return 0;
}