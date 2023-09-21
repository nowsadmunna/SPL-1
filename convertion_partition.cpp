#include<iostream>
#include "header.h"
using namespace std;
int get_token[500];
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
string partitioning_equation(string equation)
{
    int i;
    for(i=0;equation[i]!='\0';i++)
    {
         if(an_alphabet(equation[i]))
         {
            get_token[i]=1;
         }
         else if(a_digit(equation[i]))
         {
            get_token[i]=2;
         }
         else if(an_operator(equation[i]))
         {
            get_token[i]=3;
         }
         else if(a_power(equation[i]))
         {
            get_token[i]=4;
         }
         else if(a_bracket(equation[i]))
         {
            get_token[i]=5;
         }
    }
    string answer="";
    char variable,sign='\0';
    int power=1,coefficient=1;
    for(i=0;equation[i]!='\0';i++)
    {
        if(get_token[i]==1)
        {
            variable=equation[i];
            if(get_token[i+1]!=4)
            {
                power=1;
            }
            if(equation[i-1]=='+')
            {
                coefficient=1;
            }
            else if(equation[i-1]=='-')
            {
                coefficient=-1;
            }
        }
        else if(get_token[i]==2)
        {
            if(equation[i+1]=='*')
            {
                coefficient=(int)(equation[i])-48;
            }
            if(equation[i-1]=='-' && equation[i-2]=='(')
            {
                coefficient=coefficient*(-1);
            }
            if(equation[i-2]!='^' && (equation[i-1]=='+' || equation[i-1]=='-') && (equation[i+1]=='+' || equation[i+1]=='-'))
            {
                coefficient=1401;
            }
            else if(equation[i-2]!='^' && (equation[i-1]=='+' || equation[i-1]=='-') && (equation[i+1]=='(' || equation[i+1]==')'))
            {
                coefficient=1402;
                variable=equation[i];
            }
            else if((equation[i-1]=='(' || equation[i-1]==')') && (equation[i+1]=='+' || equation[i+1]=='-'))
            {
                coefficient=1403;
                variable=equation[i];
            }
            else if((equation[i-1]=='(' || equation[i-1]==')')&&(equation[i+1]=='(' || equation[i+1]==')'))
            {
                coefficient=1404;
                variable=equation[i];
            }
        }
        else if(get_token[i]==3)
        {
            if(equation[i]=='*')
            {
                continue;
            }
            else if(equation[i-1]=='(')
            {
                continue;
            }
            else if(equation[i-1]!='^')
            {
                sign=equation[i];
            }
            else 
            {
                continue;
            }
        }
        else if(get_token[i]==4)
        {
            if(get_token[i+1]==2)
            {
                power=(int)(equation[i+1])-48;
            }
            else if(equation[i+1]=='-')
            {
                power=(int)(equation[i+2])-48;
                power=power*(-1);
            }

        }
        if(sign=='+' || sign=='-' || equation[i]==')')
        {
            
        }
    }
}

