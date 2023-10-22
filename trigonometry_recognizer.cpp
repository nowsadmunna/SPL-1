#include<iostream>
#include"header.h"
using namespace std;
int which_trigonometry=0;
string temoprary_for_trigonometry;
int check_trigonometry_funtion(string equation)
{
   int ln_count=500,trigonometry_count=500,root_count=500,expotential_count=500;
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
           trigonometry_count=i;
           break;
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
       else if(equation[i]=='c' && equation[i+1]=='o' && equation[i+2] =='s' && equation[i+3]=='e' && equation[i+4]=='c')
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
   if(which_trigonometry==0)
   {
       return 0;
   }
}
int derivative_sign_of_trigonometry()
{
    return which_trigonometry;
}
string as_trigonometry_function(string equation,string temporary)
{
    string inside_of_trigonometry,answer;
    int flag=0;
    inside_of_trigonometry=inside_of_bracket(equation);
    if(derivative_sign_of_trigonometry()==1)
    {
        if(check_algebric_equation(inside_of_trigonometry))
        {
            if(partition_based_on_operator(inside_of_trigonometry,temporary)=="0")
            {
                cout<<temporary<<"0"<<endl;
                answer="0";
                flag=1;
            }
            else if(partition_based_on_operator(inside_of_trigonometry,temporary)=="1")
            {
                temporary+="cos("+inside_of_trigonometry+")";
                cout<<temporary<<endl;
                answer="cos("+inside_of_trigonometry+")";
                flag=1;
            }
        }
        if(flag==0)
        {
            temporary+="cos("+inside_of_trigonometry+")*";
            cout<<temporary<<" d/dx("<<inside_of_trigonometry<<")"<<endl;
            answer="cos("+inside_of_trigonometry+")*("+partition_based_on_operator(inside_of_trigonometry,temporary)+")";
        }
    }
    else if(derivative_sign_of_trigonometry()==3)
    {
        temporary+="sec^2("+inside_of_trigonometry+")*";
        cout<<temporary<<" d/dx("<<inside_of_trigonometry<<")"<<endl;
        answer="sec^2("+inside_of_trigonometry+")*("+partition_based_on_operator(inside_of_trigonometry,temporary)+")";

    }
    else if(derivative_sign_of_trigonometry()==5)
    {
        temporary+="sec("+inside_of_trigonometry+")*"+"tan("+inside_of_trigonometry+")*";
        cout<<temporary<<" d/dx("<<inside_of_trigonometry<<")"<<endl;
        answer="sec("+inside_of_trigonometry+")"+"*"+"tan("+inside_of_trigonometry+")*("+partition_based_on_operator(inside_of_trigonometry,temporary)+")";

    }
    else if(derivative_sign_of_trigonometry()==2)
    {
        temporary+="-cosec("+inside_of_trigonometry+")*"+"cot("+inside_of_trigonometry+")*";
        cout<<temporary<<" d/dx("<<inside_of_trigonometry<<")"<<endl;
        answer="-cosec("+inside_of_trigonometry+")"+"*"+"cot("+inside_of_trigonometry+")*("+partition_based_on_operator(inside_of_trigonometry,temporary)+")";

    }
    else if(derivative_sign_of_trigonometry()==4)
    {
       temporary+="(-sin("+inside_of_trigonometry+"))*";
        cout<<temporary<<" d/dx("<<inside_of_trigonometry<<")"<<endl;
        answer="-sin("+inside_of_trigonometry+")*("+partition_based_on_operator(inside_of_trigonometry,temporary)+")";

    }
    else if(derivative_sign_of_trigonometry()==6)
    {
        temporary+="(-cosec^2("+inside_of_trigonometry+"))*";
        cout<<temporary<<" d/dx("<<inside_of_trigonometry<<")"<<endl;
        answer="-cosec^2("+inside_of_trigonometry+")*("+partition_based_on_operator(inside_of_trigonometry,temporary)+")";

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
