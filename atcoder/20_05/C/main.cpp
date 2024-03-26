#include <bits/stdc++.h>

using namespace std;
string reference;

int dist(string a, string b) {
    auto d = 0;

    for (int i = 0; i < a.size(); i++) {
        d += (a[i] - b[i] == 0)? 0 : 1;
    }

    return d;
}

// Function to check whether there
// exists a Hamiltonian Path or not
bool Hamiltonian_path(vector<vector<int> >& adj, int N){
    int dp[N][(1 << N)];
 
    // Initialize the table
    memset(dp, 0, sizeof dp);
 
    // Set all dp[i][(1 << i)] to
    // true
    for (int i = 0; i < N; i++)
        dp[i][(1 << i)] = true;
 
    // Iterate over each subset
    // of nodes
    for (int i = 0; i < (1 << N); i++) {
 
        for (int j = 0; j < N; j++) {
 
            // If the jth nodes is included
            // in the current subset
            if (i & (1 << j)) {
 
                // Find K, neighbour of j
                // also present in the
                // current subset
                for (int k = 0; k < N; k++) {
 
                    if (i & (1 << k)
                        && adj[k][j]
                        && j != k
                        && dp[k][i ^ (1 << j)]) {
 
                        // Update dp[j][i]
                        // to true
                        dp[j][i] = true;
                        break;
                    }
                }
            }
        }
    }
 
    // Traverse the vertices
    for (int i = 0; i < N; i++) {
 
        // Hamiltonian Path exists
        if (dp[i][(1 << N) - 1])
            return true;
    }
 
    // Otherwise, return false
    return false;
}

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    auto v = vector<string>(n);

    for (auto &s: v) {
        cin >> s;
    }

    auto g = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist(v[i], v[j]) == 1) g[i][j] = 1;
            else g[i][j] = 0;
        }
    }

    if (Hamiltonian_path(g, n)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}