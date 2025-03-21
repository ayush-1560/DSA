class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m>n)  return findMedianSortedArrays(nums2,nums1);
        int l = 0, r=m;
        while(l<=r){
            int Px = l + (r-l)/2;
            int Py = ((m+n+1)/2) - Px;
            int x1 = (Px==0) ? INT_MIN : nums1[Px-1];
            int x2 = (Py==0) ? INT_MIN : nums2[Py-1];
            int x3 = (Px==m) ? INT_MAX : nums1[Px];
            int x4 = (Py==n) ? INT_MAX : nums2[Py];
            if(x1<=x4 && x2<=x3){
                if((m+n)%2==1){
                    return max(x1,x2);
                }
                else return (max(x1,x2) + min(x3,x4))/2.0;
            }
            if(x1>x4) r = Px-1;
            else l = Px+1;
        }
        return -1;
    }
};