#include<iostream>
#include"header.h"
using namespace std;
string ans8="";
bool check_uv_function(string equation)
{
    int i;
    for(i=0;equation[i]!='\0';i++)
    {
        if(equation[i]=='*' && equation[i-1]==')' && equation[i+1]=='(')
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
string as_uv_function(string equation,string temporary)
{
    cout<<"As it follows uv method: "<<endl;
    cout<<"d/dx(u*v)="<<"u*d/dx(v)+v*d/dx(u)"<<endl;
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
    cout<<"u="<<u_part<<endl;
    cout<<"v="<<v_part<<endl;
    cout<<"d/dx("<<equation<<")="<<u_part<<"*d/dx"<<v_part<<"+"<<v_part<<"*d/dx"<<u_part<<endl;
    cout<<"d/dx"<<u_part<<"=";
    derivative_of_upart=partition_based_on_operator(remove_bracket(u_part),temporary);
    cout<<endl;
    cout<<"d/dx"<<v_part<<"=";
    derivative_of_vpart=partition_based_on_operator(remove_bracket(v_part),temporary);
    cout<<endl;
    answer+=v_part+"*("+derivative_of_upart+")+"+u_part+"*("+derivative_of_vpart+")";
    temporary+=answer;
    // cout<<"("<<derivative_of_upart<<")*"<<v_part<<" + "<<"("<<derivative_of_vpart<<")"<<"*"<<u_part<<endl;
    return answer;
}
string remove_bracket(string equation)
{
    //jdi jahmela hoy tahole stack diye korar try korbo
    string part;
    int i;
    for(i=1;i<equation.size()-1;i++)
    {
        part+=equation[i];
    }
    return part;
}

