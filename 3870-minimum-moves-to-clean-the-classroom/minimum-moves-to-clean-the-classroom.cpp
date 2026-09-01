class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;
        vector<pair<int, int>> litter;

        // Find S and L
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();

        // Give each L a bit number
        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < k; i++) {
            id[litter[i].first][litter[i].second] = i;
        }

        int fullMask = (1 << k) - 1;

        // best[r][c][mask] = maximum energy with which
        // we have reached (r,c) having collected mask
        vector<vector<vector<int>>> best(
            m,
            vector<vector<int>>(
                n,
                vector<int>(1 << k, -1)
            )
        );

        // r, c, mask, remaining energy
        queue<tuple<int, int, int, int>> q;

        q.push({sr, sc, 0, energy});
        best[sr][sc][0] = energy;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto [r, c, mask, en] = q.front();
                q.pop();

                // All litter collected
                if (mask == fullMask)
                    return moves;

                if (en == 0)
                    continue;

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    int newEnergy = en - 1;
                    int newMask = mask;

                    // Collect litter
                    if (classroom[nr][nc] == 'L') {
                        int bit = id[nr][nc];
                        newMask |= (1 << bit);
                    }

                    // Reset
                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    // Only visit if we get MORE energy
                    // for the same position + mask
                    if (newEnergy > best[nr][nc][newMask]) {

                        best[nr][nc][newMask] = newEnergy;

                        q.push({
                            nr,
                            nc,
                            newMask,
                            newEnergy
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};