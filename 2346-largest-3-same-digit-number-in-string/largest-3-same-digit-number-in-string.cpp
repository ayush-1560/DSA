class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.length();
        int maxNum=INT_MIN;
        string ans="";
        for(int i=1;i<n-1;i++){
            if(num[i]==num[i-1] && num[i]==num[i+1]){
                if(stoi(num.substr(i-1,3))>maxNum){
                    maxNum=stoi(num.substr(i-1,3));
                    ans=num.substr(i-1,3);
                }
            }
        }
        return ans;
    }
};