class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char>st(brokenLetters.begin(),brokenLetters.end());
        stringstream ss(text);
        string word;
        int words = 0;
        while(ss>>word){
            bool canType=true;
            for(char ch : word){
                if(st.count(ch)){
                    canType = false;
                    break;
                }
            }
            if(canType) words++;
        }
        return words;
    }
};