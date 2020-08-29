class Solution {
public:
    int reverse(int x) {
        long long y;
        int pos=1;
        long long res=0;
        pos=1;
        y=x;
        y = x < 0 ? -y : y;
        while(y!=0){
            res=res*10+y%10;
            y/=10;
            pos++;
        }
        if(res<=(unsigned int)pow(2,31)&&x<0){
            return -int(res);
        }
        if(res<=(unsigned int)pow(2,31)-1&&x>0){
            return int(res);
        }
        return 0;
    }
};