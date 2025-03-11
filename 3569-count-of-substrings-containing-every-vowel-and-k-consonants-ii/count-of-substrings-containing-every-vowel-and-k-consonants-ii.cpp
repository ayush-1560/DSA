class Solution {
public:
    bool isVowel(char ch){
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }
    long long countOfSubstrings(string word, int k) {
       int n = word.length();
       unordered_map<char,int>mp;
       vector<int>nextCons(n);
       int lastConstIdx = n;
       for(int i=n-1;i>=0;i--){
          nextCons[i]=lastConstIdx;
          if(!isVowel(word[i])){
             lastConstIdx = i;
          }
       }
       long long ans=0;
       int l=0,r=0,constCount=0;
       while(r<n){
         if(isVowel(word[r])) mp[word[r]]++;
         else constCount++;
         while(constCount > k){
            if(isVowel(word[l])){
                mp[word[l]]--;
                if(mp[word[l]]==0) mp.erase(word[l]);
            }
            else constCount--;
            l++;
         }
         while(l<n && mp.size()==5 && constCount==k){
            int idx = nextCons[r];
            ans+=idx-r;
            if(isVowel(word[l])){
                mp[word[l]]--;
                if(mp[word[l]]==0) mp.erase(word[l]);
            }
            else constCount--;
            l++;
         }
         r++;
       }
       return ans;
    }
};