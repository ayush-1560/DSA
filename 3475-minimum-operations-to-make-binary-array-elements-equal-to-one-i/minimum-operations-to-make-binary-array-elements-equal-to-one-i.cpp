class Solution {
public:
    int solve(vector<int>& nums,int k){
        int n = nums.size();
        vector<bool>isFlipped(n,false);
        int currFlip=0;
        int flips =0;
        for(int i=0;i<n;i++){
            if(i>=k && isFlipped[i-k]==true){
                currFlip--;
            }
            if(currFlip%2==nums[i]) {
                if(i+k>n) return -1;
                currFlip++;
                flips++;
                isFlipped[i]=true;
            }
        }
        return flips;
    }
    int minOperations(vector<int>& nums) {
        return solve(nums,3);
    }
};