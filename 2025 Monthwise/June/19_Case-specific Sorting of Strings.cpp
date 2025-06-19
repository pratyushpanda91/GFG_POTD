class Solution {
  public:
    string caseSort(string& s) {
        string temp = s;
        sort(temp.begin(),temp.end());
        int j = 0;
        int i = 0;
        for(int k = 0; k < temp.size(); k++){
            if(islower(temp[k])){
                i = k;
                break;
            }
        }
        int k = 0;
        while(k < s.size()){
            if(isupper(s[k])){
                s[k] = temp[j];
                j++;
            }
            else{
                s[k] = temp[i];
                i++;
            }
            k++;
        }
        return s;
    }


};class Solution {
  public:
    string caseSort(string& s) {
        string temp = s;
        sort(temp.begin(),temp.end());
        int j = 0;
        int i = 0;
        for(int k = 0; k < temp.size(); k++){
            if(islower(temp[k])){
                i = k;
                break;
            }
        }
        int k = 0;
        while(k < s.size()){
            if(isupper(s[k])){
                s[k] = temp[j];
                j++;
            }
            else{
                s[k] = temp[i];
                i++;
            }
            k++;
        }
        return s;
    }


};
