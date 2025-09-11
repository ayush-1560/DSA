class Solution {
public:
    bool isVowel(char ch){
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' ||ch=='u'
        ||ch=='A' or ch=='E' or ch=='I' or ch=='O' or ch=='U');
    }
    string sortVowels(string s) {
        int n = s.length();
        string t = s;
        vector<char>v;
        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                v.push_back(s[i]);
                t[i]='.';
            }
        }
        sort(v.rbegin(),v.rend());
        for(int i=0;i<n;i++){
            if(t[i]=='.' && !v.empty()){
                t[i]=v.back();
                v.pop_back();
            }
        }
        return t;
    }
};