class Solution {
public:
    bool isVowel(char ch){
        return (ch=='a' || ch=='e'|| ch=='i'|| ch=='o'||ch=='u'
        ||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U');
    }
    bool isValid(string word) {
        if(word.length()<3) return false;
        bool hasVowel =false,hasConst =false;
        for(char ch : word){
            if(!isalnum(ch)) return false;
            if(isVowel(ch)) hasVowel=true;
            else if( isalpha(ch) &&  !isVowel(ch)) hasConst=true;
        }
        return (hasVowel && hasConst);
    }
};