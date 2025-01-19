class Solution {
public:
    int trap(vector<int>& height) {
      int n=height.size();
      vector<int>left_max(n,INT_MIN);
      vector<int>right_max(n,INT_MIN);
      left_max[0]=height[0];
      int maxi=height[0];
      right_max[n-1] = height[n-1];
      int maxi2=height[n-1];
      for(int i=1;i<n;i++){
        maxi=max(maxi,height[i]);
        left_max[i]=maxi;
      }
      for(int i=n-2;i>=0;i--){
        maxi2=max(maxi2,height[i]);
        right_max[i]=maxi2;
      }
      int ans=0;
      for(int i=1;i<=n-2;i++){
         ans+=min(left_max[i],right_max[i]) - height[i];
      }
      return ans;
    }
};