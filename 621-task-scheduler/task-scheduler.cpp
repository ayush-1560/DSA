class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(char ch : tasks) freq[ch-'A']++;
        priority_queue<int>pq;
        for(int ele : freq) if(ele!=0) pq.push(ele);
        int ans=0;
        while(!pq.empty()){
            vector<int>v;
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    v.push_back(freq);
                }
            }
            for(auto f : v){
                if(f>0) pq.push(f);
            }
            if(pq.empty()){
                ans+=v.size();
            }
            else ans+=n+1;
        }
        return ans;
    }
};