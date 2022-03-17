class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int val=0;
        for(auto i:s){
            if(i=='('){
                st.push(val);
                val=0;
            }
            else{
                val=st.top()+max(2*val,1);
                st.pop();
    
            }
        }
        return val;
    }
};