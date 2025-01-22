class ProductOfNumbers {
public:
    vector<int>suffProd;
    ProductOfNumbers() {
        suffProd.push_back(1);
    }
    
    void add(int num) {
        if(num==0){
            suffProd.clear();
            suffProd.push_back(1);
        }
        else{
            suffProd.push_back(suffProd.back()*num);
        }
    }
    
    int getProduct(int k) {
        int n = suffProd.size();
        if(k>=n) return 0;
        return suffProd[n-1]/suffProd[n-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */