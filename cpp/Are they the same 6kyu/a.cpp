#include <iostream>
#include <vector>

class Same
{
public:
    static bool comp(std::vector<int> &a, std::vector<int> &b)
    {
        if (a.size() != b.size())
            return false;

        for (size_t i = 0; i < a.size(); i++)
        {
            if (a[i] * a[i] != b[i])
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Same s;
    std::vector<int> a = {121, 144, 19, 161, 19, 144, 19, 11};
    std::vector<int> b = {14641, 20736, 361, 25921, 361, 20736, 361, 121};
    std::cout << s.comp(a, b);
    return 0;
}