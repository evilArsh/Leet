class Solution {
public:
    int strStr(string haystack, string needle) {
        int hs=haystack.size(),ns=needle.size(),index=-1;
        if(ns==0){return 0;}
        if(ns>hs){return -1;}
        for(int i=0;i<hs-ns+1;i++){
            int j=0;
            for(;j<ns;j++){
                if(haystack[i+j]!=needle[j]){break;}
            }
            if(j==ns){index=i;break;}
        }
        return index;
    }
};