class Solution {
public:
    string maps[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> res;
    void trace(string &s,string &digits,int index){
        if(index==digits.length()){
            res.push_back(string(s));
            return;
        }
        string letters=maps[digits[index]-'0'];
        int len=letters.length();
        for(int i=0;i<len;i++){
            s+=letters[i];
            trace(s,digits,index+1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0){return res;}
        string tmp="";
        trace(tmp,digits,0); 
        return res;
    }
};