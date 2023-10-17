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
    string u_part,v_part,derivative_of_upart,derivative_of_vpart;
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
    cout<<u_part<<" "<<v_part<<endl;
    derivative_of_upart=partitioning_equation(u_part);
    derivative_of_vpart=partitioning_equation(v_part);
    cout<<"("<<derivative_of_upart<<")*"<<v_part<<" + "<<"("<<derivative_of_vpart<<")"<<"*"<<u_part<<endl;
    return " ";
}

