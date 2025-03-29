class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int xor1= 0 , xor2=0;
        for(auto ele : arr1) xor1^=ele;
        for(auto ele : arr2) xor2^=ele;
        return xor1&xor2;
    }
};