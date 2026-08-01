class Solution {
public:

    void bfs(vector<vector<int>>& Adj,
             queue<pair<int,int>>& q,
             int oldColor,
             int newColor) {

        int n = Adj.size();
        int m = Adj[0].size();

        while (!q.empty()) {

            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            // Up
            if (i - 1 >= 0 && Adj[i - 1][j] == oldColor) {
                Adj[i - 1][j] = newColor;
                q.push({i - 1, j});
            }

            // Down
            if (i + 1 < n && Adj[i + 1][j] == oldColor) {
                Adj[i + 1][j] = newColor;
                q.push({i + 1, j});
            }

            // Left
            if (j - 1 >= 0 && Adj[i][j - 1] == oldColor) {
                Adj[i][j - 1] = newColor;
                q.push({i, j - 1});
            }

            // Right
            if (j + 1 < m && Adj[i][j + 1] == oldColor) {
                Adj[i][j + 1] = newColor;
                q.push({i, j + 1});
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& Adj,
                                  int sr,
                                  int sc,
                                  int newColor) {

        int oldColor = Adj[sr][sc];

        if (oldColor == newColor)
            return Adj;

        queue<pair<int,int>> q;
        q.push({sr, sc});

        // Mark the starting cell as visited
        Adj[sr][sc] = newColor;

        bfs(Adj, q, oldColor, newColor);

        return Adj;
    }
};