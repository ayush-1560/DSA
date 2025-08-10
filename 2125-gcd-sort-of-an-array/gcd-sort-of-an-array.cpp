class Solution {
public:
    vector<int> parent, rank;

    int find(int i) {
        if (i == parent[i]) return i;
        return parent[i] = find(parent[i]);
    }

    void Union(int x, int y) {
        int par_x = find(x);
        int par_y = find(y);
        if (par_x == par_y) return;
        if (rank[par_x] > rank[par_y]) {
            parent[par_y] = par_x;
        } else if (rank[par_y] > rank[par_x]) {
            parent[par_x] = par_y;
        } else {
            parent[par_y] = par_x;
            rank[par_x]++;
        }
    }
    vector<int>getFactors(int x){
        vector<int>factors;
        for(int i=2;i*i<=x;i++){
            if(x%i==0) factors.push_back(i);
            while(x%i==0) x/=i;
        }
        if(x>1) factors.push_back(x);
        return factors;
    }
    bool gcdSort(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(),nums.end());
        parent.resize(mx+1);
        rank.resize(mx+1,1);
        for(int i=0; i <= mx; i++) parent[i] = i;
        for(int num : nums){
            vector<int>factors = getFactors(num);
            for(int f : factors) Union(num,f);
        }
        vector<int>sortedNums=nums;
        sort(sortedNums.begin(),sortedNums.end());
        for(int i=0;i<n;i++){
            if(find(sortedNums[i])!=find(nums[i])) return false;
        }
        return true;
    }
};