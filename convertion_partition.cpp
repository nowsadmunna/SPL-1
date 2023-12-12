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
    char variable='\0',sign='\0';
    int power=1,coefficient=1;
    string co_coefficient,co_power;
    for(i=0;equation[i]!='\0'; )
    { 
        if(get_token[i]==1)
        {
            variable=equation[i];
            i++;
        }
        else if(get_token[i]==2)
        {
            if(equation[i-1]=='-' && equation[i-2]=='(')
            {
                co_coefficient+=equation[i-1];
            }
            while(1)
            {
                if(get_token[i]!=2)
                {
                    break;
                }
                else 
                {
                    co_coefficient+=equation[i];
                    i++;
                }
            }
            coefficient=stoi(co_coefficient);           
        }
        else if(get_token[i]==3)
        {
            if((equation[i]=='+' || equation[i]=='-') && (equation[i-1]!='('))
            {
                sign=equation[i];
                i++;
            }
            else
            {
                i++;
            }           
        }
        else if(get_token[i]==4)
        {
            if(equation[i+1]=='(' && equation[i+2]=='-')
            {
                co_power+=equation[i+2];
                i=i+2;
            }
            i++;
             while(1)
            {
                if(get_token[i]!=2)
                {
                    break;
                }
                else 
                {
                    co_power+=equation[i];
                    i++;
                }
            }
            power=stoi(co_power);
        }
        else if(get_token[i]==5)
        {
            i++;
        }
        if(sign=='+' || sign=='-')
        {
            answer+=calculate_derivative(variable,power,coefficient);
            answer+=sign;
            cout<<sign;
            sign='\0';
            coefficient=1;
            power=1;
            variable='\0';
            co_coefficient="";
            co_power="";
        }
    }
    answer+=calculate_derivative(variable,power,coefficient);
    if(answer!="0")
    {
        cout<<"="<<answer<<endl;
    }
    sign='\0';
    variable='\0';
    co_coefficient="";
    co_power="";
    return answer;
}
