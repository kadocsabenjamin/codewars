#include <iostream>

#include <string>
#include <unordered_map>
#include <vector>
#include <type_traits>

struct Assembler
{
    struct Register
    {
        std::string name;
        int data;
    };

    Assembler(const std::vector<std::string> &program);
    void Run();

    void Move(std::string regName, std::string data);
    void Increment(std::string regName);
    void Decrement(std::string regName);
    bool JumpNotZero(std::string arg);

    void DecrementLineCounter(std::string regName);

    std::vector<std::string> tasks;

    std::vector<Register> registers;
    int lineCounter;
};

Assembler::Assembler(const std::vector<std::string> &program)
    : tasks(program), lineCounter(0)
{
    Register temp_const;
    temp_const.data = 0;
    temp_const.name = "temp";
    registers.push_back(temp_const);
    Run();
}

void Assembler::Run()
{
    while (lineCounter < tasks.size())
    {
        std::string currTask = tasks[lineCounter];
        std::vector<std::string> currInstructions;

        size_t pos = 0;
        while ((pos = currTask.find(" ")) != std::string::npos)
        {
            currInstructions.push_back(currTask.substr(0, pos));
            currTask.erase(0, pos + 1);
        }
        currInstructions.push_back(currTask);

        if (currInstructions[0] == "inc")
        {
            Increment(currInstructions[1]);
        }
        else if (currInstructions[0] == "dec")
        {
            Decrement(currInstructions[1]);
        }
        else if (currInstructions[0] == "mov")
        {
            Move(currInstructions[1], currInstructions[2]);
        }
        else if (currInstructions[0] == "jnz")
        {
            if (currInstructions[1][0] == '-')
            {
                registers[0].data = std::stoi(currInstructions[1].substr(1)) * -1;
            }
            else
            {
                registers[0].data = std::stoi(currInstructions[1]);
            }

            JumpNotZero(currInstructions[1]);
            tasks[lineCounter] = currInstructions[0] + " " + std::to_string(std::stoi(currInstructions[1]) - 1) + currInstructions[2];
            DecrementLineCounter(currInstructions[2]);
        }

        lineCounter++;
    }
}

void Assembler::Increment(std::string regName)
{
    for (auto &r : registers)
    {
        if (r.name == regName)
        {
            r.data++;

            return;
        }
    }
}

void Assembler::Decrement(std::string regName)
{
    for (auto &r : registers)
    {
        if (r.name == regName)
        {
            r.data--;

            return;
        }
    }
}

void Assembler::Move(std::string regName, std::string data)
{
    for (auto &r : registers)
    {
        if (r.name == regName)
        {
            for (auto &rr : registers)
            {
                if (rr.name == data)
                {
                    r.data = rr.data;

                    return;
                }
            }

            r.data = std::stoi(data);

            return;
        }
    }

    Register temp;
    temp.data = std::stoi(data);
    temp.name = regName;

    registers.push_back(temp);
}

bool Assembler::JumpNotZero(std::string arg)
{
    bool ArgIsReg{false};
    int f = 0;

    for (auto &r : registers)
    {
        if (r.name == arg)
        {
            ArgIsReg = true;
            break;
        }
        f++;
    }

    if (ArgIsReg)
    {
        return registers[f].data > 0;
    }
}

void Assembler::DecrementLineCounter(std::string regName)
{
    for (auto &r : registers)
    {
        if (r.name == regName)
        {
            lineCounter = lineCounter - r.data;

            return;
        }
    }

    lineCounter = lineCounter - std::stoi(regName);
}

std::unordered_map<std::string, int> assembler(const std::vector<std::string> &program)
{
    Assembler myAssebler(program);
}

int main()
{
    std::vector<std::string> program{"mov a 5", "inc a", "dec a", "dec a",
                                     "jnz a -1", "inc a"};
    assembler(program);
    return 0;
}