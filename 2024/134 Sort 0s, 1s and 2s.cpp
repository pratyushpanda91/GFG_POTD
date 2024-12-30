class Solution {
  public:
    void sort012(vector<int>& arr) {
        int zero=0, two=arr.size()-1;
        for(int i=0; i<=two; i++){
            if(arr[i]==0) swap(arr[i],arr[zero++]);
            if(arr[i]==2) {swap(arr[i],arr[two--]); i--;}
        }
}
};
