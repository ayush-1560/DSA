class Solution {
public:
    bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
    vector<int> closestPrimes(int left, int right) {
        vector<int>primes;
        for(int i=left;i<=right;i++){
            if(isPrime(i)) primes.push_back(i);
        }
        int n=primes.size();
        int i=n-2;
        int j=n-1;
        int minVal=INT_MAX;
        int num1=-1,num2=-1;
        while(i>=0){
            if(primes[j]-primes[i]<=minVal){
                minVal=primes[j]-primes[i];
                num1=primes[i];
                num2=primes[j];
            }
            i--;
            j--;
        }
        return {num1,num2};
    }
};