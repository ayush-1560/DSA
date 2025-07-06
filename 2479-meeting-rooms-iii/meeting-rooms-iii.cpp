class Solution {
public:
    typedef pair<long long,int> P;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        priority_queue<P,vector<P>,greater<P>>pq;
        priority_queue<int,vector<int>,greater<>>pq2;
        for(int i=0;i<n;i++) pq2.push(i);
        vector<int>cnt(n,0);
        for(auto meeting : meetings){
            int start = meeting[0];
            int end = meeting[1];
            while(!pq.empty() && pq.top().first<=start){
                pq2.push(pq.top().second);
                pq.pop();
            }
            if(!pq2.empty()){
                int room = pq2.top();
                pq2.pop();
                cnt[room]++;
                pq.push({end,room});
            }
            else{
                int minRoom = pq.top().second;
                long long endTime = pq.top().first;
                pq.pop();
                cnt[minRoom]++;
                pq.push({endTime+(end-start),minRoom});
            }
        }
        int maxVal=0;
        int ans = -1;
        for(int i=0;i<cnt.size();i++){
            if(cnt[i]>maxVal){
                ans=i;
                maxVal=cnt[i];
            }
        }
        return ans;
    }
};