class Solution {
public:
    bool check(vector<int> nums, long long  mid) {
    int n = nums.size();
    vector<long long>arr(begin(nums),end(nums));
    for (int i = 0; i <= n - 2; i++) {
        if(arr[i] > mid) return false;
        arr[i + 1] -= mid-arr[i];
    }
    return arr[n - 1] <= mid;
}
    int minimizeArrayValue(vector<int>& nums) {
        int l = 0;
        int r = *max_element(nums.begin(),nums.end());
        while(l<=r){
            long long mid = l+(r-l)/2;
            if(check(nums,mid)) r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};