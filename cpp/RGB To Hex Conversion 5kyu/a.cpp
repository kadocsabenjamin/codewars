#include <iostream>
#include <string>

std::string GetDigit(int num)
{
    if (num < 10)
    {
        return std::to_string(num);
    }

    char res = 'A' + (num - 10);

    return std::string(1, res);
}

std::string DecToHex(int num)
{
    std::string result{};

    if (num > 255)
    {
        num = 255;
    }
    else if (num < 0)
    {
        num = 0;
    }

    int first{num / 16};
    int second{num % 16};
    result += GetDigit(first);
    result += GetDigit(second);

    return result;
}

class RGBToHex
{
public:
    static std::string rgb(int r, int g, int b)
    {
        std::string result{};
        result += DecToHex(r);
        result += DecToHex(g);
        result += DecToHex(b);
        return result;
    }
};

int main()
{
    RGBToHex a;
    std::cout << a.rgb(254, 255, 255);

    return 0;
}