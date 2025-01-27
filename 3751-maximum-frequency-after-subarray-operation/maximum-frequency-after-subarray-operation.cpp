class Solution {
public:
    int calcmaxGain(vector<int>& nums,int value,int k){ //kadane's
        int maxGain =0,currGain=0;
        for(int num : nums){
            if(num==k) currGain--;
            if(num==value) currGain++;
            if(currGain<0) currGain=0;
            maxGain = max(maxGain,currGain);
        }
        return maxGain;
    }
    int maxFrequency(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(auto ele : nums) freq[ele]++;
        int maxFreq=0;
        for(auto it : freq){
            maxFreq = max(maxFreq,calcmaxGain(nums,it.first,k));
        }
        return maxFreq+freq[k];
    }
};