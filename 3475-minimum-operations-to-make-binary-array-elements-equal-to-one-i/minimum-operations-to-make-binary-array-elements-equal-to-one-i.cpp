class Solution {
public:
    int solve(vector<int>& nums,int k){
        int n = nums.size();
        int currFlip=0;
        int flips =0;
        for(int i=0;i<n;i++){
            if(i>=k && nums[i-k]==5){
                currFlip--;
            }
            if(currFlip%2==nums[i]) {
                if(i+k>n) return -1;
                currFlip++;
                flips++;
                nums[i]=5;
            }
        }
        return flips;
    }
    int minOperations(vector<int>& nums) {
        return solve(nums,3);
    }
};