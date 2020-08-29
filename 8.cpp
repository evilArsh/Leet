class Solution {
public:
    int myAtoi(string str) {
        // - 45
        // 0-9 48-57
        // 0x7fffffff pow(2,31)-1
        long long  a=0;
        int symbol=0;
        int num=0;
        bool minus=false;
        for(int i=0;i<str.size();i++){
            if(int(str[i])>=48&&int(str[i])<=57){
                num++;
                a=a*10+int(str[i]-48);
                if(a>=0x7fffffff&&!minus){return INT_MAX;}
                if(a>0x7fffffff&&minus){return INT_MIN;}
            }else if(int(str[i])==45){
                if(symbol||num>0){break;}
                minus=true;
                symbol=1;
            }else if(int(str[i])==43){
                if(symbol||num>0){break;}
                minus=false;
                symbol=1;
            }else if(int(str[i])==32){
                if(num>0||symbol){break;}
            }else{break;}
        }
        return minus?-a:a;
    }
};