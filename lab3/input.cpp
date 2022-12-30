#ifndef LAB3_INPUT_CPP
#define LAB3_INPUT_CPP

#include "board.cpp"
#include "console.cpp"

using namespace std;

class Input
{
    Board *board;
    string choices;
    vector<int> directions;

public:
    explicit Input(Board *board)
    {
        this->board = board;
    }

public:
    Direction read()
    {
        while (true)
        {
            choices.clear();
            directions.clear();
            add_direction("W", UP);
            add_direction("Z", DOWN);
            add_direction("A", LEFT);
            add_direction("S", RIGHT);
            return (Direction)directions[Console::choice(choices)];
        }
    }

private:
    void add_direction(const string &c, Direction d)
    {
        if (board->is_allowed(d))
        {
            choices.append(c);
            directions.push_back(d);
        }
    }
};

#endif