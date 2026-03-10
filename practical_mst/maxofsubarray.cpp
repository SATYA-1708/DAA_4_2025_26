class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
      
      int n=arr.size();
     vector<int> b;

     for (int i=0;i<=n-k;i++) {
            int maximum=arr[i];
            for (int j=i;j<i+k;j++) {
                if(maximum<arr[j])
                maximum=arr[j];
            }
            b.push_back(maximum);
        }
    return b;
    }
};




