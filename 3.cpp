class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen=0;
        int nlen=0;
        int last=0;
        for(int i=0;i<s.size();i++){
            nlen=1;
            for(int j=last;j<i;j++){
                if(s[i]!=s[j]){
                    nlen++;
                }else{
                    last=j+1;
                    break;
                }
            }
            maxLen=maxLen>nlen?maxLen:nlen;
        }
        return maxLen;
    }
};