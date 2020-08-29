class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        for(int i=0;i<s.length();i++){
            char t=s.at(i);
            if(t=='('||t=='{'||t=='['){st.push(t);}
            else{
                if(st.empty()){return false;}
                char top=st.top();
                st.pop();
                if(t==')'&&top!='('){return false;}
                else if(t=='}'&&top!='{'){return false;}
                else if(t==']'&&top!='['){return false;}
            }
        }
        return st.empty()?true:false;
    }
};