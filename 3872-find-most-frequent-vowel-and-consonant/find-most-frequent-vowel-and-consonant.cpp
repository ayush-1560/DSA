class Solution {
public:
    bool isVowel(char ch){
        return string("aeiou").find(ch)!=string :: npos;
    }
    int maxFreqSum(string s) {
        vector<int>freq(26,0);
        for(char ch : s) freq[ch-'a']++;
        int vowelFreq=0,constFreq=0;
        for(int i=0;i<26;i++){
            if(isVowel('a' + i)){
                vowelFreq=max(vowelFreq,freq[i]);
            }
            else constFreq = max(constFreq,freq[i]);
        }
        return vowelFreq + constFreq;
    }
};