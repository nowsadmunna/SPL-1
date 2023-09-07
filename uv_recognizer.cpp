#include<iostream>
#include"header.h"
using namespace std;
string ans8="";
bool check_uv_function(string equation)
{
    int i;
    for(i=0;equation[i]!='\0';i++)
    {
        if(equation[i]=='*' && equation[i-1]==')' && (equation[i+1]='(' || (equation[i+1]>96 && equation[i+1]<123)))
        {
            return true;
        }
        else
        {
            continue;
        }
    }
    return false;
}
string as_uv_function(string equation)
{
    char first_part_u[500];
    char second_part_v[500];
    cout<<"As it is a product of two functions.The equation will follow the UV method"<<endl;
    cout<<"This is the rules of UV method for differentiation: "<<endl;
    cout<<"d/dx(u*v)=u*d/dx(v)+v*d/dx(u)"<<endl;
    int i,j=0,k=0;
    int to_get_part=0;
    int derivative_sign_u,derivative_sign_v;
    for(i=0;equation[i]!='\0';i++)
    {
        if(equation[i]=='*' && equation[i-1]==')' && (equation[i+1]=='(' || (equation[i+1]>96 && equation[i+1]<123)))
        {
            to_get_part=1;
            continue;
        }
        if(to_get_part==0)
        {
            first_part_u[j]=equation[i];
            j++;
        }
        else if(to_get_part==1)
        {
            second_part_v[k]=equation[i];
            k++;
        }
    }
    first_part_u[j]='\0';
    second_part_v[k]='\0';
    cout<<"u= "<<first_part_u<<endl;
    cout<<"v= "<<second_part_v<<endl;
    bool trigonometry_recognizer_second=check_trigonometry_funtion(second_part_v);
    cout<<trigonometry_recognizer_second<<endl;
    
    if(trigonometry_recognizer_second==true)
    {
         derivative_sign_v=derivative_sign_of_trigonometry();
         cout<<derivative_sign_v<<endl;
         if(derivative_sign_v==2 || derivative_sign_v==4 || derivative_sign_v==6)
         {
             if(as_trigonometry_function(second_part_v)!="0")
             {
                 ans8+="-";
             }
         }
    }
}

