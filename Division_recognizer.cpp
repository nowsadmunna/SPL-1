#include<iostream>
#include"header.h"
using namespace std;
bool check_udivv_function(string equation)
{
    int i;
    for(i=0;equation[i]!='\0';i++)
    {
        if(equation[i]=='/' && equation[i-1]==')' && equation[i+1]=='(')
        {
            return true;
        }
        else
        {
            continue;
        }
    }
    return false;
}
string as_udivv(string equation)
{
    string u_part,v_part,derivative_of_upart,derivative_of_vpart,answer;
    int i;
    int flag=0;
    for(i=0;i<equation.size();i++)
    {
        if(equation[i]=='/' && equation[i-1]==')' && equation[i+1]=='(')
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
    answer="("+v_part+"*d/dx("+remove_bracket(u_part)+")-"+u_part+"*d/dx("+remove_bracket(v_part)+"))/"+v_part+"^2";
    return answer;
}