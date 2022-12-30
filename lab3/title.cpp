#ifndef LAB3_TITLE_CPP
#define LAB3_TITLE_CPP

#include <iostream>
#include "console.cpp"
#include "double.cpp"
#include "scene.cpp"
#include "single.cpp"

using namespace std;

class Title : public Scene
{
public:
    Scene *show() override
    {
        cout << "---------- 2048 ----------" << endl;
        cout << endl;
        cout << "Choose a game mode:" << endl;
        cout << "[1] Singleplayer" << endl;
        cout << "[2] Doubleplayer" << endl;

        Scene *scene;
        switch (Console::choice("12"))
        {
            case 0:
                scene = new Single();
                break;
            case 1:
                cout << endl;
                string player1, player2;
                cout << "Enter player1's name:" << endl;
                cin >> player1;
                cin.sync();
                cout << "Enter player2's name:" << endl;
                cin >> player2;
                cin.sync();
                scene = new Double(player1, player2);
                break;
        }
        return scene;
    }
};

#endif