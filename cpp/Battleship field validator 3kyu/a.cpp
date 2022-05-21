#include <iostream>

#include <vector>

const int kFieldSize = 10;

bool NoRemained(int battleship, int cruisers, int destroyers, int subs)
{
    if (battleship != 0 || cruisers != 0 || destroyers != 0 || subs != 0)
    {
        return false;
    }
    return true;
}

int CheckField(std::vector<std::vector<int>> &field, int i, int j)
{
    if (field[i][j] == 0 || field[i][j] == 2)
        return 0;

    int dCounter{0};

    for (int x = 0; x < 4; x++)
    {
        if (i + x < kFieldSize)
        {
            if (field[i + x][j] != 0)
            {
                if (j - 1 > 0 && i + x - 1 > 0)
                {
                    if (field[i + x - 1][j - 1] != 0)
                    {
                        return -1;
                    }
                }
                if (j - 1 > 0 && i + x + 1 < kFieldSize - 1)
                {
                    if (field[i + x + 1][j - 1] != 0)
                    {
                        return -1;
                    }
                }

                if (j + 1 < kFieldSize && i + x - 1 > 0)
                {
                    if (field[i + x - 1][j + 1] != 0)
                    {
                        return -1;
                    }
                }
                if (j + 1 < kFieldSize && i + x + 1 < kFieldSize - 1)
                {
                    if (field[i + x + 1][j + 1] != 0)
                    {
                        return -1;
                    }
                }

                dCounter++;
                field[i + x][j] = 2;
            }
            else
            {
                break;
            }
        }
    }

    int rCounter{0};
    for (int y = 0; y < 4; y++)
    {
        if (i + y < kFieldSize)
        {
            if (field[i][j + y] != 0)
            {

                if (i - 1 > 0 && j + y - 1 > 0)
                {
                    if (field[i - 1][j + y - 1] != 0)
                    {
                        return -1;
                    }
                }
                if (i - 1 > 0 && j + y + 1 < kFieldSize)
                {
                    if (field[i - 1][j + y + 1] != 0)
                    {
                        return -1;
                    }
                }
                if (i + 1 < kFieldSize && j + y - 1 > 0)
                {
                    if (field[i + 1][j + y - 1] != 0)
                    {
                        return -1;
                    }
                }
                if (i + 1 < kFieldSize && j + y + 1 < kFieldSize)
                {
                    if (field[i + 1][j + y + 1] != 0)
                    {
                        return -1;
                    }
                }

                rCounter++;
                field[i][j + y] = 2;
            }
            else
            {
                break;
            }
        }
    }

    if (dCounter > 1 && rCounter > 1)
    {
        return -1;
    }
    if (dCounter >= rCounter)
    {
        return dCounter;
    }
    return rCounter;
}

bool validate_battlefield(std::vector<std::vector<int>> field)
{
    int battleship{1}; // 4
    int cruisers{2};   // 3
    int destroyers{3}; // 2
    int subs{4};       // 1

    for (int i = 0; i < kFieldSize; i++)
    {
        for (int j = 0; j < kFieldSize; j++)
        {
            int h = CheckField(field, i, j);
            if (h == 1)
            {
                subs--;
            }
            else if (h == 2)
            {
                destroyers--;
            }
            else if (h == 3)
            {
                cruisers--;
            }
            else if (h == 4)
            {
                battleship--;
            }
            else if (h == -1)
            {
                return false;
            }
        }
    }
    return NoRemained(battleship, cruisers, destroyers, subs);
}

int main()
{
    std::vector<std::vector<int>> f{
        std::vector<int>{1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
        std::vector<int>{1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
        std::vector<int>{1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
        std::vector<int>{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        std::vector<int>{0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        std::vector<int>{0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        std::vector<int>{0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        std::vector<int>{0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        std::vector<int>{0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        std::vector<int>{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    std::cout << validate_battlefield(f);

    // std::cout << std::endl;
    // for (auto &&i : f)
    // {
    //     for (auto &&j : i)
    //     {
    //         std::cout << j;
    //     }
    //     std::cout << std::endl;
    // }

    return 0;
}