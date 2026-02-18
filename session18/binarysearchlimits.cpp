#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& arr, int req) {
    int l = 0, h = arr.size();
    while (l < h) {
        int mid = l + (h - l) / 2;
        if (arr[mid] < req) l = mid + 1;
        else h = mid;
    }
    return l;
}

int upperBound(vector<int>& arr, int req) {
    int l = 0, h = arr.size();
    while (l < h) {
        int mid = l + (h - l) / 2;
        if (arr[mid] <= req) l = mid + 1;
        else h = mid;
    }
    return l;
}

int main() {
    vector<int> arr = {1,3,7,9,11,12};
    int req = 3;
    cout << lowerBound(arr, req) << endl;
    cout << upperBound(arr, req) << endl;
    return 0;
}