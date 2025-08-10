class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_set<string>st;
        for(int i=0;i<=29;i++){
            string str = to_string(1<<i);
            sort(str.begin(),str.end());
            st.insert(str);
        }
        string str2 = to_string(n);
        sort(str2.begin(),str2.end());
        return st.count(str2);
    }
};