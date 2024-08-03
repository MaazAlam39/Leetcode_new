class Solution {
public:
    vector<int> timeTaken(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        vector<int> f(n, 0);
        vector<int> s(n, 0);
        vector<int> c(n, 0);
        
        function<void(int, int)> dfs = [&](int i, int p) {
            for (int j : graph[i]) {
                if (j != p) {
                    int cost = (j & 1) ? 1 : 2;
                    dfs(j, i);
                    if (f[j] + cost > f[i]) {
                        s[i] = f[i];
                        f[i] = f[j] + cost;
                        c[i] = j;
                    } else if (f[j] + cost > s[i]) {
                        s[i] = f[j] + cost;
                    }
                }
            }
        };
        
        dfs(0, -1);
        
        vector<int> res(n, 0);
        
        function<void(int, int)> sdfs = [&](int i, int p) {
            for (int j : graph[i]) {
                if (j != p) {
                    int cost = (i & 1) ? 1 : 2;
                    if (c[i] == j) {
                        if (f[j] < s[i] + cost) {
                            s[j] = f[j];
                            f[j] = s[i] + cost;
                            c[j] = i;
                        } else {
                            s[j] = max(s[j], s[i] + cost);
                        }
                    } else {
                        s[j] = f[j];
                        f[j] = f[i] + cost;
                        c[j] = i;
                    }
                    sdfs(j, i);
                }
            }
        };
        
        sdfs(0, -1);
        
        return f;
    }
};