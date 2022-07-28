class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return 0;
        }
        unordered_map<char,int> a;
        for(int i=0;i<s.length();i++){
            a[s[i]]++;
            a[t[i]]--;
        }
        for(auto i:a){
            if(i.second){
                return 0;
            }
        }
        return 1;
    }
};