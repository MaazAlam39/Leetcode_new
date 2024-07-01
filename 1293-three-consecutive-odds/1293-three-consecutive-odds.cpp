class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
    int odds = 0;
    for (auto i = 0; i < arr.size() && odds < 3; ++i){
        if((arr[i]%2) !=0)odds=odds+1;
        else odds=0;
    }
        //odds = arr[i] % 2 ? odds + 1 : 0;
    return odds == 3;
}
};