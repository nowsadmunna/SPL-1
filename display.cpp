#include<iostream>
#include "header.h"
using namespace std;

string answer="";
void as_algebric(string equation)

void display()
{
        cout<<"Enter the equation that you want to differentiate"<<endl;
        cout<<"Option:"<<endl;
        cout<<"1.Input Equation"<<endl;
        cout<<"2.Exit"<<endl;
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;
        getchar();
        if(choice==1)
        {
            string equation;
            cout<<"Enter The Equation: ";
            getline(cin,equation);
            equation=removespaces(equation);
            cout<<equation<<endl;
           cout<<"Answer: ";
           bool uv_recognizer=check_uv_function(equation);
           if(uv_recognizer==true)
           {
                answer+=as_uv_function(equation);
           }
        }
}
string removespaces(string equation)
{
    string space_removal_string;
    int i;
    for(i=0;equation[i]!='\0';i++)
    {
        if(equation[i]==' ')
            {
                continue;
            }
        else
            {
                space_removal_string+=equation[i];
            }
    }
    return space_removal_string;
}
