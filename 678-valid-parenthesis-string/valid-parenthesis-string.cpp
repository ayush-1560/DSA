class Solution {
public:
    bool checkValidString(string s) {
        stack<int>openSt,astSt;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                openSt.push(i);
            }
            else if(s[i]=='*'){
                astSt.push(i);
            }
            else{
                if(!openSt.empty()){
                    openSt.pop();
                }
                else if(!astSt.empty()){
                    astSt.pop();
                }
                else return false;
            }
        }
        while(!openSt.empty() && !astSt.empty()){
            if(openSt.top() > astSt.top()) return false;
            openSt.pop();
            astSt.pop();
        }
        return openSt.empty();
    }
};