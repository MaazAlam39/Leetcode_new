class Solution {
public:
    int minOperations(vector<string>& logs) {
        vector<string> path_stack;
        for(const string& log : logs){
            if(log=="../"){
                if(!path_stack.empty()){
                    path_stack.pop_back();
                }
            }else if (log !="./"){
                path_stack.push_back(log);
            }
        }
        return path_stack.size();

    }
};