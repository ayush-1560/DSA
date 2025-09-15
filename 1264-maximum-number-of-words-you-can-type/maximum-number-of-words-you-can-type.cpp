class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss(text);
        string word;
        int words = 0;
        while(ss>>word){
            bool canType=true;
            for(char ch : word){
                if(brokenLetters.find(ch)!=string::npos){
                    canType = false;
                    break;
                }
            }
            if(canType) words++;
        }
        return words;
    }
};