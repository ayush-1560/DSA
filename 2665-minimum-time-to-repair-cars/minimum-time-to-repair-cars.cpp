class Solution {
public:
    bool isPossible(vector<int>& ranks, int cars,long long k){
        long long carsFixed =0;
        for(int i=0;i<ranks.size();i++){
            carsFixed+=sqrt(k/ranks[i]);
        }
        return carsFixed>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        int minRank=*max_element(ranks.begin(),ranks.end());
        long long l=1, r=1LL*minRank*cars*cars;
        long long ans =1LL*minRank*cars*cars;
        while(l<=r){
            long long mid = l + (r-l)/2;
            if(isPossible(ranks,cars,mid)){
                ans = mid;
                r=mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};