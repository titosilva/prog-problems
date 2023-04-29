#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct less_than_key
{
    inline bool operator() (const pair<int, int>& struct1, const pair<int, int>& struct2)
    {
        return (struct1.first < struct2.first);
    }
};

int search_greater_element_leq(vector<pair<int, int>> elements, int max) {
    int range_min = 0, range_max = elements.size();
    int i = (range_max + range_min) / 2;

    while (true) {
        if (range_max <= range_min + 1) break;
        i = (range_max + range_min) / 2;

        if (elements[i].first > max) {
            range_max = i;
        } else {
            range_min = i;
        }
    }

    return range_min;
}

int main() {
    ios::sync_with_stdio(false);
    int N, Q;
    cin >> N >> Q;

    unordered_map<int, vector<pair<int, int>>> roadwork_times;
    unordered_map<int, int> roadwork_max_times, roadwork_min_times;
    vector<int> roadwork_points;

    int S, T, X;
    for (int i = 0; i < N; i++) {
        cin >> S >> T >> X;

        if (S > T) {
            swap(S, T);
        }

        if (X > T) {
            // No one gets to this X before time T
            continue;
        }

        if (roadwork_times.find(X) == roadwork_times.end()) {
            roadwork_times[X] = vector<pair<int, int>>();
            roadwork_max_times[X] = T;
            roadwork_min_times[X] = S;
            roadwork_points.push_back(X);
        }

        roadwork_times[X].push_back(pair<int, int>(S, T));

        if (T > roadwork_max_times[X]) {
            roadwork_max_times[X] = T;
        }

        if (S < roadwork_min_times[X]) {
            roadwork_min_times[X] = S;
        }
    }

    sort(roadwork_points.begin(), roadwork_points.end());
    for (auto x: roadwork_points) {
        sort(roadwork_times[x].begin(), roadwork_times[x].end(), less_than_key());
    }

    int D;
    for (int i = 0; i < Q; i++) {
        cin >> D;

        bool done = false;
        for (auto x: roadwork_points) {
            // cout << "D: " << D << "; x(loop): " << x << "; max: " << roadwork_max_times[x] << "; min: " << roadwork_min_times[x] << endl;

            if (D + x > roadwork_max_times[x]) {
                continue;
            } else if (D + x < roadwork_min_times[x]) {
                continue;
            } else {
                auto idx = search_greater_element_leq(roadwork_times[x], D + x);
                auto values = roadwork_times[x][idx];

                // cout << "D: " << D << "; x: " << x << "; v: " << values.first << ", " << values.second << endl;
                if (D + x >= values.first && D + x < values.second) {
                    cout << x << endl;
                    done = true;
                    break;
                }
            }
        }

        if (!done) {
            cout << -1 << endl;
        }
    }    

    return 0;
}