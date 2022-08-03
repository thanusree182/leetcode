class Solution {
public:
    char repeatedCharacter(string s) {
        map <char,int> a;
        for(int i=0;i<s.length();i++){
            a[s[i]]++;
            if(a[s[i]]>1){
                return s[i];
            }
        }
        return '-1';
    }
};