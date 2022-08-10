class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> codes={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> help;
        for(auto word:words){
            string c="";
            for(auto ch:word){
                c+=codes[ch-97];
            }
            help.insert(c);
        }
        return help.size();
    }
};