#include <iostream>
using namespace std;

int main()
{
    char *srt[3] = {"stra", "strb", "strc"};
    char **p = &(srt[0]);
    int i = 3;
    while (i--)
        cout << *p++ << endl;
    return 0;
}