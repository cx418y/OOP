#ifndef LAB3_GAME_CPP
#define LAB3_GAME_CPP

#include "board.cpp"
#include "input.cpp"
#include "output.cpp"
#include "scene.cpp"

class Game : public Scene
{
    Board *board = new Board(condition);
    Input *in = new Input(board);
    Output *out = new Output(board);

protected:
    Game() = default;

public:
    Scene *show() override
    {
        while (true)
        {
            output();
            switch (board->move(input()))
            {
                case Board::GAME_OVER:
                    Console::clear();
                    Game::output();
                    cout << "game over" << endl;
                    summary();
                    goto END;
                case Board::WIN:
                    Console::clear();
                    Game::output();
                    cout << "GAME COMPLETE" << endl;
                    summary();
                    goto END;
            }
        }
        END:
        Console::pause();
        return nullptr;
    }

protected:
    virtual Direction input()
    {
        return in->read();
    }

protected:
    virtual void output()
    {
        out->write();
    }

protected:
    virtual void summary() = 0;
};

#endif