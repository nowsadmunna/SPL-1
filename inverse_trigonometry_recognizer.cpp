#include<iostream>
#include"header.h"
int which_inverse_trigonometry;
int check_inverse_trigonometry_funtion(string equation)
{
   int ln_count=500,trigonometry_count=500,root_count=500,expotential_count=500,inverse_trigonometry_count=500;
   int i;
   which_inverse_trigonometry=0;
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
   if(ln_count<inverse_trigonometry_count)
   {
       return 0;
   }
   if(root_count<inverse_trigonometry_count)
   {
       return 0;
   }
   if(expotential_count<inverse_trigonometry_count)
   {
    return 0;
   }
   if(trigonometry_count<inverse_trigonometry_count)
   {
    return 0;
   }
   for(i=0;equation[i]!='\0';i++)
   {
       if(equation[i]=='s' && equation[i+1]=='i' && equation[i+2]=='n' && equation[i+3]=='^' && equation[i+4]=='(' && equation[i+5]=='-' && equation[i+6]=='1' && equation[i+7]==')')
       {
           which_inverse_trigonometry=1;
           return 1;
       }
       else if(equation[i]=='t' && equation[i+1]=='a' && equation[i+2]=='n' && equation[i+3]=='^' && equation[i+4]=='(' && equation[i+5]=='-' && equation[i+6]=='1' && equation[i+7]==')')
       {
           which_inverse_trigonometry=3;
           return 1;
       }
       else if(equation[i]=='s' && equation[i+1]=='e' && equation[i+2]=='c' && equation[i+3]=='^' && equation[i+4]=='(' && equation[i+5]=='-' && equation[i+6]=='1' && equation[i+7]==')')
       {
           which_inverse_trigonometry=5;
           return 1;
       }
       else if(equation[i]=='c' && equation[i+1]=='s' && equation[i+2] =='c' && equation[i+3]=='^' && equation[i+4]=='(' && equation[i+5]=='-' && equation[i+6]=='1' && equation[i+7]==')')
       {
           which_inverse_trigonometry=2;
           return 1;
       }
       else if(equation[i]=='c' && equation[i+1]=='o' && equation[i+2]=='s' && equation[i+3]=='^' && equation[i+4]=='(' && equation[i+5]=='-' && equation[i+6]=='1' && equation[i+7]==')')
       {
           which_inverse_trigonometry=4;
           return 1;
       }
       else if(equation[i]=='c' && equation[i+1]=='o' && equation[i+2]=='t' && equation[i+3]=='^' && equation[i+4]=='(' && equation[i+5]=='-' && equation[i+6]=='1' && equation[i+7]==')')
       {
           which_inverse_trigonometry=6;
           return 1;
       }
   }
    return 0;
}
int derivative_sign_of_inverse_trigonometry()
{
    return which_inverse_trigonometry;
}
string as_inverse_trigonometry_function(string equation)
{
    string answer;
    string inside_of_inverse_trigonometry=inside_of_inverse_bracket(equation);
    if(derivative_sign_of_inverse_trigonometry()==1)
    {
       if(inside_of_inverse_trigonometry.size()==1 && inside_of_inverse_trigonometry[0]=='x')
       {
            answer="1/sqrt(1-x^2)";
       }
       else
       {
            answer="1/sqrt(1-("+inside_of_inverse_trigonometry+")^2)*d/dx("+inside_of_inverse_trigonometry+")";
       }
    }
    else if(derivative_sign_of_inverse_trigonometry()==3)
    {
       if(inside_of_inverse_trigonometry.size()==1 && inside_of_inverse_trigonometry[0]=='x')
       {
            answer="1/(1+x^2)";
       }
       else
       {
            answer="1/(1+("+inside_of_inverse_trigonometry+")^2)*d/dx("+inside_of_inverse_trigonometry+")";
       }
    }
    else if(derivative_sign_of_inverse_trigonometry()==5)
    {
        if(inside_of_inverse_trigonometry.size()==1 && inside_of_inverse_trigonometry[0]=='x')
       {
            answer="1/x*sqrt(x^2-1)";
       }     
       else
       {
            answer="1/("+inside_of_inverse_trigonometry+")*sqrt(("+inside_of_inverse_trigonometry+")^2-1)*d/dx("+inside_of_inverse_trigonometry+")";
       }
    }
    else if(derivative_sign_of_inverse_trigonometry()==2)
    {
         if(inside_of_inverse_trigonometry.size()==1 && inside_of_inverse_trigonometry[0]=='x')
       {
            answer="(-1)/x*sqrt(x^2-1)";
       }  
       else
       {
            answer="(-1)/("+inside_of_inverse_trigonometry+")*sqrt(("+inside_of_inverse_trigonometry+")^2-1)*d/dx("+inside_of_inverse_trigonometry+")";
       }
    }
    else if(derivative_sign_of_inverse_trigonometry()==4)
    {
       if(inside_of_inverse_trigonometry.size()==1 && inside_of_inverse_trigonometry[0]=='x')
       {
            answer="(-1)/sqrt(1-x^2)";
       }     
       else
       {
            answer="(-1)/sqrt(1-("+inside_of_inverse_trigonometry+")^2)*d/dx("+inside_of_inverse_trigonometry+")";
       }
    }
    else if(derivative_sign_of_inverse_trigonometry()==6)
    {
        if(inside_of_inverse_trigonometry.size()==1 && inside_of_inverse_trigonometry[0]=='x')
       {
            answer="(-1)/(1+x^2)";
       }     
       else
       {
            
            answer="(-1)/(1+("+inside_of_inverse_trigonometry+")^2)*d/dx("+inside_of_inverse_trigonometry+")";
       }
    }
    return answer;
}
string inside_of_inverse_bracket(string equation)
{
    stack<char>bracket;
    stack<int>index_of_bracket;
    string part;
    int i,x;
    for(i=8;i<equation.size();i++)
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
