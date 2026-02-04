#include <iostream>
#include <queue>
using namespace std;

int main() {
    int K, N;
    cin >> K >> N;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < N; i++) {
        int score;
        cin >> score;

        minHeap.push(score);

        if (minHeap.size() > K) {
            minHeap.pop();
        }

        if (minHeap.size() < K) {
            cout << -1 << endl;
        } else {
            cout << minHeap.top() << endl;
        }
    }

    return 0;
}
