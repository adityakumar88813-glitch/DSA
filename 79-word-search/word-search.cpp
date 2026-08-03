class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int row, int col, int index) {

        // All characters matched
        if (index == word.size())
            return true;

        // Boundary check + character check
        if (row < 0 || row >= board.size() ||
            col < 0 || col >= board[0].size() ||
            board[row][col] != word[index])
            return false;

        // Mark as visited
        char ch = board[row][col];
        board[row][col] = '#';

        // Explore 4 directions
        bool found =
            dfs(board, word, row + 1, col, index + 1) ||
            dfs(board, word, row - 1, col, index + 1) ||
            dfs(board, word, row, col + 1, index + 1) ||
            dfs(board, word, row, col - 1, index + 1);

        // Backtrack
        board[row][col] = ch;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int rows = board.size();
        int cols = board[0].size();

        // Start DFS from every cell
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};