class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int res=0;
        string top,bot;
        int t_score, b_score;

        if (y>x){
            top="ba";
            t_score=y;
            bot="ab";
            b_score=x;
        }
        else{
            top="ab";
            t_score=x;
            bot="ba";
            b_score=y;
        }

        vector<char> stack;
        for(char ch:s){
            if(ch==top[1] && !stack.empty() && stack.back()==top[0]){
                res+=t_score;
                stack.pop_back();
            }else stack.push_back(ch);
        }

        vector<char> new_stack;
        for(char ch:stack){
            if(ch==bot[1] && !new_stack.empty() && new_stack.back()==bot[0]){
                res+=b_score;
                new_stack.pop_back();
            }else new_stack.push_back(ch);
        }
        return res;

    }
};