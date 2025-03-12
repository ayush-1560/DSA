class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int l=0,r=1;
        int temp=0;
        int ans=0;
        while(temp!=k-1){
            colors.push_back(colors[temp]);
            temp++;
        }
        int N= n+k-1;
        int length =1;
        for(int i=1;i<N;i++){
            if(colors[i]==colors[i-1]) length=1;
            else length++;
            if(length>=k) {
                ans++;
            }
        }
        return ans;
    }
};