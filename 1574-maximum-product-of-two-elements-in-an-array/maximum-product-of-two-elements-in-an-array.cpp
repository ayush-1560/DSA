class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxElement = -1, smaxElement = -1;
        for(int num : nums){
            if(num > maxElement){
                smaxElement = maxElement;
                maxElement = num;
            }
            else if(num > smaxElement){
                smaxElement = num;
            }
        }

        return (maxElement-1)*(smaxElement-1);
    }
};