#include <iostream>

#include <vector>
#include <utility>
#include <algorithm>

int sum_intervals(std::vector<std::pair<int, int>> intervals)
{
    std::vector<int> vec{};
    for (size_t i = 0; i < intervals.size(); i++)
    {
        for (int y = intervals[i].first; y < intervals[i].second; y++)
        {
            if (std::find(vec.begin(), vec.end(), y) == vec.end())
            {
                vec.push_back(y);
            }
        }
    }

    return vec.size();
}

int main()
{
    std::cout << sum_intervals({{1, 5}, {6, 10}});
}