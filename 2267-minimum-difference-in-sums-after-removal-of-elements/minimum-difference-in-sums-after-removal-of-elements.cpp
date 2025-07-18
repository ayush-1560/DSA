class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int n = N/3;
        vector<long long>minLeftSum(N,0);
        vector<long long>maxRightSum(N,0);
        priority_queue<int>maxHeap;
        priority_queue<int,vector<int>,greater<>>minHeap;
        long long leftSum=0;
        long long rightSum=0;
        for(int i=0;i<2*n;i++){
            maxHeap.push(nums[i]);
            leftSum+=nums[i];
            if(maxHeap.size()>n){
                leftSum-=maxHeap.top();
                maxHeap.pop();
            }
            minLeftSum[i]=leftSum;
        }
        for(int i=N-1;i>=n;i--){
            minHeap.push(nums[i]);
            rightSum+=nums[i];
            if(minHeap.size()>n){
                rightSum-=minHeap.top();
                minHeap.pop();
            }
            maxRightSum[i]=rightSum;
        }
        long long minDiff=LLONG_MAX;
        for(int i=n-1;i<=2*n-1;i++){
            minDiff= min(minDiff,minLeftSum[i]-maxRightSum[i+1]);
        }
        return minDiff;
    }
};