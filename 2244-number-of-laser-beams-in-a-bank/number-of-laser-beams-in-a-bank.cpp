class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int prev=0;
        int ans = 0;
        for(string row : bank){
            int curr = 0;
            for(char ch : row){
                if(ch=='1') curr++;
            }
            ans+=(curr*prev);
            prev = curr!=0 ? curr : prev;
        }
        return ans;
    }
};