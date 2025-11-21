class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char>st;
        for(char ch : s) st.insert(ch);
        int count=0;
        for(char ch : st){
            int left_idx=-1,right_idx=-1;
            for(int i=0;i<s.length();i++){
                if(s[i]==ch){
                    if(left_idx==-1){
                        left_idx=i;
                    }
                    right_idx=i;
                }
            }
            unordered_set<char>ans;
            for(int mid=left_idx+1;mid<=right_idx-1;mid++){
                ans.insert(s[mid]);
            }
            count+=ans.size();
        }
        return count;
    }
};