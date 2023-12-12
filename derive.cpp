#include<iostream>
#include"header.h"
using namespace std;
string calculate_derivative(char variable,int power,int coefficient)
{
    int derivative_power,derivative_coefficient;
    derivative_coefficient=coefficient*power;
    derivative_power=power-1;
    string answer;
    if(variable=='\0')
    {
        answer+="0";
        cout<<"0"<<endl;
        return answer;
    }
    else if(derivative_coefficient!=1)
    {
        if(derivative_coefficient<0)
        {
            answer+='(';
            answer+=to_string(derivative_coefficient);
            answer+=')';
            cout<<"(";
            if(coefficient<0)
             {
                cout<<"("<<coefficient<<")";
             }
            else 
            {
                cout<<coefficient;
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
            cout<<")";
        }
        else 
        {
            answer+=to_string(derivative_coefficient);
            cout<<"(";
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
            if(coefficient!=1)
            {
                cout<<"*";
            }
            if(power<0)
            {
                cout<<"("<<power<<")";
            }
            else
            {
                cout<<power;
            }
            cout<<")";
        }
    }
    if(derivative_power!=0 && derivative_power!=1)
    {
        answer+="*";
        answer+=variable;
        answer+="^";
        cout<<"*"<<variable<<"^"<<"("<<power<<"-1)";
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
        if(derivative_coefficient==1 && derivative_power==0)
        {
            cout<<variable<<"^("<<power<<"-1)";
            answer="1";
        }
        else if(derivative_power==0)
        {
            cout<<"*"<<variable<<"^"<<"("<<power<<"-1)";
        }
        else if(derivative_power==1)
        {
           cout<<"*"<<variable<<"^"<<"("<<power<<"-1)";
           answer+="*";
           answer+=variable;
        }
    }
  return answer;      
}