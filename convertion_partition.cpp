#include<iostream>
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
bool an_alphabet(char c)
{
    if((c>='a' && c<='z') || (c>='A' && c<='Z'))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool a_digit(char c)
{
    if(c>='0' && c<='9')
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool an_operator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/')
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool a_power(char c)
{
    if(c=='^')
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool a_bracket(char c)
{
    if(c=='(' || c==')' || c=='[' || c==']' || c=='{' || c=='}')
        {
            return true;
        }
        else
        {
            return false;
        }
}

