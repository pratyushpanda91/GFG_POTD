class Solution {
  public:
     int majorityElement(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end());
        if(arr.size()%2 != 0)
        {
            for(int i = 0; i <= (arr.size())/2; i++)
            {
                if(arr[i] == arr[i + arr.size()/2])
                    return arr[i];
            }
        }
        else
        {
            for(int i = 0; i < (arr.size())/2; i++)
            {
                if(arr[i] == arr[i + arr.size()/2])
                    return arr[i];
            }
            
        }
        return -1;
    }
};
