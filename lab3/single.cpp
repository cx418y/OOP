#ifndef LAB3_SINGLE_CPP
#define LAB3_SINGLE_CPP

#include "console.cpp"
#include "game.cpp"

class Single : public Game
{
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