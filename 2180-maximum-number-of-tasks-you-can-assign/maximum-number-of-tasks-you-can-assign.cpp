class Solution {
public:
    bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid) {
        multiset<int> st(begin(workers), begin(workers) + mid);

        for(int i = mid-1; i >= 0; i--) {
            int reqrd = tasks[i];
            auto it   = prev(st.end());

            if(*it >= reqrd) {
                st.erase(it);
            } else if(pills<=0) {
                return false;
            } else {
                auto weakestWorkerIt = st.lower_bound(reqrd - strength);
                if(weakestWorkerIt == st.end()) {
                    return false;
                }
                st.erase(weakestWorkerIt);
                pills--;
            }
        }

        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int m = tasks.size(),n=workers.size();
        int l = 0;
        int r = min(m,n);
        int ans=0;
        sort(begin(tasks), end(tasks));
        sort(begin(workers), end(workers), greater<int>());
        while(l<=r){
            int mid = l+(r-l)/2;
            if(check(tasks,workers,pills,strength,mid)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};