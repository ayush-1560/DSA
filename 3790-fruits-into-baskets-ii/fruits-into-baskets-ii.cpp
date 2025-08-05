class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            bool isAssigned = false;
            for(int j=0;j<n;j++){
                if(baskets[j]>=fruits[i]){
                    baskets[j]=0;
                    isAssigned = true;
                    break;
                }
            }
            if(!isAssigned) cnt++;
        }
        return cnt;
    }
};