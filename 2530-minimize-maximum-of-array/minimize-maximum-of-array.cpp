class Solution {
public:
    bool isValid(vector<int> nums,long long expected_max){
        vector<long long>arr(begin(nums),end(nums));
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]>expected_max) return false;
            long long buffer = expected_max -arr[i];
            arr[i+1]-= buffer; 
        }
        return (arr[arr.size()-1]<=expected_max);
    }
    int minimizeArrayValue(vector<int>& nums) {
        long long low = 0, high = *max_element(nums.begin(),nums.end());
        while(low<=high){
            long long mid = low + (high-low)/2;
            if(isValid(nums,mid)){
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
    }
};