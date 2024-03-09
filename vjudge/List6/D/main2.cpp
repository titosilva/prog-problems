#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

// upper limit for primes
const int N = 100;
vector<int> lp(N+1);
vector<int> pr;
void compute_primes() {
    for (int i=2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }
}

map<ll, multiset<ll>> factor_cache;
multiset<ll> factorize(ll n) {
    if (factor_cache.count(n)) {
        return factor_cache[n];
    }

    multiset<ll> factors;

    for (auto p : pr) {
        while (n % p == 0) {
            factors.insert(p);
            n /= p;
        }

        if (n == 1) break;
    }

    return factors;
}

multiset<ll> factorize(ll a, ll b, ll c) {
    if (factor_cache.count(a * b * c)) return factor_cache[a * b * c];

    auto af = multiset<ll>(factorize(a));
    auto bf = multiset<ll>(factorize(b));
    auto cf = multiset<ll>(factorize(c));

    auto r = multiset<ll>();
    r.insert(af.begin(), af.end());
    r.insert(bf.begin(), bf.end());
    r.insert(cf.begin(), cf.end());

    factor_cache[a * b * c] = r;
    return r;
}

map<ll, ll> d_cache;
// Number of divisors
ll d(multiset<ll> factors, ll mod) {
    ll p = 1, aux = 1;

    for (auto f: factors) {
        if (aux % f == 0) continue;
        p *= factors.count(f) + 1;
        aux *= f;
    }

    return p;
}

ll d(ll a, ll b, ll c, ll mod) {
    if (d_cache.count(a * b * c)) return d_cache[a * b * c];

    auto r = d(factorize(a, b, c), mod);
    d_cache[a * b * c] = r;
    return r;
}

ll MOD = 1073741824;
int main() {
    compute_primes();

    ll a, b, c;
    while (cin >> a >> b >> c) {
        ll s = 0;
        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                for (int k = 1; k <= c; k++) {
                    s = (s + d(i, j, k, MOD)) % MOD;
                }
            }
        }
        cout << s << endl;
    }

    return 0;
}