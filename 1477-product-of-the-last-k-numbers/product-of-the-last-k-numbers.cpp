class ProductOfNumbers {
public:
    vector<int>prod;
    ProductOfNumbers() {
    }
    
    void add(int num) {
        prod.push_back(num);
    }
    
    int getProduct(int k) {
        int n=prod.size();;
        int pdct=1;
        for(int i=n-k;i<n;i++){
            pdct*=prod[i];
        }
        return pdct;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */