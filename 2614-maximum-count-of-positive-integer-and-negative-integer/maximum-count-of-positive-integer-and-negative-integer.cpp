class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int negative=0,positive=0;
        for(auto ele : nums){
            if(ele<0) negative++;
            else if(ele>0) positive++;
        }
        return max(negative,positive);
    }
};