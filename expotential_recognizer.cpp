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
string as_expotential_function(string equation,string temporary)
{
    string inside_of_ex,answer;
    inside_of_ex=inside_of_bracket(equation);
    // cout<<"As it is a expotential function.it will follow the expotential rule: "<<endl;
    // cout<<"d/dx(e^(x))=e^(x)"<<endl;
    // cout<<"d/dx("<<equation<<")= "<<"e^("<<inside_of_ex<<")* d/dx("<<inside_of_ex<<")"<<endl;
    if(inside_of_ex.size()==1 && inside_of_ex[0]=='x')
    {
        temporary+="e^(x)";
        cout<<temporary<<endl;
        answer="e^(x)";
    }
    else if(check_algebric_equation(inside_of_ex)==1)
    {
        temporary+="e^("+inside_of_ex+")*";
        cout<<temporary<<"d/dx("<<inside_of_ex<<")"<<endl;
        cout<<temporary<<"("<<partitioning_equation(inside_of_ex,temporary)<<")"<<endl;
        if(partitioning_equation(inside_of_ex,temporary)=="0")
        {
            answer="0";
        }
        else 
        {
            answer="e^("+inside_of_ex+")*("+partitioning_equation(inside_of_ex,temporary)+")";
        }
    }
    else 
    {
        temporary+="e^("+inside_of_ex+")*";
        cout<<temporary<<"d/dx("<<inside_of_ex<<")"<<endl;
        answer="e^("+inside_of_ex+")*("+partition_based_on_operator(inside_of_ex,temporary)+")";
    }   
    return answer;
}
