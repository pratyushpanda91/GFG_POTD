class Solution {
  public:
    // Function to return the count of number of elements in the union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        unordered_set<int> unionSet;

        // Insert elements of the first array into the set
        for (int num : a) {
            unionSet.insert(num);
        }

        // Insert elements of the second array into the set
        for (int num : b) {
            unionSet.insert(num);
        }

        // The size of the set gives the count of unique elements in the union
        return unionSet.size();
    }
};
