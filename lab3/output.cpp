#ifndef LAB3_OUTPUT_CPP
#define LAB3_OUTPUT_CPP

#include <iostream>
#include "board.cpp"

using namespace std;

class Output
{
    const char *BLOCKS[12] = {"     ", "  2  ", "  4  ", "  8  ", " 16  ", " 32  ", " 64  ", " 128 ", " 256 ", " 512 ", "1024 ", "2048 "};

    Grid *grid;

public:
    explicit Output(Board *board)
    {
        this->grid = board;
    }

public:
    void write()
    {
        for (int i = 0; i < grid->get_size(); i++)
        {
            for (int j = 0; j < grid->get_size(); j++)
                cout << "+-----";
            cout << "+" << endl;
            for (int j = 0; j < grid->get_size(); j++)
                cout << "|" << BLOCKS[grid->get_cell(j, i)];
            cout << "|" << endl;
        }
        for (int j = 0; j < grid->get_size(); j++)
            cout << "+-----";
        cout << "+" << endl;
    }
};

#endif