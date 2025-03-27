class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int bit =0 ; bit<=31;bit++){
            int temp = (1<<bit);
            int ones = 0;
            for(int num : nums){
                if((num & temp)!=0) ones++;
            }
            if(ones%3==1) ans = (ans | temp);
        }
        return ans;
    }
};