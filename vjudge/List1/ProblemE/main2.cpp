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

    num N, L, U, M;


    
    return 0;
}