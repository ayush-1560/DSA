class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ops = 0;
        for(int num : nums){
            if(num==1) ops++;
            else if(num%3==0) continue;
            else {
                int x=num;
                while(x%3!=0){
                    x++;
                }
                int y = num;
                while(y>0 && y%3!=0) y--;
                ops+=min((x-num),(num-y));
            }
        }
        return ops;
    }
};