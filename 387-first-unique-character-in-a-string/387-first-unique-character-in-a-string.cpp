class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> help;
        for(int i=0;i<s.length();i++){
            help[s[i]]++;
        }
        for(int i=0;i<s.length();i++){
            if(help[s.at(i)]==1)
                return i;
        }
        
        return -1;
    }
};