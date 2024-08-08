class Solution {
public:
    int minimumPushes(string word) {
        int ans=0;
        vector<int> freq(26,0);
        for(auto it:word)freq[it-'a']++;
        sort(freq.rbegin(),freq.rend());
        int i=0;
        while(i<26){
            if(i<8){
                ans+= freq[i]; // map at first positon of all keys
            }
            else if(i<16){
                ans+= freq[i]*2; // map with second position of all keys
            }else if(i<24){
                ans+= freq[i]*3; // map with third position all keys
            }
            else ans+= freq[i]*4; // map with fourth position of all keys
        i++;
        }
        return ans;
    }
};