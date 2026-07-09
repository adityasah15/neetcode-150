class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> rows[9];
        unordered_set<int> cols[9];
        map<pair<int, int>, unordered_set<int>> squares;
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                int curr = board[r][c];
                if (curr == '.')
                    continue;
                pair<int, int> superkey = {r / 3, c / 3};
                if (rows[r].count(curr) || cols[c].count(curr) ||
                    squares[superkey].count(curr)) {
                    return false;
                }
                rows[r].insert(curr);
                cols[c].insert(curr);
                squares[superkey].insert(curr);
            }
        }
        return true;
    }
};