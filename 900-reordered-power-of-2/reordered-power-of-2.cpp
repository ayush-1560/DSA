class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_set<string>st;
        for(int i=1;i<=1e9;i<<=1){
            string str = to_string(i);
            sort(str.begin(),str.end());
            st.insert(str);
        }
        string str2 = to_string(n);
        sort(str2.begin(),str2.end());
        return st.count(str2);
    }
};