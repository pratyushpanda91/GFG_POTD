class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        int n=s.length();
        stack<char>st;
        for(int i=0; i<n; i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }else if(s[i]==')'){
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }else return 0;
            }
            else if(s[i]=='}'){
                if(!st.empty() && st.top()=='{'){
                    st.pop();
                }else return 0;
            }
            else if(s[i]==']'){
                if(!st.empty() && st.top()=='['){
                    st.pop();
                }else return 0;
            }
        }
        return st.empty();
    }
};
