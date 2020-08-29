class Solution {
public:
	bool isPalindrome(int x) {
		if( x < 0){return false;}
		if (x < 10) { return true; }
        long long  begin = 1, end = 10;
        long long y=x;
		while (y / (begin*10) != 0) {
			begin *= 10;
		}
		while (begin >= end) {
			if (y / begin % 10 == y % end / (end/10)) {
				begin /= 10;
				end *= 10;
			}
			else {
				return false;
			}
		}
		return true;
	}
};