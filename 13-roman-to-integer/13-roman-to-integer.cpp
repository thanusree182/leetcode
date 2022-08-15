class Solution {
public:
    int romanToInt(string s) {
        map<char,int> help={
            { 'I', 1 },
            { 'V', 5 },
            { 'X', 10 },
            { 'L', 50 },
            { 'C', 100 },
            { 'D', 500 },
            { 'M', 1000 }
        };
        int prev=0,result=0;
        for(int i=s.length()-1;i>=0;i--){
            int curr=help.find(s[i])->second;
            if(prev<=curr){
                result+=curr;
            }
            else{
                result-=curr;
            }
            prev=curr;
        }
        return result;
    }
};