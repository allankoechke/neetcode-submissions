class Solution {
    bool hasDuplicate(const std::vector<char>& block) {
        std::array<uint8_t, 9> seen{};
        for(const char c: block) {
            // Ignore empty cells (denoted by '.')
            if(c == '.') continue;

            int i = c - '1';
            if(seen[i]) return true;
            seen[i] = 1;
        }

        return false;
    }

    bool hasGridDuplicate(vector<vector<char>>& board, const int cell) {
        std::array<uint8_t, 9> seen{};

        // Get actual row and col by * 3
        auto row = (cell / 3) * 3;
        auto col = (cell % 3) * 3;

        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                char c = board[row+i][col + j];
                if(c == '.') continue;

                int v = c - '1';
                if(seen[v]) return true;
                seen[v] = 1;
            }
        }

        return false;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::cout << "ROW" << std::endl;
        // Check rows for duplicates
        for(const auto& row: board) {
            if(hasDuplicate(row)) return false;
        }

        std::cout << "COL" << std::endl;
        // Check column for duplicates
        for(int col=0; col<9; col++) {
            std::array<uint8_t, 9> seen{};

            for(int row=0; row<9; row++) {
                auto c = board[row][col];
                if(c == '.') continue;
                int i = c - '1';
                if(seen[i]) return false;
                seen[i] = 1;
            }
        }

        std::cout << "GRID" << std::endl;
        // Check for 3x3 grid validity
        for(int i = 0; i<9; i++) {
            if(hasGridDuplicate(board, i)) return false;
        }

        return true;
    }
};
