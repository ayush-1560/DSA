class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int x=0;
        for(int ele : derived) x^=ele;
        return(!x);
    }
};