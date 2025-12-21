class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();
        int deletions = 0;
        vector<bool>alreadySorted(m,false);
        for(int col = 0 ; col<n;col++){
            bool deleted = false;
            for(int row = 0;row<m-1;row++){
                if(!alreadySorted[row] && strs[row][col]>strs[row+1][col]){
                    deletions++;
                    deleted = true;
                    break;
                }
            }
            if(deleted) continue;
                for(int i=0;i<m-1;i++){
                    alreadySorted[i] = alreadySorted[i] | (strs[i][col]<strs[i+1][col]);
                }
        }
        return deletions;
    }
};