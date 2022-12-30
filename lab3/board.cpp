#ifndef LAB3_BOARD_CPP
#define LAB3_BOARD_CPP

#include <random>
#include "direction.cpp"
#include "grid.cpp"

using namespace std;

class Board : public Grid
{
    int condition;
    bool allowed[4];
    int **transitions[4];
    default_random_engine engine;
    uniform_int_distribution<int> random;

public:
    enum Status {OK, GAME_OVER, WIN};

public:
    explicit Board(int condition) : Grid(4)
    {
        this->condition = condition;

        int len = get_size() * get_size();
        for (int i = 0; i < 4; i++)
            transitions[i] = (int **)malloc(sizeof(int *) * len);
        init_up();
        init_down();
        init_left();
        init_right();

        random = uniform_int_distribution<int>(0, len - 1);
        generate_random();
        generate_random();
        test_move();
    }

private:
    void init_up()
    {
        for (int i = 0; i < get_size(); i++)
        {
            for (int j = 0; j < get_size(); j++)
                *(transitions[UP] + get_size() * i + j) = cells + get_size() * j + i;
        }
    }

private:
    void init_down()
    {
        for (int i = 0; i < get_size(); i++)
        {
            for (int j = 0; j < get_size(); j++)
                *(transitions[DOWN] + get_size() * i + j) = cells + get_size() * (get_size() - j - 1) + i;
        }
    }

private:
    void init_left()
    {
        for (int i = 0; i < get_size() * get_size(); i++)
            *(transitions[LEFT] + i) = cells + i;
    }

private:
    void init_right()
    {
        for (int i = 0; i < get_size(); i++)
        {
            for (int j = 0; j < get_size(); j++)
                *(transitions[RIGHT] + get_size() * i + j) = cells + get_size() * i + get_size() - j - 1;
        }
    }

public:
    bool is_allowed(Direction direction)
    {
        return allowed[direction];
    }

private:
    bool test_move()
    {
        bool movable = false;
        int len = get_size() * get_size();
        int *cells_clone = (int *)malloc(sizeof(int) * len);
        copy(cells, cells_clone, len);

        for (int i = 0; i < 4; i++)
        {
            allowed[i] = false;
            int **p = transitions[i];
            for (int j = 0; j < get_size(); j++, p += get_size())
            {
                allowed[i] |= collapse(p);
                allowed[i] |= merge(p);
                if (allowed[i])
                {
                    copy(cells_clone, cells, len);
                    movable = true;
                    break;
                }
            }
        }

        free(cells_clone);
        return movable;
    }

private:
    void copy(int *from, int *to, int len)
    {
        while (len--)
            *(to++) = *(from++);
    }

public:
    Status move(Direction direction)
    {
        bool modified = false;
        int **p = transitions[direction];
        for (int i = 0; i < get_size(); i++, p += get_size())
        {
            modified |= collapse(p);
            modified |= merge(p);
            collapse(p);
        }
        generate_random();
        for (int i = 0; i < get_size() * get_size(); i++)
        {
            if (*(cells + i) == condition)
                return WIN;
        }
        return test_move() ? OK : GAME_OVER;
    }

private:
    bool collapse(int **p)
    {
        bool ret = false;
        int **cur = p;
        for (int i = 0; i < get_size(); i++, p++)
        {
            if (**p != 0)
            {
                if (cur != p)
                {
                    **cur = **p;
                    **p = 0;
                    ret = true;
                }
                cur++;
            }
        }
        return ret;
    }

private:
    bool merge(int **p)
    {
        bool ret = false;
        for (int i = 1; i < get_size(); i++, p++)
        {
            if (**p != 0 && **p == **(p + 1))
            {
                (**p)++;
                **(p + 1) = 0;
                ret = true;
            }
        }
        return ret;
    }

private:
    void generate_random()
    {
        while (true)
        {
            int *p = cells + random(engine);
            if (*p == 0)
            {
                *p = 1;
                break;
            }
        }
    }
};

#endif