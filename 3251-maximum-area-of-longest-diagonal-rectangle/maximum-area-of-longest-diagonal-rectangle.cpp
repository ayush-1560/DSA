class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea=0;
        int diagSofar=0;
        for(auto dim : dimensions){
            int diagLen = dim[0]*dim[0] + dim[1]*dim[1];
            if(diagLen>diagSofar){
                diagSofar = diagLen;
                maxArea = dim[0]*dim[1];
            }
            else if(diagLen ==diagSofar){
                maxArea = max(maxArea,dim[0]*dim[1]);
            }
        }
        return maxArea;
    }
};