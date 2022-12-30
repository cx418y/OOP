#include <cstring>
#include "title.cpp"

using namespace std;

int main(int argc, char **argv)
{
    condition = (argc > 1 && strcmp(argv[1], "-t") == 0) ? 3 : 11;
    Scene *scene = new Title();
    while (scene)
        scene = scene->show();
    return 0;
}