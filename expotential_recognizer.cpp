#include<iostream>
#include"header.h"
using namespace std;
int check_expotentail_function(string equation)
{
   int ln_count=500,trigonometry_count=500,root_count=500,expotential_count=500;
   int i;
   for(i=0;equation[i]!='\0';i++)
   {   
       if(equation[i]=='l' && equation[i+1]=='n')
       {
           ln_count=i;
           break;
       }
       else if(equation[i]=='s' && equation[i+1]=='q' && equation[i+2]=='r' && equation[i+3]=='t')
       {
           root_count=i;
           break;
       }
       else if(equation[i]=='t' || equation[i]=='s' || equation[i]=='c')
       {
           trigonometry_count=i;
           break;
       }
       else if(equation[i]=='e' && equation[i+1]=='^')
       {
        expotential_count=i;
        break;
       }
   }
   if(expotential_count<ln_count && expotential_count<trigonometry_count && expotential_count<root_count)
   {
    return 1;
   }
   else 
   {
    return 0;
   }
}
string as_expotential_function(string equation)
{
    string inside_of_ex,answer,algebric_part;
    inside_of_ex=inside_of_bracket(equation);
    if(inside_of_ex.size()==1 && inside_of_ex[0]=='x')
    {
        cout<<"e^(x)"<<endl;
        answer="e^(x)";
    }
    else if(check_algebric_equation(inside_of_ex)==1)
    {
        cout<<"e^("+inside_of_ex+")*";
        cout<<"d/dx("<<inside_of_ex<<")"<<endl;
        cout<<"d/dx("<<inside_of_ex<<")=";
        algebric_part=partitioning_equation(inside_of_ex);
        answer="e^("+inside_of_ex+")*("+algebric_part+")";
    }
    else 
    {
        cout<<"e^("+inside_of_ex+")*";
        cout<<"d/dx("<<inside_of_ex<<")"<<endl;
        answer="e^("+inside_of_ex+")*("+partition_based_on_operator(inside_of_ex)+")";
    }   
    return answer;
}
