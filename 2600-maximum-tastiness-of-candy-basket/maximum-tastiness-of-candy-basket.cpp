class Solution {
public:
    bool canPlace(vector<int>& price, int k,int dist){
        int count =1, last= price[0];
        for(int i=1;i<price.size();i++){
            if(price[i] - last >= dist){
                count++;
                last=price[i];
            }
        }
        return count>=k;
    }
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        sort(price.begin(),price.end());
        int low =1 , high = price[n-1]-price[0];
        int ans = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(canPlace(price,k,mid)) {
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};