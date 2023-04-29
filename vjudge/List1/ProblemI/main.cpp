#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long num;

vector<num> merge_sorted_arrays(vector<num> v1, vector<num> v2) {
    vector<num> result;
    num v1_idx = 0, v2_idx = 0;

    while (v1_idx < v1.size() && v2_idx < v2.size()) {
        if (v1[v1_idx] <= v2[v2_idx]) {
            result.push_back(v1[v1_idx]);
            v1_idx++;
        } else {
            result.push_back(v2[v2_idx]);
            v2_idx++;
        }
    }

    while (v1_idx < v1.size()) {
        result.push_back(v1[v1_idx]);
        v1_idx++;
    }

    while (v2_idx < v2.size()) {
        result.push_back(v2[v2_idx]);
        v2_idx++;
    }

    return result;
}

void print_vec(vector<num> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << ", ";
    }

    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);

    int datasets, M, N, temp;
    cin >> datasets;
    
    for (int dataset = 0; dataset < datasets; dataset++) {
        cin >> M >> N;
        vector<num> A, u;
        vector<num> db, to_insert;

        for (int i = 0; i < M; i++) {
            cin >> temp;
            A.push_back(temp);
        }

        for (int i = 0; i < N; i++) {
            cin >> temp;
            u.push_back(temp);
        }

        int u_idx = 0;
        for (int i = 0; i < A.size(); i++) {
            to_insert.push_back(A[i]);

            while (i == u[u_idx] - 1 && u_idx < u.size()) {
                if (to_insert.size() > 0) {
                    sort(to_insert.begin(), to_insert.end());
                    db = merge_sorted_arrays(db, to_insert);
                    to_insert.clear();
                }

                cout << db[u_idx] << endl;
                u_idx++;
            }
        }

        if (dataset + 1 < datasets) {
            cout << endl;
        }
    }

    return 0;
}
