#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

const std::string open = "(";
const std::string close = ")";

bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

int GetMax(std::vector<int> &lst)
{
    int max{0};
    for (auto i : lst)
    {
        if (abs(i) > max)
        {
            max = abs(i);
        }
    }
    return max;
}

class SumOfDivided
{
public:
    static std::string sumOfDivided(std::vector<int> &lst)
    {
        // int max{*std::max_element(lst.begin(), lst.end())};
        // this would be better than my func but codewars dont likey
        int max = GetMax(lst);

        int i{2};
        std::string factors{};
        while (max >= i)
        {
            if (isPrime(i))
            {
                int sum{0};
                bool found{false};
                for (auto &num : lst)
                {
                    if (num % i == 0)
                    {
                        sum += num;
                        found = true;
                    }
                }
                if (found)
                    factors += (open + std::to_string(i) + " " + std::to_string(sum) + close);
            }
            i++;
        }
        return factors;
    }
};

int main()
{

    std::vector<int> v{3, 5, 23, 31, 53, 61, 1373, 5653, 7451};

    for (auto &&i : v)
    {
        std::cout << isPrime(i) << std::endl;
    }

    // std::vector<int> lst{0, 1, 4, 12, 15, 30, -45};
    // std::cout << SumOfDivided::sumOfDivided(lst) << std::endl;
    // std::cout << "(2 12)(3 27)(5 15)" << std::endl;

    return 0;
}