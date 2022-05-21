#include <iostream>

#include <string>

std::string ToLower(const std::string &word)
{
    std::string str{};
    for (auto &&c : word)
    {
        if (c <= 'a')
        {
            str += char(c + ('a' - 'A'));
        }
        else
        {
            str += c;
        }
    }
    return str;
}

std::string duplicate_encoder(const std::string &word)
{
    std::string my_word = ToLower(word);
    std::string ret_value{};
    for (auto &chr : my_word)
    {
        size_t found_first{my_word.find(chr)};
        size_t found_last{my_word.find_last_of(chr)};

        if (found_first != found_last)
            ret_value += ")";
        else
            ret_value += "(";
    }
    return ret_value;
}

int main()
{
    std::cout << ")())())" << std::endl;
    std::cout << duplicate_encoder("Success") << std::endl;
    return 0;
}