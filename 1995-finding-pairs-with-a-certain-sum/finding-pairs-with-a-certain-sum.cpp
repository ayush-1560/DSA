class FindSumPairs {
public:
    vector<int>v1,v2;
    unordered_map<int,int>mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v1=nums1;
        v2=nums2;
        for(int num : nums2) mp[num]++;
    }
    
    void add(int index, int val) {
        mp[v2[index]]--;
        v2[index]+=val;
        mp[v2[index]]++;
    }
    
    int count(int tot) {
        int cnt=0;
        for(int i=0;i<v1.size();i++){
            if(mp.count(tot-v1[i])) cnt+=mp[tot-v1[i]];
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */