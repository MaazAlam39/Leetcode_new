class Tracker {
public:
    int val;
    int index;
    int column;
    
    Tracker(int v, int i, int c) : val(v), index(i), column(c) {}
};
struct compare{
    bool operator()(const Tracker& a,const Tracker&b){
        return a.val>b.val;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Tracker,vector<Tracker>,compare>track;
        int maxval=INT_MIN;
        int n=nums.size();
        int start=0;
        int end=INT_MAX;
        for(int i=0;i<n;i++){
            int val=nums[i][0];
            track.push(Tracker(val,i,0));
            maxval=max(maxval,val);
        }
        while(track.size()==n){
            Tracker temp=track.top();
            track.pop();

            if(maxval-temp.val<end-start){
                start=temp.val;
                end=maxval;
            }

            if(temp.column+1<nums[temp.index].size()){
                int nextval=nums[temp.index][temp.column+1];
                track.push(Tracker(nextval,temp.index,temp.column+1));
                maxval=max(maxval,nextval);
            }
        }
        return {start,end};
    }
};

