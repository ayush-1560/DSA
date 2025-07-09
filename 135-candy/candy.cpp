class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candies = n;
        int i=1;
        while(i<n){
            int peak =0;
            if(ratings[i]==ratings[i-1]) {
                i++;
                continue;
            }
            while(ratings[i] > ratings[i-1]){
                peak++;
                i++;
                candies+=peak;
                if(i==n) return candies;
            }
            int dip =0;
            while(i<n && ratings[i]<ratings[i-1]){
                i++;
                dip++;
                candies+=dip;
            }
            candies-=min(dip,peak);
        }
        return candies;
    }
};