class Solution {
  public:
    int f(int x, int A, int B, int C) {
        return A * x * x + B * x + C;
    }

    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        int n = arr.size();
        vector<int> result(n);
        int left = 0, right = n - 1;
        int index = (A >= 0) ? n - 1 : 0;

        while (left <= right) {
            int leftVal = f(arr[left], A, B, C);
            int rightVal = f(arr[right], A, B, C);

            if (A >= 0) {
                if (leftVal > rightVal) {
                    result[index--] = leftVal;
                    left++;
                } else {
                    result[index--] = rightVal;
                    right--;
                }
            } else {
                if (leftVal < rightVal) {
                    result[index++] = leftVal;
                    left++;
                } else {
                    result[index++] = rightVal;
                    right--;
                }
            }
        }
        return result;
    }
};
