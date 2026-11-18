class Solution {
    bool hasDuplicate(const std::vector<char> block) {
        std::unordered_set<char> seen;
        for(const char c: block) {
            // Ignore empty cells (denoted by '.')
            if(c == '.') continue;

            auto [_, added] = seen.insert(c);
            if(!added) return true;
        }

        return false;
    }

    std::vector<char> getGrid(vector<vector<char>>& board, const int row, const int col) {
        std::vector<char> result;

        auto _row = row * 3;
        auto _col = col * 3;

        result.insert(result.end(), board[_row].begin() + _col, board[_row].begin() + _col + 3);
        result.insert(result.end(), board[_row+1].begin() + _col, board[_row+1].begin() + _col + 3);
        result.insert(result.end(), board[_row+2].begin() + _col, board[_row+2].begin() + _col + 3);

        std::cout << "[ ";
        for(const auto i: result) std::cout << i << " ";
        std::cout << "] " << std::endl;

        return result;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::cout << "ROWS" << std::endl;
        // Check rows for duplicates
        for(const auto& row: board) {
            if(hasDuplicate(row)) return false;
        }

        std::cout << "COLS" << std::endl;
        // Check column for duplicates
        for(int col=0; col<9; col++) {
            std::vector<char> col_vec;

            for(int row=0; row<9; row++) {
                col_vec.push_back(board[row][col]);
            }

            if(hasDuplicate(col_vec)) return false;
        }

        std::cout << "GRID" << std::endl;
        // Check for 3x3 grid validity
        for(int row = 0; row<3; row++) {
            for(int col = 0; col<3; col++) {
                auto grid = getGrid(board, row, col);
                if(hasDuplicate(grid)) return false;
            }
        }

        return true;
    }
};
