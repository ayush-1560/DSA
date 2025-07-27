class Solution {
public:
    bool isPeakOrValley(int a, int b, int c){
        return (b > a && b > c) || (b < a && b < c);
    }

    int countHillValley(vector<int>& nums) {
        vector<int> arr;
        arr.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i-1])
                arr.push_back(nums[i]);
        }

        int cnt = 0;
        for(int i = 1; i < arr.size() - 1; i++){
            if(isPeakOrValley(arr[i-1], arr[i], arr[i+1]))
                cnt++;
        }
        return cnt;
    }
};
