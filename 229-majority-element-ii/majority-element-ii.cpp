class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ele1 = NULL;
        int count1=0;
        int ele2= NULL;
        int count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele1) count1++;
            else if(nums[i]==ele2) count2++;
            else if(count1==0){
                ele1=nums[i];
                count1=1;
            }
            else if(count2==0){
                ele2=nums[i];
                count2=1;
            }
            else {
                count1--;
                count2--;
            }
        }
        vector<int>ans;
        count1=0,count2=0;
        for(int num : nums){
            if(num==ele1) count1++;
            else if(num==ele2) count2++;
        }
        if(count1>floor(n/3)) ans.push_back(ele1);
        if(count2>floor(n/3)) ans.push_back(ele2);
        return ans;
    }
};