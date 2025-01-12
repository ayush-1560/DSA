class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.length()%2!=0) return false;
        stack<int>open;
        stack<int>openClose;
        for(int i=0;i<s.length();i++){
            if(locked[i]=='0'){
                openClose.push(i);
            }
            else{
                if(s[i]=='(') open.push(i);
                else{
                    if(open.empty() && openClose.empty()) return false;
                    else{
                        if(!open.empty()) open.pop();
                        else if(!openClose.empty()) openClose.pop();
                    }
                }
            }
        }
        while(!open.empty() && !openClose.empty() && open.top() < openClose.top()){
            open.pop();
            openClose.pop();
        }
        if(!open.empty()) return false;
        return true;
    }
};