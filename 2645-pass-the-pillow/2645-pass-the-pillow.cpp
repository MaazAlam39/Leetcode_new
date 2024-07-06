class Solution {
public:
    int passThePillow(int n, int time) {
        int completed=time/(n-1);
        int remain=time%(n-1);
        int ans=0;
        if(completed % 2 !=0)ans=n-remain;
        else ans=remain+1;
        //return chunks % 2 == 0 ? (time % (n - 1) + 1) : (n - time % (n - 1));
        return ans;
    }
};