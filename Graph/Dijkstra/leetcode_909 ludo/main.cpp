class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> adj;
        vector<int> dist(n * n, INT_MAX);
        dist[0] = 0;
        bool c = true;
        for (int i = n-1; i >=0; i--) {
            for (int j = 0; j < n; j++) {
                if (c) {
                    adj.push_back(board[i][j]);
                } else {
                    adj.push_back(board[i][n - j - 1]);
                }
            }
            c = !c;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            q;
        q.push({0, 0});
        while (!q.empty()) {
            pair<int, int> p = q.top();
            q.pop();
            int d = p.first;
            int x = p.second;
            for (int i = 1; i <= 6; i++) {
                if (x + i < n * n) {
                    if (adj[x + i] != -1) {
                        int newx = adj[x + i] - 1;
                        if (dist[newx] > 1 + d) {
                            q.push({1 + d, newx});
                            dist[newx] = 1 + d;
                        }
                    } else {
                        if (dist[x + i] > 1 + d) {
                            q.push({1 + d, x + i});
                            dist[x + i] = 1 + d;
                        }
                    }
                }
            }
        }
        return dist[n*n-1] == INT_MAX ? -1 : dist[n*n-1];
    }
};