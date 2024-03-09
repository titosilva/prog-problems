#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

// upper limit for primes
const int N = 1001000;
int lastp = -1;
vector<int> lp(N+1);
vector<int> pr, jmp;
void compute_primes() {
    for (int i=2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);

            if (lastp < 0) {
                lastp = i;
            } else {
                jmp.push_back(i - lastp);
                lastp = i;
            }
        }
        for (int j = 0; i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }
}


int main() {
    compute_primes();
    auto prs = pr.size();
    int t, l, u;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> l >> u;

        int b = -1, r = prs;
        while(r - b > 1) {
            int m = (b + r) / 2;
            if(l < pr[m]) {
                r = m; // a[l] <= k < a[m] <= a[r]
            } else {
                b = m; // a[l] <= a[m] <= k < a[r]
            }
        }

        map<int, int> cnts;
        while (pr[b] <= u) {
            if (b == 0 || pr[b] < l || pr[b - 1] < l) {
                b++;
                continue;
            }

            auto diff = pr[b] - pr[b - 1];
            // cout << diff << " ";
            cnts[diff]++;
            b++;
        }
        // cout << endl;

        int max_jmp = 0, max_cnt = -1, max_r = 0;
        for (auto c: cnts) {
            // cout << c.first << " " << c.second << endl;
            auto x = cnts[c.first];
            if (max_cnt < x) {
                max_jmp = c.first;
                max_cnt = cnts[max_jmp];
                max_r = 0;
            } else if (max_cnt == x) {
                max_r++;
            }
        }

        if (max_cnt == -1 || max_r > 0) {
            cout << "No jumping champion" << endl;
        } else {
            cout << "The jumping champion is " << max_jmp << endl;
        }
    }


    return 0;
}