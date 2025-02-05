class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
        int n = s1.length();
        int misCount=0;
        int idx1=-1,idx2=-1;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]) {
                if(idx1==-1){
                    idx1=i;
                }
                else idx2=i;
                misCount++;
            }
        }
        if(misCount!=2) return false;
        swap(s2[idx1],s2[idx2]);
        return (s1==s2);
    }
};