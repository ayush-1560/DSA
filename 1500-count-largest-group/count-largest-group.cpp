class Solution {
public:
    int sumD(int n){
        int sum =0;
        while(n>0){
            sum+=(n%10);
            n/=10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int,int>mp;
        int groups =0;
        int maxGroup =0;
        for(int i = 1;i<=n ; i++){
            mp[sumD(i)]++;
            if(mp[sumD(i)]==maxGroup){
                groups++;
            }
            else if(mp[sumD(i)]>maxGroup){
                maxGroup = mp[sumD(i)];
                groups=1;
            }
        }
        
        return groups;
    }
};