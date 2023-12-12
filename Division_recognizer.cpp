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
    cout<<"As it follows the devide Rule: "<<endl;
    cout<<"          (v*d/dx(u)-u*d/dx(v))"<<endl;
    cout<<"d/dx(u/v)=---------------------"<<endl;
    cout<<"                    v^2        "<<endl;
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
    cout<<"u="<<u_part<<endl;
    cout<<"v="<<v_part<<endl;
    for(i=0;i<equation.size()+8;i++)
    {
        cout<<" ";
    }
    cout<<v_part<<"*d/dx"<<u_part<<"-"<<u_part<<"*d/dx"<<v_part<<endl;
    cout<<"d/dx("<<equation<<")=----------------------------------------------------------"<<endl;
    cout<<"                                          "<<v_part<<"^2"<<endl;
    cout<<"calculating the dervaive of "<<u_part<<" -"<<endl;
    derivative_of_upart=partition_based_on_operator(remove_bracket(u_part));
    cout<<"d/dx"<<u_part<<"="<<derivative_of_upart<<endl;
    cout<<"calculating the dervaive of "<<v_part<<endl;
    derivative_of_vpart=partition_based_on_operator(remove_bracket(v_part));
    cout<<"d/dx"<<v_part<<"="<<derivative_of_vpart<<" -"<<endl;
    answer="("+v_part+"*("+derivative_of_upart+")-"+u_part+"*("+derivative_of_vpart+"))"+"/("+v_part+")"+"^2";
    for(i=0;i<equation.size()+8;i++)
    {
        cout<<" ";
    }
    cout<<v_part<<"*("<<derivative_of_upart<<")-"<<u_part<<"*("<<derivative_of_vpart<<")"<<endl;
    cout<<"d/dx("<<equation<<")=--------------------------------------------------------"<<endl;
    cout<<"                                             "<<v_part<<"^2"<<endl;
    return answer;
}