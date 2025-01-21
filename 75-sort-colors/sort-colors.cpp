class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroes=0,ones=0,twos=0;
        for(int x : nums){
            if(x==0) zeroes++;
            else if(x==1) ones++;
            else twos++;
        }
        int idx=0;
        while(idx<nums.size()){
            while(zeroes--){
                nums[idx]=0;
                idx++;
            }
            while(ones--){
                nums[idx]=1;
                idx++;
            }
            while(twos--){
                nums[idx]=2;
                idx++;
            }
        }
    }
};