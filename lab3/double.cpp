#ifndef LAB3_DOUBLE_CPP
#define LAB3_DOUBLE_CPP

#include <cstring>
#include "game.cpp"

using namespace std;

class Double : public Game
{
    string *player1;
    string *player2;

public:
    Double(string player1, string player2)
    {
        this->player1 = &player1;
        this->player2 = &player2;
    }
protected:
    void output() override
    {
        Console::clear();
        Game::output();
    }

protected:
    void summary() override
    {
        cout << "This is some summary" << endl;
    }
};

#endif