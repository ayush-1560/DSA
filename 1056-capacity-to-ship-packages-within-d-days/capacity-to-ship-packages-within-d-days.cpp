class Solution {
public:
    bool isPossible(vector<int>& weights, int days,int cap){
        int load=0, day =1;
        for(int i=0;i<weights.size();i++){
            if(load + weights[i]>cap){
                day++;
                load = weights[i];
            }
            else load+=weights[i];
        }
        return day<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low =*max_element(weights.begin(),weights.end())
        ,high = accumulate(weights.begin(),weights.end(),0);
        int ans = high;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(isPossible(weights,days,mid)){
                ans=mid;
                high=mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};