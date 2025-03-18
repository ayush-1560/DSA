class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
       sort(deck.begin(),deck.end());
       int n = deck.size();
       vector<int>ans(n,0);
       int i=0,j=0;
       bool skip = false;
       while(i<n){
         if(ans[j]==0){
            if(!skip){
                ans[j] = deck[i];
                i++;
            }
            skip = !skip;
         }
         j=(j+1)%n;
       }
       return ans;
    }
};