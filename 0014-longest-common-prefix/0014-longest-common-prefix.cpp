// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         string ans="";
//         sort(strs.begin(),strs.end());
//         int n=strs.size();
//         string first=strs[0],last=strs[n-1];
//         for(int i=0;i<min(first.size(),last.size());i++){
//             if(first[i]!=last[i]){
//                 return ans;
//             }
//             ans+=first[i];
//         }
//         return ans;
//     }
// };






class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n=strs.size();
        
        string first = strs[0], last = strs[n - 1];
        int minm=min(first.size(),last.size());
        int i=0;
        while(i<minm && first[i]==last[i])i++;
        string pre = first.substr(0, i);
        return pre; 
    }
};
