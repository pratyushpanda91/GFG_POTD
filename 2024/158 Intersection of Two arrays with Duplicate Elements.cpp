class Solution {
  public:
    vector<int> findIntersection(vector<int> &a, vector<int> &b) {
        unordered_set<int> setA(a.begin(), a.end());
        unordered_set<int> result;

        for (int num : b) {
            if (setA.count(num)) {
                result.insert(num);
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};
