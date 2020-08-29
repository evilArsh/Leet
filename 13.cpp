class Solution {
public:
    int romanToInt(string s) {
        int num=0;
        int a[26];
        a[8]=1;a[21]=5;a[23]=10;a[11]=50;a[2]=100;a[3]=500;a[12]=1000;
        for(int i=s.size()-1;i>=0;){
            int now=a[s[i]-65];
            if(i-1>=0){
                int back=a[s[i-1]-65];
                if(now>back){
                    num+=now-back;
                    i=i-2;
                }else{
                    num+=now;
                    i--;
                }
            }else{
                num+=now;
                i--;
            }
        }
    return num;
    }
};