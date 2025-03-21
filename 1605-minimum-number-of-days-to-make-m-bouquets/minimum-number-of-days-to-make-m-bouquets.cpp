class Solution {
public:
    int countBloom(vector<int>& bloomDay, int k, int day){
        int count =0;
        int currCount =0;
        for(int& ele : bloomDay){
            if(ele<=day) currCount++;
            else currCount=0;
            if(currCount==k) {
                count++;
                currCount=0;
            }
        }
        return count;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 0, high = *max_element(begin(bloomDay),end(bloomDay));
        if((long long)m*k>bloomDay.size()) return -1;
        int ans = high;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(countBloom(bloomDay,k,mid)>=m){
                ans=mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};