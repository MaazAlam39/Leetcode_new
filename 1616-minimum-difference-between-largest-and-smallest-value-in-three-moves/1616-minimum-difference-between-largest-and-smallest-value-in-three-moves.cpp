/*class Solution {
public:
r<int>& nums) {
        
*/
class Solution {
    public:
            int minDifference(vector<int>& A) {
        
                int n = A.size();
                if (n < 5) return 0;
                sort(A.begin(), A.end());
                int k=n-3;
                int ans=A.back()-A[0];
                for(int i=k-1;i<n;i++){
                    ans=min(ans,A[i]-A[i-k+1]);
                }
                return ans;
            }
    };
