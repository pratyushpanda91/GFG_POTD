class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
        int n = arr.size();
        unordered_map<int, int> freq;

      
        for (int num : arr) {
            freq[num]++;
        }

        vector<int> res(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            int currFreq = freq[arr[i]];


            while (!st.empty() && freq[arr[st.top()]] <= currFreq) {
                st.pop();
            }

            if (!st.empty()) {
                res[i] = arr[st.top()];
            }

            
            st.push(i);
        }

        return res;
    }
};
