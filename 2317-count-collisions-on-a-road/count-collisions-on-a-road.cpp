class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int collisions=0;
        int i=0,j=n-1;
        while(i<n && directions[i]=='L') i++;
        while(j>=0 && directions[j]=='R') j--;
        for(int t=i;t<=j;t++){
            if(directions[t]=='L' || directions[t]=='R'){
                collisions++;
            }
        }
        return collisions;
    }
};