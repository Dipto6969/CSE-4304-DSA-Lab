#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Deque {
private:
    int maxSize;
    vector<int> data;
    int left, right;

public:
    Deque(int size) {
        maxSize = size;
        data.resize(maxSize);
        left = right = -1;
    }

    bool isFull() {
        return (left == 0 && right == maxSize - 1) || (right == left - 1);
    }

    bool isEmpty() {
        return left == -1;
    }

    void pushLeft(int x) {
        if (isFull()) {
            cout << "The queue is full" << endl;
        } else {
            if (left == -1) {
                left = right = 0;
                data[left] = x;
            } else if (left > 0) {
                left--;
                data[left] = x;
            } else if (right < maxSize - 1) {
                left = maxSize - 1;
                data[left] = x;
            }
            cout << "Pushed in left: " << x << endl;
        }
    }

    void pushRight(int x) {
        if (isFull()) {
            cout << "The queue is full" << endl;
        } else {
            if (left == -1) {
                left = right = 0;
                data[right] = x;
            } else if (right < maxSize - 1) {
                right++;
                data[right] = x;
            } else if (left > 0) {
                right = 0;
                data[right] = x;
            }
            cout << "Pushed in right: " << x << endl;
        }
    }

    void popLeft() {
        if (isEmpty()) {
            cout << "The queue is empty" << endl;
        } else {
            cout << "Popped from left: " << data[left] << endl;
            if (left == right) {
                left = right = -1;
            } else if (left == maxSize - 1) {
                left = 0;
            } else {
                left++;
            }
        }
    }

    void popRight() {
        if (isEmpty()) {
            cout << "The queue is empty" << endl;
        } else {
            cout << "Popped from right: " << data[right] << endl;
            if (left == right) {
                left = right = -1;
            } else if (right == 0) {
                right = maxSize - 1;
            } else {
                right--;
            }
        }
    }
};

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int n, m;
        cin >> n >> m;
        Deque dq(n);

        cout << "Case " << t << ":" << endl;

        for (int i = 0; i < m; i++) {
            string cmd;
            cin >> cmd;

            if (cmd == "pushLeft") {
                int x;
                cin >> x;
                dq.pushLeft(x);
            } else if (cmd == "pushRight") {
                int x;
                cin >> x;
                dq.pushRight(x);
            } else if (cmd == "popLeft") {
                dq.popLeft();
            } else if (cmd == "popRight") {
                dq.popRight();
            }
        }
    }

    return 0;
}
