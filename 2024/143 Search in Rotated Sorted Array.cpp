class Solution {
public:
    int search(vector<int>& arr, int key) {
        int left = 0, right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == key) 
                return mid;

            // Check if the left half is sorted
            if (arr[left] <= arr[mid]) {
                if (key >= arr[left] && key < arr[mid]) 
                    right = mid - 1; // Key lies in the left sorted half
                else 
                    left = mid + 1;  // Key lies in the right half
            } 
            // Otherwise, the right half is sorted
            else {
                if (key > arr[mid] && key <= arr[right]) 
                    left = mid + 1;  // Key lies in the right sorted half
                else 
                    right = mid - 1; // Key lies in the left half
            }
        }

        return -1; // Key not found
    }
};
