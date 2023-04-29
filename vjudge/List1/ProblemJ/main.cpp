#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long num;

void read_values(vector<num>& vec, int quantity) {
    num value, last_value = -1;
    for (int i = 0; i < quantity; i++) {
        cin >> value;

        if (value == last_value) {
            continue;
        }

        vec.push_back(value);
        last_value = value;
    }
}

int main() {
    ios::sync_with_stdio(false);

    num N, M;
    while (cin >> N >> M) {
        if (N == 0 && M == 0) {
            continue;
        }

        vector<num> jack, jill;
        read_values(jack, N);
        read_values(jill, M);

        int count = 0, jack_pos = 0, jill_pos = 0;
        num jack_value, jill_value;
        while (jack_pos < N && jill_pos < M) {
            jack_value = jack[jack_pos];
            jill_value = jill[jill_pos];

            if (jack_value == jill_value) {
                count++;
                jack_pos++;
                jill_pos++;
            } else if (jack_value < jill_value) {
                jack_pos++;
            } else {
                jill_pos++;
            }
        }

        cout << count << endl;
    }

    return 0;
}