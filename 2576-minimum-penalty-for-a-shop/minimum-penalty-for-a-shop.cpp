class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        vector<int>yes(n,0);
        vector<int>no(n,0);
        yes[0] = customers[0]=='Y' ? 1 : 0;
        no[0] = customers[0]=='N' ? 1 : 0;
        for(int i=1;i<n;i++){
            yes[i] += yes[i-1] + (customers[i]=='Y' ? 1 : 0);
            no[i] += no[i-1] + (customers[i]=='N' ? 1 : 0);
        }
        int minPenalty=INT_MAX;
        int minTime = INT_MAX;
        for(int i = 0; i <= n; i++) {
    int forwardPenalty = (i < n ? yes[n-1] - (i > 0 ? yes[i-1] : 0) : 0);
    int backwardPenalty = (i > 0 ? no[i-1] : 0);

    if(forwardPenalty + backwardPenalty < minPenalty) {
        minPenalty = forwardPenalty + backwardPenalty;
        minTime = i;
    }
}
return minTime;
    }
};