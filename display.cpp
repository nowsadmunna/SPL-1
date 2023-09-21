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
void uplusv(string equ, char caa)
{
    //etar kaj holo + ar - ar vittite partiton kore d/dx(u) akare dekhano
    int x13=0;
    char s13='\0';
    string temp_equ = "";
    for(int i=0; i<equ.size(); i++)
    {
        x13 = char_type(equ[i]);
        if(x13==3)
        {
            if(equ[i-1]=='(')
                continue;
            else if(equ[i]=='*')
            {
                temp_equ += equ[i];
                continue;
            }
            else if(equ[i-1]!='^')
                s13 = equ[i];
            else {
                temp_equ += equ[i];
                continue;
            }
        }
        if(equ[i]=='(')
            continue;
        if(s13=='\0')
            temp_equ += equ[i];

        if(s13=='+' || s13=='-' || equ[i]==')')
        {
            cout<<"d/d"<<caa<<"(";
            if(equ[i]==')')
                cout<<temp_equ;
            else
                cout<<temp_equ<<") "<<s13<<" ";
            temp_equ = "";
        }
         s13 = '\0';
    }
    cout<<"\n\n\t\t\t    =  ";
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
