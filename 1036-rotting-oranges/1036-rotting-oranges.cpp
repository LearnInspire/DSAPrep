class Solution {
public:
    //approach 2: everything is same just optimize the code using cnt & time
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int tot = 0, cnt = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                if (grid[i][j] != 0)
                    tot++;
            }
        }
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        int ans = 0;
        while (!q.empty()) {
            int k = q.size();
            cnt += k;
            while (k--) {
                int y = q.front().second, x = q.front().first;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m ||
                        grid[nx][ny] != 1)
                        continue;
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
            if (!q.empty())
                ans++;
        }
        if (tot == cnt)
            return ans;
        return -1;
    }

    /*approch 1: gives TLE
    int orangesRotting(vector<vector<int>>& grid) {
        // using bfs graph traversal
        if(grid.empty()) return 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q; //{{row, col}, time}
        int vis[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                } else
                    vis[i][j] = 0;
            }
        }
        int time = 0;
        int drow[4] = {-1, 0, +1, 0};
        int dcol[4] = {0, 1, 0, -1};
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();
            for (int i = 0; i < 4; i++) {
                int neighborRow = r + drow[i];
                int neighborCol = c + drow[i];
                if (neighborRow < 0 && neighborCol < 0 && neighborRow >= m &&
                    neighborCol >= n && vis[neighborRow][neighborCol] != 2 &&
                    grid[neighborRow][neighborCol] == 1) {
                        q.push({{neighborRow, neighborCol}, t + 1});
                        vis[neighborRow][neighborCol] = 1;
                }
            }
        }

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(vis[i][j] != 2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return time;
    }*/
};