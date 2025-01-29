class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int assumedElement = nums[0];
        int count =1;
        for(int i=0;i<n;i++){
            if(nums[i]==assumedElement){
                count++;
            }
            else count--;
            if(count==0){
                assumedElement = nums[i];
                count=1;
            }
        }
        count =0;
        for(int i=0;i<n;i++){
            if(nums[i]==assumedElement) count++;
        }
        if (count>=(n/2)) return assumedElement;
        return -1;
    }
};