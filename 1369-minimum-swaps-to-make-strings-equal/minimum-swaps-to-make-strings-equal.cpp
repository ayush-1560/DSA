class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n = s1.length();
        int xy =0, yx=0;
        for(int i=0;i<n;i++){
            if(s1[i]=='x' && s2[i]=='y') xy++;
            else if(s1[i]=='y' && s2[i]=='x') yx++;
        }
        if((xy+yx)%2!=0) return -1;
        return xy/2 + yx/2 + (xy%2)*2;
    }
};