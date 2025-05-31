class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n * n + 1, false);
        queue<pair<int, int>> q; // (square, moves)
        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [square, moves] = q.front();
            q.pop();
            if (square == n * n) return moves;

            for (int i = 1; i <= 6; ++i) {
                int nextSquare = square + i;
                if (nextSquare > n * n) continue;

                pair<int, int> pos = getBoardPosition(nextSquare, n);
                int row = pos.first, col = pos.second;
                if (board[row][col] != -1) {
                    nextSquare = board[row][col];
                }

                if (!visited[nextSquare]) {
                    visited[nextSquare] = true;
                    q.push({nextSquare, moves + 1});
                }
            }
        }

        return -1; // unreachable
    }

private:
    // Helper function to convert square number to (row, col) in the board
    pair<int, int> getBoardPosition(int s, int n) {
        int quot = (s - 1) / n;
        int rem = (s - 1) % n;
        int row = n - 1 - quot;
        int col = (quot % 2 == 0) ? rem : (n - 1 - rem);
        return {row, col};
    }
};
