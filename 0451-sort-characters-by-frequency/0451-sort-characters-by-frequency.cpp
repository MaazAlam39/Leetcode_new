#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqMap;
        for (char ch : s) {
            freqMap[ch]++;
        }

        vector<pair<int, char>> freqVec;
        for (const auto& pair : freqMap) {
            freqVec.push_back({pair.second, pair.first});
        }

        sort(freqVec.begin(), freqVec.end(), greater<pair<int, char>>());

        string result;
        for (const auto& pair : freqVec) {
            result.append(pair.first, pair.second);
        }

        return result;
    }
};
