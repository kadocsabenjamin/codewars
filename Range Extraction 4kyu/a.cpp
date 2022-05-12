#include <iostream>
#include <string>
#include <vector>

std::string range_extraction(std::vector<int> args)
{
    std::string ret_value;
    for (size_t i = 0; i < args.size(); i++)
    {
        int counter = 0;
        while (args[i + counter + 1] == args[i + counter] + 1)
        {
            counter++;
        }
        if (counter == 0)
        {
            ret_value += std::to_string(args[i]);
            ret_value += ",";
        }
        else if (counter == 1)
        {
            ret_value += std::to_string(args[i]);
            ret_value += ",";
            ret_value += std::to_string(args[i + 1]);
            ret_value += ",";
            i++;
        }
        else
        {
            ret_value += std::to_string(args[i]);
            ret_value += "-";
            ret_value += std::to_string(args[i + counter]);
            ret_value += ",";
            i += counter;
        }
    }
    ret_value.pop_back();

    return ret_value;
}

int main()
{

    std::vector<int> args = {-6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20};
    std::cout << range_extraction(args) << std::endl;
    return 0;
}