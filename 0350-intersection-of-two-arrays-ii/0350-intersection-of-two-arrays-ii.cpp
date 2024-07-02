class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> c1(1001,0);
        vector<int> c2(1001,0);
        for(int n:nums1)c1[n]++;
        for(int n:nums2)c2[n]++;

        vector<int> resl;
        for(int n=0;n<1001;n++){
            int minm=min(c1[n],c2[n]);
            for(int i=0;i<minm;i++)resl.push_back(n);
        }return resl;

    }
};