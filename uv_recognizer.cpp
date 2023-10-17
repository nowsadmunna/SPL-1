#include<iostream>
#include"header.h"
using namespace std;
string ans8="";
bool check_uv_function(string equation)
{
    int i;
    for(i=0;equation[i]!='\0';i++)
    {
        if(equation[i]=='*' && equation[i-1]==')' && (equation[i+1]='(' || (equation[i+1]>96 && equation[i+1]<123)))
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
string as_uv_function(string equation)
{
    string u_part,v_part;
    int i;
    int flag=0;
    for(i=0;i<equation.size();i++)
    {
        if(equation[i]=='*' && equation[i-1]==')' && equation[i+1]=='(')
        {
            flag=1;
        }
        if(flag==0)
        {
            u_part+=equation[i];
        }
        if(flag==1)
        {
            v_part+=equation[i];
        }
    }
    cout<<u_part<<" "<<v_part<<endl;
}

