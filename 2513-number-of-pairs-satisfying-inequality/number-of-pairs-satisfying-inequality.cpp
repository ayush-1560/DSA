class Solution {
public:
    long long countPairs(vector<int>&delta,int left, int mid , int right,int diff){
        long long count = 0;
        int l=left,r=mid+1;
        while(l<=mid && r<=right){
            if(delta[l]<=delta[r]+diff){
                count+=(right-r+1);
                l++;
            }
            else r++;
        }
        int i=left,k=0;
        int j=mid+1;
        vector<int>temp(right-left+1);
        while(i<=mid && j<=right){
            if(delta[i]<=delta[j]){
                temp[k++] = delta[i++];
            }
            else temp[k++] = delta[j++];
        }
        while(i<=mid){
            temp[k++] = delta[i++];
        }
        while(j<=right){
            temp[k++] = delta[j++];
        }
        for(int i=left;i<=right;i++){
            delta[i] = temp[i-left];
        }
        return count;
    }
    long long mergeAndCount(vector<int>&delta,int left, int right,int diff){
        if(left >=right) return 0;
        long long count =0;
        int mid = left + (right-left)/2;
        count+=mergeAndCount(delta,left,mid,diff);
        count+=mergeAndCount(delta,mid+1,right,diff);
        count+=countPairs(delta,left,mid,right,diff);
        return count;
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n=nums1.size();
        vector<int>delta(n);
        for(int i=0;i<n;i++){
            delta[i] = nums1[i] -nums2[i];
        }
        return mergeAndCount(delta,0,n-1,diff);
    }
};