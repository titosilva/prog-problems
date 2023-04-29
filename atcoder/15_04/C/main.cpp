#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
struct Node {
    Node* next;
    int value;
};

Node* alloc(int value) {
    auto r = (Node*)malloc(sizeof(Node));

    r->value = value;
    r->next = NULL;

    return r;
}

int main() {
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<Node*> boxes = vector<Node*>(n);
    auto in_boxes = unordered_map<int, vector<int>>();
    
    for (auto &b: boxes) {
        b = NULL;
    }

    int t, i, j, k;
    for (int k = 0; k < q; k++) {
        cin >> t;
        if (t == 1) {
            cin >> i >> j;

            if (in_boxes.find(i) == in_boxes.end()) {
                in_boxes[i] = vector<int>();
            }
            in_boxes[i].push_back(j);

            Node* place = boxes[j];
            if (place == NULL) {
                boxes[j] = alloc(i);
            } else {
                while (place->value < i && place->next != NULL) {
                    place = place->next;
                }

                auto n = alloc(i);
                if (place == boxes[j] && place->value > i) {
                    boxes[j] = n;
                    n -> next = place;
                } else {
                    n->next = place->next;
                    place->next = n;
                }
            }
        } else if (t == 2) {
            cin >> i;

            Node* place = boxes[i];
            while (place != NULL) {
                cout << place->value << " ";
                place = place->next;
            }
            cout << endl;
        } else {
            cin >> i;
        
            if (in_boxes.find(i) != in_boxes.end()) {
                sort(in_boxes[i].begin(), in_boxes[i].end());
                int last = -1;
                for (auto b: in_boxes[i]) {
                    if (last == b) {
                        continue;
                    }

                    cout << b << " ";
                    last = b;
                }
                cout << endl;
            }
        }
    }

    return 0;
}