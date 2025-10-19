class Solution {
public:
    string rotate(string& s,int b){
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin() + b);
        reverse(s.begin() + b, s.end());
        return s;
    }
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size(); 
        string ans = s;
        queue<string>q;
        unordered_set<string>visited;
        q.push(s);
        while(!q.empty()){
            string str = q.front();
            q.pop();
            ans = min(str,ans);
            string temp = str;
            for(int i=1;i<str.length();i+=2){
                temp[i] = ((temp[i]-'0' + a)%10) + '0';
            }
            if(!visited.count(temp)) q.push(temp);
            visited.insert(temp);
            rotate(str,b);
            if(!visited.count(str)) q.push(str);
            visited.insert(str);
        }
        return ans;
    }
};