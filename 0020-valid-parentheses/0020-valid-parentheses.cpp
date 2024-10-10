class Solution {
public:

    bool isValid(string s){
        unordered_map<char,int>symbols={{'(',-1},{'[',-2},{'{',-3},{')',1},{'}',3},{']',2}};
        stack<char>st;
        for(char i:s){
            if(symbols[i]<0)st.push(i);
            else{
                if(st.empty())return false;
                char top=st.top();
                st.pop();
                if (symbols[top]+symbols[i]!=0)return false;
            }
        }
        if(st.empty())return true;
        return false;

    }
    // bool isValid(string s) {
    //     stack<char> st;
    //     if(s[0]==')'||s[0]==']'||s[0]=='}')
    //         return false;
    //     for(int i=0; i<s.size(); i++){
    //         if(s[i]=='('||s[i]=='['||s[i]=='{')
    //             st.push(s[i]);
    //        else if(st.size()){
    //             char c=st.top();
    //             if(c=='(' && s[i]!=')')
    //                 return false;
    //             else if(c=='[' && s[i]!=']')
    //                 return false;
    //             else if(c=='{' && s[i]!='}')
    //                 return false;
    //             st.pop();
                
    //         }
    //         else
    //             return false;
    //         //cout<<st.top();
    //     }
    //     if(!st.empty())
    //         return false;
    //     return true;
    // }
};