#include "header.h"
using namespace std;
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
    if(c>='0' && s<='9')
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
