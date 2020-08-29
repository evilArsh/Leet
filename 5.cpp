class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() < 2) { return s; }
		int begin = 0, end = 0;
		int l = 0, r = 0;
		int n = s.size();
		// while (i < s.size()) {
        for(int i=0;i<n;){
            if(n-i<=(end-begin)/2){break;}
            l=i;
            r=i;
            while(r<s.size()-1&&s[i]==s[r+1]){r++;}
            i=r+1;
            while(l-1>=0&&r+1<=s.size()){
                if(s[l-1]==s[r+1]){
                    l--;
                    r++;
                }else{break;}
            }
            if(r-l>end-begin){begin=l;end=r;}
		}
		return s.substr(begin, end - begin + 1);
	}
};