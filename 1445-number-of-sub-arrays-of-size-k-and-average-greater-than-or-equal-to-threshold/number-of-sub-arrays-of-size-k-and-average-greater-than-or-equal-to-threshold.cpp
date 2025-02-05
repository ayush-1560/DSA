class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int l=0,r=0,count=0;
        int sum=0;
        while(r<n){
            sum+=arr[r];
            if((r-l+1)>k){
                sum-=arr[l];
                l++;
            }
            if((r-l+1)==k){
                int avg=sum/(r-l+1);
                if(avg>=threshold) count++;
            }
            r++;
        }
        return count;
    }
};