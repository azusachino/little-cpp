#include <deque>
#include <iostream>

using namespace std;

int main() {
    deque<float> q;

    for (int i = 0; i <= 6; ++i) {
        q.push_front(i);
    }
    for (int i = 0; i < q.size(); ++i) {
        cout << q[i] << endl;
    }
}