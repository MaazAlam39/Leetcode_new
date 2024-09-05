class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> obstacleSet;
        for(auto& obs : obstacles) {
            obstacleSet.insert({obs[0], obs[1]});
        }

        int ans = 0;
        int x = 0, y = 0, dir = 0;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // N, E, S, W

        for(int cmd : commands) {
            if(cmd == -1) {
                dir = (dir + 1) % 4;
            } else if(cmd == -2) {
                dir = (dir - 1 + 4) % 4;
            } else {
                for(int step = 0; step < cmd; step++) {
                    int new_x = x + directions[dir][0];
                    int new_y = y + directions[dir][1];
                    
                    if(obstacleSet.count({new_x, new_y}) > 0) break;
                    
                    x = new_x;
                    y = new_y;
                    ans = max(ans, x*x + y*y);
                }
            }
        }
        return ans;
    }
};