class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return 0;
        }
        int help[26]={};
        for(int i=0;i<s.size();i++){
            help[s[i]-'a']++;
            help[t[i]-'a']--;
        }
        
    
        for(int i=0;i<26;i++){
            if(help[i] ){
               return 0;
            }
        }
        return 1;
    }
};