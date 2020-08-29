class Solution {
public:
    vector<string> res;
    void dfs(string& str,int left,int right,const int& len){
        if(str.length()==len*2){res.push_back(str);return;}
        if(left<len){
            str.push_back('(');
            dfs(str,left+1,right,len);
            str.pop_back();
        }
        if(right<left){
            str.push_back(')');
            dfs(str,left,right+1,len);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string tmp="";
        int len=n;
        dfs(tmp,0,0,len);
        return res;
    }
};