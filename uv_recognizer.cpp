#include<iostream>
#include"header.h"
using namespace std;
bool check_uv_function(string equation)
{
    int i;
    stack<char>bracket;
    for(i=0;i<equation.size();i++)
    {
        if(equation[i]=='(')
        {
            bracket.push('(');
        }
        else if(equation[i]==')')
        {
            bracket.pop();
        }
        else if(equation[i]=='*' && equation[i+1]=='(')
        {
            if(bracket.size()==0)
            {
                return true;
            }
        }
        else 
        {
            continue;
        }
    }
    return false;
}
string as_uv_function(string equation)
{
    string u_part,v_part,answer,derivative_of_upart,derivative_of_vpart;
    int i;
    int flag=0;
    for(i=0;i<equation.size();i++)
    {
        if(equation[i]=='*' && equation[i-1]==')' && equation[i+1]=='(')
        {
            flag=1;
        }
        else if(flag==0)
        {
            u_part+=equation[i];
        }
        else if(flag==1)
        {
            v_part+=equation[i];
        }
    }
    answer=u_part+"*d/dx("+remove_bracket(v_part)+")+"+v_part+"*d/dx("+remove_bracket(u_part)+")";
    return answer;
}
string remove_bracket(string equation)
{
    string after_removing_bracket;
    if(equation[0]=='(' && equation[equation.size()-1]==')')
    {
        int i;
        for(i=1;i<equation.size()-1;i++)
        {
            after_removing_bracket+=equation[i];
        }
        return after_removing_bracket;
    }
    else 
    {
        return equation;
    }
}

