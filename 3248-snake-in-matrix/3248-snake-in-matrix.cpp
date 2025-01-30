class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        vector<vector<int>> grid(n, vector<int>(n)); 
        int num = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                grid[i][j] = num++;
            }
        }

        int in = 0, j = 0;

        for(auto& command : commands) {
            if(command == "DOWN" && in + 1 < n) {
                in += 1;
            }
            else if(command == "UP" && in - 1 >= 0) {
                in -= 1;
            }
            else if(command == "LEFT" && j - 1 >= 0) {
                j -= 1;
            }
            else if(command == "RIGHT" && j + 1 < n) {
                j += 1;
            }
        }
        
        return grid[in][j];
    }
};
