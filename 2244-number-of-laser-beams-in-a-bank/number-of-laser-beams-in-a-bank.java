class Solution {
    public int numberOfBeams(String[] bank) {
        int prev =0;
        int ans = 0;
        int n = bank.length;
        for(int i=0;i<n;i++){
            int curr = 0;
            for(char ch : bank[i].toCharArray()){
                if(ch=='1') curr++;
            }
            ans+=curr*prev;
            prev = curr!=0 ? curr : prev;
        }
        return ans;
    }
}