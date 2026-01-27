#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Number of attendance records: ";
    cin >> n;

    vector<char> a(n);
    cout << "Enter attendance records (P/A): ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<int, int> mp;
    int count = 0;
    int maxLen = 0;
    mp[0] = -1;

    for (int i = 0; i < n; i++) {

        if (a[i] == 'P'||a[i] == 'p')
            count++;
        else if (a[i] == 'A'||a[i] == 'a')
            count--;

        if (mp.find(count) != mp.end()) {
            int len = i - mp[count];
            if (len > maxLen)
                maxLen = len;
        } else {
            mp[count] = i;
        }
    }

    cout << "Maximum length of stable attendance window: "
         << maxLen << endl;

    return 0;
}