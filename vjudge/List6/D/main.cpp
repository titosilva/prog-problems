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

ll binpower(ll base, ll e, ll mod) {
    ll result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (ll)result * base % mod;
        base = (ll)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(ll n, ll a, ll d, int s) {
    ll x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (ll)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(ll n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    ll d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}

vector<ll> factorize(ll n) {
    vector<ll> factors;

    cout << "Factors of " << n << ":";

    for (auto p : pr) {
        while (n % p == 0) {
            factors.push_back(p);
            n /= p;
        }

        if (n == 1) break;
    }

    for (auto f : factors) {
        cout << " " << f;
    }
    cout << endl;

    return factors;
}

map<ll, ll> d_cache;
// Number of divisors
ll d(ll n, ll mod) {
    if (d_cache.count(n)) return d_cache[n];
    auto factors = factorize(n);
    auto seen = set<ll>();
    
    auto dist = unique(factors.begin(), factors.end());
    ll r = 1;
    for (auto f : factors) {
        if (seen.count(f)) continue;
        seen.insert(f);
        r *= ((count(factors.begin(), factors.end(), f) + 1) % mod);
    }

    cout << "d(" << n << ") = " << r << endl;
    d_cache[n] = r;
    return r;
}

ll MOD = 1073741824;
int main() {
    compute_primes();
    ll a, b, c;
    while (cin >> a >> b >> c) {
        auto s = 0;
        for (ll i = 1; i <= c; i++) {
            s += (d(i, MOD) % MOD);
        }

        auto s2 = 0;
        for (ll i = 1; i <= b; i++) {
            s2 += ((s * d(i, MOD)) % MOD);
        }

        auto s3 = 0;
        for (ll i = 1; i <= c; i++) {
            s3 += ((s2 * d(i, MOD)) % MOD);
        }

        cout << s3 << endl;
    }

    return 0;
}