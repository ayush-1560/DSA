class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> allOrs, curr;
        
        for (int num : arr) {
            unordered_set<int> newCurr;
            newCurr.insert(num);
            
            for (int x : curr) {
                newCurr.insert(x | num);
            }
            
            curr = newCurr;
            allOrs.insert(curr.begin(), curr.end());
        }

        return allOrs.size();
    }
};
