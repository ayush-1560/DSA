class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int minPushes = 0;
        for(int i=0;i<n;i++){
            int factor = (i/8) + 1;
            minPushes+=factor;
        }
        return minPushes;
    }
};