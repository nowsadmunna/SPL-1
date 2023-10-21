#include<iostream>
#include "header.h"
using namespace std;

// string answer="";
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
// void as_algebric(string equation)
// {
//     int single_or_multiple=check_u_or_uplusv(equation);
//     if(single_or_multiple==0)
//     {
//         cout<<"The formula for solving this equation: "<<endl;
//         cout<<"                                      d/dx(x^n)= nx^(n-1)"<<endl;
//     }
//     else 
//     {
//         cout<<"The formula for solving this equation: "<<endl;
//         cout<<"                                      d/dx(u+v)= d/dx(u)+d/dx(v)"<<endl;
//         cout<<"The power formula is also needed: "<<endl;
//         cout<<"                                  d/dx(x^n)= nx^(n-1)"<<endl;                                      
//     }
//     cout<<"Given Equation: "<<endl;
//     cout<<"f(x)= "<<equation<<endl;
//     cout<<"d/dx(f(x))=d/dx("<<equation<<")"<<endl;
//     if(single_or_multiple>0)
//     {
//         show_as_uplusv(equation);
//     }
//     cout<<"         =";
//     //answer

// }
// //-5*x+6*x//-5*x
// int check_u_or_uplusv(string equation)
// {
//     int plus_or_minus_count=0;
//     for(int i=0;i<equation.size();i++)
//     {

//         if((equation[i]=='+' || equation[i]=='-') && (equation[i-1]!='('))
//             {
//                 plus_or_minus_count++;
//             }
//         else 
//             {
//                 continue;
//             }
//     }
//     return plus_or_minus_count;
// }
// //5*x^2+6*x^-2=d/dx(5*x^2)+d/dx(6*x^-2)
// void show_as_uplusv(string equation)
// {
//     string temporary_u_or_v="";
//     char get_symbol='\0';
//     int i;
//     for(i=0;i<equation.size();i++)
//     {
//         if((equation[i]=='+' || equation[i]=='-') && (equation[i-1]!='(') && (equation[i-1]!='^'))
//         {
//             cout<<"d/dx("<<temporary_u_or_v<<")"<<equation[i];
//             temporary_u_or_v="";
//         }
//         else if(equation[i]=='(' || equation[i]==')')
//         {
//             continue;
//         }
//         else 
//         {
//             temporary_u_or_v+=equation[i];
//         }
//     }
//     cout<<"d/dx("<<temporary_u_or_v<<')'<<endl;
        
// }
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
string initial_checking(string equation,string temporary)
{
    string answer_for="";
    // if(check_uv_function(equation))
    // {
    //     answer_for+=as_uv_function(equation);
    // }
    // else if(check_udivv_function(equation))
    // {
    //     answer_for+=as_udivv(equation);
    // }
    // else 
    //{
        if(check_trigonometry_funtion(equation))
        {
            answer_for+=as_trigonometry_function(equation,temporary);
        }
        else if(check_ln_function(equation))
        {
            answer_for+=as_ln_function(equation,temporary);
        }
        else if(check_expotentail_function(equation))
        {
            answer_for+=as_expotential_function(equation,temporary);
        }
        else if(check_square_root_function(equation))
        {
            answer_for+=as_square_root_function(equation,temporary);
        }
        else 
        {
            answer_for+=partitioning_equation(equation);
        }
    //}
    return answer_for;
}
string partition_based_on_operator(string equation,string temporary)
{
    string part,answer;
    stack<char>bracket;
    int i;
    for(i=0;i<equation.size();i++)
    {
        if(equation[i]=='(')
        {
            bracket.push(equation[i]);
            part+=equation[i];
        }
        else if(equation[i]==')')
        {
            bracket.pop();
            part+=equation[i];
        }
        else if(equation[i]=='+' || equation[i]=='-')
        {
            //cout<<bracket.size()<<endl;

            if(bracket.size()==0)
            {
                //cout<<part<<endl;
                answer+=initial_checking(part,temporary);
                answer+=equation[i];
                part="";
            }
            else 
            {
                part+=equation[i];
            }
        }
        else 
        {
            part+=equation[i];
        }
    }
   // cout<<part<<endl;
    answer+=initial_checking(part,temporary);
    return answer;
}

