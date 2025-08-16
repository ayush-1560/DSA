class Solution {
public:
    int maximum69Number (int num) {
        int temp = num;
        int pos=-1;
        int counter =0;
        while(temp>0){
            int r = temp%10;
            if(r==6){
                pos=counter;
            }
            counter++;
            temp/=10;
        }
        return pos!=-1 ? num + 3*pow(10,pos) : num;
    }
};