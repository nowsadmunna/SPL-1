#include<iostream>
#include"header.h"
using namespace std;
char another_sign='\0';
string calculate_derivative(char variable,int power,int coefficient,char sign,string temporary)
{
    int derivative_power,derivative_coefficient;
    derivative_coefficient=coefficient*power;
    derivative_power=power-1;
    string answer;
    if(another_sign=='+' || another_sign=='-')
    {
        answer+=another_sign;
        //cout<<another_sign;
    }
    if(variable=='\0')
    {
        answer+="0";
        //cout<<"0";
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
            // cout<<"(";
            temporary+="(";
            if(coefficient<0)
             {
                //cout<<"("<<coefficient<<")";
                temporary+="("+to_string(coefficient)+")";
             }
            else 
            {
                //cout<<coefficient;
                temporary+=to_string(coefficient);
            }
            //cout<<"*";
            temporary+="*";
            if(power<0)
            {
                //cout<<"("<<power<<")";
                temporary+="("+to_string(power)+")";
            }
            else
            {
                //cout<<power;
                temporary+=to_string(power);
            }
            //cout<<")";
            temporary+=")";
        }
        else 
        {
            answer+=to_string(derivative_coefficient);
            //cout<<"(";
            temporary+="(";
            if(coefficient<0)
            {
                //cout<<"("<<coefficient<<")";
                temporary+="("+to_string(coefficient)+")";
            }
            else 
            {
                if(coefficient!=1)
                {
                    //cout<<coefficient;
                    temporary+=to_string(coefficient);
                }
            }
            if(coefficient!=1)
            {
                //cout<<"*";
                temporary+="*";
            }
            if(power<0)
            {
                //cout<<"("<<power<<")";
                temporary+="("+to_string(power)+")";
            }
            else
            {
                //cout<<power;
                temporary+=to_string(power);
            }
            //cout<<")";
            temporary+=")";
        }
    }
    if(derivative_coefficient==1 && derivative_power==0)
    {
        answer+="1";
        //cout<<"1";
    }
    if(derivative_power!=0)
    {
        answer+="*";
        answer+=variable;
        if(derivative_power!=1)
        temporary+="*"+variable;
        //cout<<"*"<<variable;
    }
    if(derivative_power!=0 && derivative_power!=1)
    {
        answer+="^";
        // cout<<"^"<<"("<<power<<"-1)";
        temporary+="^("+to_string(power)+"-1)";
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
        //cout<<"*"<<variable<<"^"<<"("<<power<<"-1"<<")";
        temporary+="*";
        temporary+=variable;
        temporary+="^("+to_string(power)+"-1)";
    }
    cout<<temporary<<endl;
  another_sign=sign;
  return answer;      
}