class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1;
        int maxi=0;
        // int l=height.size();
        while(left < right){
            int currentarea=(min(height[left],height[right]))*(right-left);
            maxi=max(maxi,currentarea);

            if(height[left]<height[right])left++;
            else right--;
        }
        return maxi;
       
    }
};