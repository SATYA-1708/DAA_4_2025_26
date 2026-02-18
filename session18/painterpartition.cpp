class Solution {
  public:
    bool canPaint(vector<int>& arr, int k, int maxTime) {
        int painters = 1, currSum = 0;
        for (int len : arr) {
            if (currSum + len <= maxTime) {
                currSum += len;
            } else {
                painters++;
                currSum = len;
                if (painters > k) return false;
            }
        }
        return true;
    }

    int minTime(vector<int>& arr, int k) {
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canPaint(arr, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};