class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int cnt=0;
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            bool isAssigned = false;
            for(int j=0;j<n;j++){
                if(!st.count(j) && baskets[j]>=fruits[i]){
                    st.insert(j);
                    isAssigned = true;
                    break;
                }
            }
            if(!isAssigned) cnt++;
        }
        return cnt;
    }
};