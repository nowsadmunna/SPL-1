#include<iostream>
#include"header.h"
using namespace std;
int which_trigonometry=0;
int check_trigonometry_funtion(string equation)
{
   int ln_count=500,trigonometry_count=500,root_count=500,expotential_count=500,inverse_trigonometry_count=500;
   int i;
   which_trigonometry=0;
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
   if(ln_count<trigonometry_count)
   {
       return 0;
   }
   if(root_count<trigonometry_count)
   {
       return 0;
   }
   if(expotential_count<trigonometry_count)
   {
    return 0;
   }
   if(inverse_trigonometry_count<trigonometry_count)
   {
    return 0;
   }
   for(i=0;equation[i]!='\0';i++)
   {
       if(equation[i]=='s' && equation[i+1]=='i' && equation[i+2]=='n')
       {
           which_trigonometry=1;
           return 1;
       }
       else if(equation[i]=='t' && equation[i+1]=='a' && equation[i+2]=='n')
       {
           which_trigonometry=3;
           return 1;
       }
       else if(equation[i]=='s' && equation[i+1]=='e' && equation[i+2]=='c')
       {
           which_trigonometry=5;
           return 1;
       }
       else if(equation[i]=='c' && equation[i+1]=='s' && equation[i+2] =='c')
       {
           which_trigonometry=2;
           return 1;
       }
       else if(equation[i]=='c' && equation[i+1]=='o' && equation[i+2]=='s')
       {
           which_trigonometry=4;
           return 1;
       }
       else if(equation[i]=='c' && equation[i+1]=='o' && equation[i+2]=='t')
       {
           which_trigonometry=6;
           return 1;
       }
   }
    return 0;
}
int derivative_sign_of_trigonometry()
{
    return which_trigonometry;
}
string as_trigonometry_function(string equation)
{
    string inside_of_trigonometry,answer;
    inside_of_trigonometry=inside_of_bracket(equation);
    if(derivative_sign_of_trigonometry()==1)
    {
       if(inside_of_trigonometry.size()==1 && inside_of_trigonometry[0]=='x')
       {
            answer="cos(x)";
       }
       else
       {
            answer="cos("+inside_of_trigonometry+")*d/dx("+inside_of_trigonometry+")";
       }
    }
    else if(derivative_sign_of_trigonometry()==3)
    {
       if(inside_of_trigonometry.size()==1 && inside_of_trigonometry[0]=='x')
       {
            answer="sec^2(x)";
       }
       else
       {
            answer="sec^2("+inside_of_trigonometry+")*d/dx("+inside_of_trigonometry+")";
       }
    }
    else if(derivative_sign_of_trigonometry()==5)
    {
        if(inside_of_trigonometry.size()==1 && inside_of_trigonometry[0]=='x')
       {
            answer="sec(x)*tan(x)";
       }     
       else
       {
            answer="sec("+inside_of_trigonometry+")*"+"tan("+inside_of_trigonometry+")*d/dx("+inside_of_trigonometry+")";
       }
    }
    else if(derivative_sign_of_trigonometry()==2)
    {
         if(inside_of_trigonometry.size()==1 && inside_of_trigonometry[0]=='x')
       {
            answer="(-csc(x)*cot(x))";
       }  
       else
       {
            answer="(-csc("+inside_of_trigonometry+")*"+"cot("+inside_of_trigonometry+"))*d/dx("+inside_of_trigonometry+")";
       }
    }
    else if(derivative_sign_of_trigonometry()==4)
    {
       if(inside_of_trigonometry.size()==1 && inside_of_trigonometry[0]=='x')
       {
            answer="(-sin(x))";
       }     
       else
       {
            answer="(-sin("+inside_of_trigonometry+"))*d/dx("+inside_of_trigonometry+")";
       }
    }
    else if(derivative_sign_of_trigonometry()==6)
    {
        if(inside_of_trigonometry.size()==1 && inside_of_trigonometry[0]=='x')
       {
            answer="(-csc^2(x))";
       }     
       else
       {
            answer="(-csc^2("+inside_of_trigonometry+"))*d/dx("+inside_of_trigonometry+")";
       }
    }
    return answer;
}
string inside_of_bracket(string equation)
{
    stack<char>bracket;
    stack<int>index_of_bracket;
    string part;
    int i,x;
    for(i=0;i<equation.size();i++)
    {
        if(equation[i]=='(')
        {
            bracket.push(equation[i]);
            index_of_bracket.push(i);
        }
        else if(equation[i]==')')
        {
            if(bracket.size()==1)
            {
                x=i;
                break;
            }
            else 
            {
                bracket.pop();
                index_of_bracket.pop();
            }
        }
    }
    for(i=index_of_bracket.top()+1;i<x;i++)
    {
        part+=equation[i];
    }
    return part;
}
