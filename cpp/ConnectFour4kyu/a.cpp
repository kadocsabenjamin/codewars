#include <iostream>

////////////////////////////////

#include <string>
#include <vector>

int getNext(int column, std::vector<std::vector<std::string>>& grid) {
    for (size_t i = 0; i < 6; i++) {
        if (grid[i][column] == "") {
            return i;
        }
    }
    return -1;
}

std::vector<std::vector<std::string>> initGrid() {
    std::vector<std::vector<std::string>> grid;
    for (size_t i = 0; i < 6; i++) {
        std::vector<std::string> temp;
        for (size_t j = 0; j < 7; j++) {
            temp.push_back("");
        }
        grid.push_back(temp);
    }

    return grid;
}

std::string who_is_winner(std::vector<std::string> pieces_position_list) {
    std::vector<std::vector<std::string>> grid = initGrid();

    for (auto i : pieces_position_list) {
        int column = int(i[0] - 'A');

        grid[getNext(column, grid)][column] = i[2];

        for (size_t i = 0; i < 6; i++) {
            for (size_t j = 0; j < 7; j++) {
                if (j < 7 - 3) {
                    if (grid[i][j] == "R" && grid[i][j + 1] == "R" && grid[i][j + 2] == "R" && grid[i][j + 3] == "R") {
                        return "Red";
                    }
                    if (grid[i][j] == "Y" && grid[i][j + 1] == "Y" && grid[i][j + 2] == "Y" && grid[i][j + 3] == "Y") {
                        return "Yellow";
                    }
                }
                if (i < 6 - 3) {
                    if (grid[i][j] == "R" && grid[i + 1][j] == "R" && grid[i + 2][j] == "R" && grid[i + 3][j] == "R") {
                        return "Red";
                    }
                    if (grid[i][j] == "Y" && grid[i + 1][j] == "Y" && grid[i + 2][j] == "Y" && grid[i + 3][j] == "Y") {
                        return "Yellow";
                    }
                }
                if (i < 6 - 3 && j < 7 - 3) {
                    if (grid[i][j] == "R" && grid[i + 1][j + 1] == "R" && grid[i + 2][j + 2] == "R" && grid[i + 3][j + 3] == "R") {
                        return "Red";
                    }
                    if (grid[i][j] == "Y" && grid[i + 1][j + 1] == "Y" && grid[i + 2][j + 2] == "Y" && grid[i + 3][j + 3] == "Y") {
                        return "Yellow";
                    }
                }
                if (i < 6 - 3 && j > 2) {
                    if (grid[i][j] == "R" && grid[i + 1][j - 1] == "R" && grid[i + 2][j - 2] == "R" && grid[i + 3][j - 3] == "R") {
                        return "Red";
                    }
                    if (grid[i][j] == "Y" && grid[i + 1][j - 1] == "Y" && grid[i + 2][j - 2] == "Y" && grid[i + 3][j - 3] == "Y") {
                        return "Yellow";
                    }
                }
            }
        }
    }

    return "Draw";
}

////////////////////////////////

int main() {
    std::cout << who_is_winner({"C_Yellow", "E_Red",
                                "G_Yellow",
                                "B_Red", "D_Yellow",
                                "B_Red", "B_Yellow",
                                "G_Red", "C_Yellow",
                                "C_Red", "D_Yellow", "F_Red", "E_Yellow", "A_Red", "A_Yellow", "G_Red", "A_Yellow", "F_Red", "F_Yellow", "D_Red",
                                "B_Yellow", "E_Red",
                                "D_Yellow", "A_Red", "G_Yellow", "D_Red", "D_Yellow", "C_Red"});
    return 0;
}