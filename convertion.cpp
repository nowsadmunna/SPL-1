#include "header.h"
using namespace std;
int char_type(char c)
{
    if(an_alphabet(c))
    {
        return 1;
    }
    else if(a_digit(c))
    {
        return 2;
    }
    else if(an_operator(c))
    {
        return 3;
    }
    else if(a_power(c))
    {
        return 4;
    }
    else if(a_bracket(c))
    {
        return 5;
    }
    else
    {
        return 0;
    }
}
