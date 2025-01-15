class Solution {
public:
    void merge(vector<int>& nums,vector<int>&indices,vector<int>&ans,int left, int mid, int right){
        vector<int>temp(right-left +1);
        int i=left,j=mid+1,k=0,rightCount =0;
        while(i<=mid && j<=right){
            if(nums[indices[j]]<nums[indices[i]]){
                temp[k++] = indices[j++];
                rightCount++;
            }
            else{
                ans[indices[i]]+=rightCount;
                temp[k++] = indices[i++];
            }
        }
        while(i<=mid){
            ans[indices[i]]+=rightCount;
            temp[k++] = indices[i++];
        }
        while(j<=right){
            temp[k++] = indices[j++];
        }
        for(int p=0;p<temp.size();p++){
            indices[left+p]=temp[p];
        }
    }
    void mergeSort(vector<int>& nums,vector<int>&indices,vector<int>&ans,int left, int right){
        if(left >= right) return;
        int mid = left + (right-left)/2;
        mergeSort(nums,indices,ans,left,mid);
        mergeSort(nums,indices,ans,mid+1,right);
        merge(nums,indices,ans,left,mid,right);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,0);
        vector<int>indices(n,0);
        for(int i=0;i<n;i++) indices[i] = i;
        mergeSort(nums,indices,ans,0,n-1);
        return ans;
    }
};