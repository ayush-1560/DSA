class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,0});
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto [word,len]=q.front();
                q.pop();
                if(word==endWord) return len+1;
                for(int i=0;i<word.length();i++){
                    char temp = word[i];
                    for(char ch ='a';ch<='z';ch++){
                        word[i]=ch;
                        if(st.count(word)){
                            q.push({word,len+1});
                            st.erase(word);
                        }
                        word[i]=temp;
                    }
                }
            }
        }
        return 0;
    }
};