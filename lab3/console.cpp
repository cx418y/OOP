#ifndef LAB3_CONSOLE_CPP
#define LAB3_CONSOLE_CPP

#include <cstring>

using namespace std;

class Console
{
private:
    Console() = default;

public:
    static int choice(const string &choices)
    {
        return system(("CHOICE /C " + choices + " /N").c_str()) - 1;
    }

    static void clear()
    {
        system("CLS");
    }

    static void pause()
    {
        system("PAUSE");
    }
};

#endif