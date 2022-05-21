#include <iostream>
#include <string>

std::string multiply(std::string a, std::string b)
{
    if (a == "0" || b == "0")
    {
        return "0";
    }

    std::string result(a.size() + b.size(), 0);

    for (int i = a.size() - 1; i >= 0; i--)
    {
        for (int j = b.size() - 1; j >= 0; j--)
        {
            int n = (a[i] - '0') * (b[j] - '0') + result[i + j + 1];
            result[i + j + 1] = n % 10;
            result[i + j] += n / 10;
        }
    }

    for (int i = 0; i < result.size(); i++)
    {
        result[i] += '0';
    }

    int i = 0;
    while (result[i] == '0')
    {
        i++;
    }

    return result.substr(i);
}

int main()
{
    std::cout << multiply("0000001", "3");
    return 0;
}