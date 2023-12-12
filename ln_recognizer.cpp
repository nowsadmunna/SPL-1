#include<iostream>
#include"header.h"
using namespace std;
int check_ln_function(string equation)
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
   if(ln_count<expotential_count && ln_count<trigonometry_count && ln_count<root_count)
   {
    return 1;
   }
   else 
   {
    return 0;
   }
}
string as_ln_function(string equation)
{
    string inside_of_ln,answer;
    inside_of_ln=inside_of_bracket(equation);
    // cout<<"As it is a ln function.it will follow the logarithm rule: "<<endl;
    // cout<<"d/dx(ln(x))=1/x"<<endl;
    // cout<<"d/dx("<<equation<<")= "<<endl;
    if(inside_of_ln.size()==1 && inside_of_ln[0]=='x')
    {
        temporary+="1/x";
        cout<<"1/x"<<endl;
        answer="1/x";
    }
    else if(check_algebric_equation(inside_of_ln)==1)
    {
        temporary+="(1/("+inside_of_ln+"))*";
        cout<<"(1/("<<inside_of_ln<<"))*"<<"d/dx("<<inside_of_ln<<")"<<endl;
        cout<<temporary<<"("<<partitioning_equation(inside_of_ln)<<")"<<endl;
        if(partitioning_equation(inside_of_ln)=="0")
        {
            answer="0";
        }
        else 
        {
            answer="(1/("+inside_of_ln+"))*("+partitioning_equation(inside_of_ln)+")";
        }
    }
    else 
    {
        temporary+="(1/("+inside_of_ln+"))*";
        cout<<"(1/("<<inside_of_ln<<"))*"<<"d/dx("<<inside_of_ln<<")"<<endl;
        answer="(1/("+inside_of_ln+"))*("+partition_based_on_operator(inside_of_ln)+")";
    }   
    return answer;
}
