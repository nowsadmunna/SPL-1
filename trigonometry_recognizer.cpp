#include<iostream>
#include"header.h"
using namespace std;
int which_trigonometry=0;
int kt=0;
int count_of_left_bracket=-1,count_of_right_bracket=-1;
int check_trigonometry_funtion(string equation)
{
   int ln_count=500,trigonometry_count=500,root_count=500;
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
   }
   if(ln_count<trigonometry_count)
   {
       return 0;
   }
   if(root_count<trigonometry_count)
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
string as_trigonometry_function(string equation)
{
    string inside_of_trigonometry;
    int i;
    int fst=count_for_left_bracket(equation);
    int lst=count_for_right_bracket(equation);
    for(i=fst;i<lst;i++)
    {
        inside_of_trigonometry+=equation[i];
    }
    if(derivative_sign_of_trigonometry()==1)
    {
        cout<<"cos("<<inside_of_trigonometry<<")* d/dx("<<inside_of_trigonometry<<")"<<endl;
    }
    else if(derivative_sign_of_trigonometry()==3)
    {
        cout<<"sec^2("<<inside_of_trigonometry<<")* d/dx("<<inside_of_trigonometry<<")"<<endl;
    }
    else if(derivative_sign_of_trigonometry()==5)
    {
        cout<<"sec("<<inside_of_trigonometry<<")*"<<"tan("<<inside_of_trigonometry<<")"<<"* d/dx("<<inside_of_trigonometry<<")"<<endl;
    }
    else if(derivative_sign_of_trigonometry()==2)
    {
         cout<<"-cosec("<<inside_of_trigonometry<<")*"<<"cot("<<inside_of_trigonometry<<")"<<"* d/dx("<<inside_of_trigonometry<<")"<<endl;;
    }
    else if(derivative_sign_of_trigonometry()==4)
    {
        cout<<"-sin("<<inside_of_trigonometry<<")* d/dx("<<inside_of_trigonometry<<")"<<endl;
    }
    else if(derivative_sign_of_trigonometry()==6)
    {
        cout<<"-cosec^2("<<inside_of_trigonometry<<")* d/dx("<<inside_of_trigonometry<<")"<<endl;
    }
    initial_checking(inside_of_trigonometry);
    return"";
}
int count_for_left_bracket(string equation)
{
    int i;
    for(i=0;i<equation.size();i++)
    {
        if(equation[i]=='(')
        {
            count_of_left_bracket++;
            return i+1;
        }
    }
}
int count_for_right_bracket(string equation)
{
    int i;
    for(i=equation.size()-1;i>=0;i--)
    {
        if(equation[i]==')')
        {
            count_of_right_bracket++;
            if(count_of_left_bracket==count_of_right_bracket)
            {
                return i;
            }
        }
    }
}

