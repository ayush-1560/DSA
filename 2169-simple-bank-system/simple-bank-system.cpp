class Bank {
public:
    vector<long long> balance;
    int n;
    Bank(vector<long long>& balance) {
        this->balance = balance;
        n = balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1-1 >=n || account2-1>=n) return false;
        if(balance[account1-1] <money) return false;
        balance[account2-1]+=money;
        balance[account1-1]-=money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(account-1 >=n) return false;
        balance[account-1]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account-1 >=n) return false;
        if(balance[account-1]<money) return false;
        balance[account-1]-=money;
        return true;
    }
};
