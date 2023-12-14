#include<iostream>
#include"header.h"
using namespace std;
int check_square_root_function(string equation)
{
   int ln_count=500,trigonometry_count=500,root_count=500,expotential_count=500;
   int i;
   for(i=0;equation[i]!='\0';i++)
   {   
       if(equation[i]=='l' && equation[i+1]=='n')
       {
           ln_count=i;
       }
       else if(equation[i]=='s' && equation[i+1]=='q' && equation[i+2]=='r' && equation[i+3]=='t')
       {
           root_count=i;
       }
       else if(equation[i]=='t' || equation[i]=='s' || equation[i]=='c')
       {
           trigonometry_count=i;
       }
       else if(equation[i]=='e' && equation[i+1]=='^')
       {
        expotential_count=i;
       }
   }
   if(root_count<expotential_count && root_count<trigonometry_count && root_count<ln_count)
   {
    return 1;
   }
   else 
   {
    return 0;
   }
}
string as_square_root_function(string equation)
{
    string inside_of_square_root,answer,algebric_part;
    inside_of_square_root=inside_of_bracket(equation);
     if(inside_of_square_root.size()==1 && inside_of_square_root[0]=='x')
    {
        cout<<"1/(2*sqrt(x))"<<endl;
        answer="1/(2*sqrt(x))";
    }
    else if(check_algebric_equation(inside_of_square_root)==1)
    {
        cout<<"(1/2*sqrt("+inside_of_square_root+"))*";
        cout<<"d/dx("<<inside_of_square_root<<")"<<endl;
        cout<<"d/dx("<<inside_of_square_root<<") =";
        algebric_part=partitioning_equation(inside_of_square_root);    
        cout<<endl;   
        answer="(1/2*sqrt("+inside_of_square_root+"))*("+algebric_part+")";
    }
    else 
    {
        cout<<"(1/2*sqrt("+inside_of_square_root+"))*";
        cout<<"d/dx("<<inside_of_square_root<<")"<<endl;
        answer="(1/2*sqrt("+inside_of_square_root+"))*("+partition_based_on_operator(inside_of_square_root)+")";
    }
    return answer;   
}
