class Solution {
public:
    char getNext(char ch) {
    return (ch == 'z') ? 'a' : ch + 1;
    }
    char kthCharacter(int k) {
        string str = "a";
        string gen = "b";
        while(str.length()<k){
            str+=gen;
            string temp="";
            for(char ch : gen){
                temp+=getNext(ch);
            }
            gen+=temp;
        }
        return str[k-1];
    }
};