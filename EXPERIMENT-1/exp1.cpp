#include <bits/stdc++.h>
using namespace std;
using namespace std :: chrono;

int Count = 0;
int depth = 0;
void complexRec(int n , int d) {
    depth = max(depth , d);
    Count++;
    if (n <= 2) {
        return;
    }


    int p = n;
    while (p > 0) {
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = i ^ p;
        }
        p >>= 1;
    }


    vector<int> small(n);
    for (int i = 0; i < n; i++) {
        small[i] = i * i;
    }


    if (n % 3 == 0) {
        reverse(small.begin(), small.end());
    } else {
        reverse(small.begin(), small.end());
    }


    complexRec(n/2 , d+1);
    complexRec(n/2 , d+1);
    complexRec(n/2 , d+1);
}
int main() {
    auto start = high_resolution_clock::now();
    int n; cin >> n;
    complexRec(n , 1);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << duration.count() << "ms" << "\n";
    cout << Count << "\n";
    cout << depth;
}
// Recurrence Relation : 3T(n/2) + nlogn + n + n/2
// Overall Time Complexity : n ^ log(3 , 2)