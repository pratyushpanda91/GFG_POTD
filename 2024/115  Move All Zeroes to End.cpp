class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int j = 0; // Position for next non-zero element
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                swap(arr[j], arr[i]);
                j++;
            }
        }
    }
};
