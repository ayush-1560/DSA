class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i=0,idx=0;
        while(i<n){
            char ch = chars[i];
            int count=0;
            while(i<n && chars[i]==ch){
                i++;
                count++;
            }
            chars[idx]=ch;
            idx++;
            if(count>1){
                string count_str = to_string(count);
                for(char ch : count_str){
                    chars[idx]=ch;
                    idx++;
                }
            }
        }
        return idx;
    }
};