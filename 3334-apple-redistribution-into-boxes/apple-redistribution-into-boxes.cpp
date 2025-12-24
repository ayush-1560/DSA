class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum1 = accumulate(apple.begin(),apple.end(),0);
        int sum2 = accumulate(capacity.begin(),capacity.end(),0);
        sort(capacity.begin(),capacity.end(),greater<int>());
        int ans = 0;
        int i=0;
        while(i<capacity.size() && sum1>0){
            sum1-=capacity[i];
            ans++;
            i++;
        }
        return ans;
    }
};