class Solution {
public:
    char kthCharacter(int k) {
        string str = "a";
        string gen = "b";
        while(str.length()<k){
            str+=gen;
            string temp="";
            for(char ch : gen){
                temp+=(ch == 'z') ? 'a' : ch + 1;
            }
            gen+=temp;
        }
        return str[k-1];
    }
};