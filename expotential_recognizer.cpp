#include<iostream>
#include"header.h"
using namespace std;
int check_expotentail_function(string equation)
{
   int ln_count=500,trigonometry_count=500,root_count=500,expotential_count=500,inverse_trigonometry_count=500;
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
           if(equation[i+3]=='^' && equation[i+4]=='(' && equation[i+5]=='-' && equation[i+6]=='1' && equation[i+7]==')')
           {
                inverse_trigonometry_count=i;
                break;
           }
           else 
           {
            trigonometry_count=i;
            break;
           }
       }
       else if(equation[i]=='e' && equation[i+1]=='^')
       {
        expotential_count=i;
        break;
       }
   }
   if(expotential_count<ln_count && expotential_count<trigonometry_count && expotential_count<root_count && expotential_count<inverse_trigonometry_count)
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
        answer="e^(x)";
    }
    else 
    {
        answer="e^("+inside_of_ex+")*d/dx("+inside_of_ex+")";
    }   
    return answer;
}
