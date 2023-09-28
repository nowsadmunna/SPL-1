#include<iostream>
#include "header.h"
using namespace std;

string answer="";
void as_algebric(string equation)
{
    int single_or_multiple=check_u_or_uplusv(equation);
    if(single_or_multiple==0)
    {
        cout<<"The formula for solving this equation: "<<endl;
        cout<<"                                      d/dx(x^n)= nx^(n-1)"<<endl;
    }
    else 
    {
        cout<<"The formula for solving this equation: "<<endl;
        cout<<"                                      d/dx(u+v)= d/dx(u)+d/dx(v)"<<endl;                                      
    }
    cout<<"Given Equation: "<<endl;
    cout<<"f(x)= "<<equation<<endl;
    cout<<"d/dx(f(x))=d/dx("<<equation<<")"<<endl;
    if(single_or_multiple>0)
    {

    }
}
int check_u_or_uplusv(string equation)
{
    int plus_or_minus_count=0;
    for(int i=0;i<equation.size();i++)
    {
            if(equation[i]=='+' || equation[i]=='-')
            {
                plus_or_minus_count++;
            }
            else 
            {
                continue;
            }
    }
    return plus_or_minus_count;
}
//5*x^2+6*x^-2=d/dx(5*x^2)+d/dx(6*x^-2)
void show_as_uplusv(string equation)
{
    string temporary_u_or_v="";
    char get_symbol='\0';
    int i;
    for(i=0;i<equation.size();i++)
    {
        if(equation[i]=='('|| equation[i]==')')
        {
            continue;
        }
        if(equation[i]=='+' || equation[i]=='-')
        {
            if(equation[i-1]=='(')
            {
                continue;
            }
           else if(equation[i-1]!='^')
           {
                get_symbol=equation[i];
           }
           else 
           {
            temporary_u_or_v+=equation[i];
            continue;
           }
        }
        if
    }
}
// void display()
// {
//         cout<<"Enter the equation that you want to differentiate"<<endl;
//         cout<<"Option:"<<endl;
//         cout<<"1.Input Equation"<<endl;
//         cout<<"2.Exit"<<endl;
//         cout<<"Enter your choice: ";
//         int choice;
//         cin>>choice;
//         getchar();
//         if(choice==1)
//         {
//             string equation;
//             cout<<"Enter The Equation: ";
//             getline(cin,equation);
//             equation=removespaces(equation);
//             cout<<equation<<endl;
//            cout<<"Answer: ";
//            bool uv_recognizer=check_uv_function(equation);
//            if(uv_recognizer==true)
//            {
//                 answer+=as_uv_function(equation);
//            }
//         }
// }
// string removespaces(string equation)
// {
//     string space_removal_string;
//     int i;
//     for(i=0;equation[i]!='\0';i++)
//     {
//         if(equation[i]==' ')
//             {
//                 continue;
//             }
//         else
//             {
//                 space_removal_string+=equation[i];
//             }
//     }
//     return space_removal_string;
// }
