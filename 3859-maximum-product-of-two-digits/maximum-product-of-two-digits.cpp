class Solution {
public:
    int maxProduct(int n) {
        string str = to_string(n);
        sort(str.begin(),str.end());
        int x = str[str.size()-1]-'0';
        int y = str[str.size()-2]-'0';
        return x*y;
    }
};