#ifndef LAB3_GRID_CPP
#define LAB3_GRID_CPP

#include <cassert>

class Grid
{
    int size;

protected:
    int *cells;

protected:
    explicit Grid(int size)
    {
        this->size = size;
        int len = size * size;
        cells = (int *)malloc(sizeof(int) * len);
        for (int i = 0; i < len; i++)
            *(cells + i) = 0;
    }

public:
    int get_size() const
    {
        return size;
    }

public:
    int get_cell(int x, int y)
    {
        assert(x >= 0 && x < size && y >= 0 && y < size);
        return *(cells + y * size + x);
    }
};

#endif