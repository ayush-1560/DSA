class Solution {
public:

    void updateFreq(int op, int val, vector<int>& v) {
        for(int i=0;i<32;i++){
            if((val>>i)&1){
                v[i]+=op;
            }
        }
    }

    int minimumDifference(vector<int>& nums, int k) {
        vector<int> freqBits(32, 0);
        int n = nums.size();
        
        int i = 0, j = 0;
        int windowOr = 0;
        int result = INT_MAX;

        while (j < n) {
            windowOr |= nums[j];
            updateFreq(1, nums[j], freqBits);
            result = min(result, abs(k - windowOr));
            if (windowOr < k) {
                j++;
            } else if (windowOr == k) {
                return 0;
            } else {  
                while (i < j && windowOr > k) {
                    updateFreq(-1, nums[i], freqBits);
                    i++;
                    
                    windowOr = 0;
                    for (int b = 0; b < 32; b++) {
                        if (freqBits[b] > 0) {
                            windowOr |= (1 << b);
                        }
                    }
                    result = min(result, abs(k - windowOr));
                }
                j++;
            }
        }

        return result;
    }
};
