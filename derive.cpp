#include<iostream>
#include"header.h"
using namespace std;
char another_sign='\0';
string calculate_derivative(char variable,int power,int coefficient,char sign)
{
    int derivative_power,derivative_coefficient;
    derivative_coefficient=coefficient*power;
    derivative_power=power-1;
    string answer;
    if(another_sign=='+' || another_sign=='-')
    {
        answer+=another_sign;
        cout<<another_sign;
    }
    if(variable=='\0')
    {
        answer+="0";
        cout<<"0";
        another_sign=sign;
        return answer;
    }
    else if(derivative_coefficient!=1)
    {
        if(derivative_coefficient<0)
        {
            answer+='(';
            answer+=to_string(derivative_coefficient);
            answer+=')';
            if(coefficient<0)
            {
                cout<<"("<<coefficient<<")";
            }
            else 
            {
                if(coefficient!=1)
                {
                    cout<<coefficient;
                }
            }
            cout<<"*";
            if(power<0)
            {
                cout<<"("<<power<<")";
            }
            else
            {
                cout<<power;
            }
            }
        else 
        {
            answer+=to_string(derivative_coefficient);
            if(coefficient<0)
            {
                cout<<"("<<coefficient<<")";
            }
            else 
            {
                if(coefficient!=1)
                {
                    cout<<coefficient;
                }
            }
            cout<<"*";
            if(power<0)
            {
                cout<<"("<<power<<")";
            }
            else
            {
                cout<<power;
            }
        }
    }
    if(derivative_coefficient==1 && derivative_power==0)
    {
        answer+="1";
        cout<<"1";
    }
    if(derivative_power!=0)
    {
        answer+="*";
        answer+=variable;
        //cout<<"*"<<variable;
    }
    if(derivative_power!=0 && derivative_power!=1)
    {
        answer+="^";
        cout<<"^"<<"("<<power<<"-1)";
        if(derivative_power<0)
        {
            answer+="(";
            answer+=to_string(derivative_power);
            answer+=")";
        }
        else 
        {
            answer+=to_string(derivative_power);
        }
    }
    else
    {
        cout<<"*"<<variable<<"^"<<"("<<power<<"-1"<<")";
    }
  another_sign=sign;
  return answer;      
}