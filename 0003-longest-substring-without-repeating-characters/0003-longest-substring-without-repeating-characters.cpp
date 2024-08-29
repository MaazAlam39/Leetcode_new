class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        // int n = s.length();
        // int maxLength = 0;
        // unordered_set<char> charSet;
        // int left = 0;
        
        // for (int right = 0; right < n; right++) {
        //     if (charSet.count(s[right]) == 0) {
        //         charSet.insert(s[right]);
        //         maxLength = max(maxLength, right - left + 1);
        //     } else {
        //         while (charSet.count(s[right])) {
        //             charSet.erase(s[left]);
        //             left++;
        //         }
        //         charSet.insert(s[right]);
        //     }
        // }
        
        // return maxLength;



        if(str.size()==0)
            return 0;
        
        int maxans = INT_MIN;
        unordered_set < int > set;
        int l = 0;
        for (int r = 0; r < str.length(); r++) // outer loop for traversing the string
        {
            if (set.find(str[r]) != set.end()) //if duplicate element is found
            {
            while (l < r && set.find(str[r]) != set.end()) {
                set.erase(str[l]);
                l++;
            }
            }
            set.insert(str[r]);
            maxans = max(maxans, r - l + 1);
        }
        return maxans;
    }
};