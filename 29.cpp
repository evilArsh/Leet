#include "head.h"
using namespace std;
class Solution {
public:
    int divide(int a, int b) {
        if(b==0){return 0;}
        if(b==1){return a;}
        int sign=-1,res=0;
        if(b==-1){
            if(a>INT_MIN){return -a;}
            return INT_MAX;
        }
        if((a>0&&b>0)||(a<0&&b<0)){sign=1;}
        a=a>0?0-a:a;
        b=b>0?0-b:b;
        res=div(a,b);
        return sign>0?res:0-res;     
    }
    int div(int a,int b){
        if(a>b){return 0;}
        int count=1,sum=b;
        while(sum+sum>=a&&sum+sum<0){
            count+=count;
            sum+=sum;
        }
        return count+div(a-sum,b);
    }
};
int main(){
    Solution so;
    cout<<so.divide(-2147483648,2);
    // cout<<so.divide(10,3);
}


// class Solution {
// public:
//     int divide(int a, int b) {
//         int sign=-1,res=0;
//         if((a>0&&b>0)||(a<0&&b<0)){sign=1;}
//         a=a>0?0-a:a;
//         b=b>0?0-b:b;
//         if(b==0){return 0;}
//         if(a>b){return 0;}
//         if(b==-1){
//             if(a>INT_MIN){return sign>0?-a:a;}
//             return INT_MAX;
//         }
//         res=div(a,b);
//         return sign>0?res:0-res;     
//     }
//     int div(int a,int b){
//         if(a>b){return 0;}
//         int count=1,sum=b;
//         while(sum+sum>=a){
//             count+=count;
//             sum+=sum;
//         }
//         return count+div(a-sum,b);
//     }
// };