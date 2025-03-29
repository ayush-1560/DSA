class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int totalXor = 0;
        for(auto ele : derived) totalXor^=ele;
        return (totalXor==0);
    }
};