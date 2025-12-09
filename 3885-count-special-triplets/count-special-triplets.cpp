class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int>mp_right;
        unordered_map<int,int>mp_left;
        int MOD = 1e9+7;
        for(int& num : nums) mp_right[num]++;
        int cnt=0;
        for(int& num : nums){
            mp_right[num]--;
            cnt = (cnt + (1LL*mp_left[num*2]* mp_right[num*2]))%MOD;
            mp_left[num]++;
        }
        return cnt%MOD;
    }
};