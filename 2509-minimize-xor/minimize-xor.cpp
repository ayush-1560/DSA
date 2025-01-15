class Solution {
public:
    bool isSetBit(int& x , int bit){
        return x & (1<<bit);
    }
    bool setBit(int&x , int bit){
        return (x |=(1<<bit));
    }
    bool isUnsetBit(int& x, int bit){
        return (x & (1<<bit)) ==0;
    }
    int minimizeXor(int num1, int num2) {
        int x =0;
        int req_setBit = __builtin_popcount(num2);
        for(int bit =31 ; bit>=0 &&(req_setBit>0);bit--){
            if(isSetBit(num1,bit)){
                setBit(x,bit);
                req_setBit--;
            }
        }
        for(int bit =0;bit<32 && (req_setBit>0);bit++){
            if(isUnsetBit(num1,bit)){
                setBit(x,bit);
                req_setBit--;
            }
        }
        return x;
    }
};