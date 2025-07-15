class Solution {
public:
    bool isVowel(char ch){
        return (ch=='a' || ch=='e'|| ch=='i'|| ch=='o'||ch=='u'
        ||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U');
    }
    bool isValid(string word) {
        if(word.length()<3) return false;
        int cntVowel=0,cntConst=0;
        for(char ch : word){
            if(!isalnum(ch)) return false;
            if(isVowel(ch)) cntVowel++;
            else if( isalpha(ch) &&  !isVowel(ch)) cntConst++;
        }
        return (cntVowel>0 && cntConst>0);
    }
};