#include<iostream>
#include "header.h"
using namespace std;
string removespaces(string equation)
{
    string space_removal_string;
    int i;
    for(i=0;equation[i]!='\0';i++)
    {
        if(equation[i]==' ')
            {
                continue;
            }
        else
            {
                space_removal_string+=equation[i];
            }
    }
    return space_removal_string;
}
void display()
{
    cout<<"-------------------Welcome to Derivative Calculator------------------"<<endl<<endl<<endl<<endl;
    int choice,i,j;
    stack<char>answer_minimization;
    string equation,answer,final_answer,part;
    while(1)
    {
        cout<<"1. Show Formula"<<endl;
        cout<<"2. Input Equation"<<endl;
        cout<<"3. Exit"<<endl<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        getchar();
        answer="";
        final_answer="";
        part="";
        if(choice==1)
        {
            show_formula();
        }
        else if(choice==2)
        {
            cout<<"Enter the equation: ";
            cin>>equation;
            getchar();
            cout<<"step by step derivative calculation of d/dx("<<equation<<") are given below : "<<endl;
            answer=partition_based_on_operator(equation);
            cout<<endl<<endl;
            cout<<"Answer ="<<answer<<endl;
            for(i=0;i<answer.size();i++)
            {
                if(answer[i]=='(')
                {
                    answer_minimization.push(answer[i]);
                    part+=answer[i];
                }
                else if(answer[i]==')')
                {
                    answer_minimization.pop();
                    part+=answer[i];
                }
                else if(answer[i]=='+' || answer[i]=='-')
                {
                    if(answer_minimization.size()==0)
                    {
                        int flag=0;
                        for(j=0;j<part.size();j++)
                        {
                            if(part[j]=='*' && part[j+1]=='0')
                            {
                                final_answer+="0";
                                flag=1;
                                break;
                            }
                            else if(part[j]=='*' && part[j+1]=='(' && part[j+2]=='0' && part[j+3]==')')
                            {
                                final_answer+="0";
                                flag=1;
                                break;
                            }   
                        }
                        if(flag==0)
                        {
                            final_answer+=part;
                        }
                        final_answer+=answer[i];
                        part="";
                    }
                    else 
                    {
                        part+=answer[i];
                    }
                }
                else 
                {
                    part+=answer[i];
                }
            }
            int flagg=0;
            for(i=0;i<part.size();i++)
            {
                if(part[i]=='*' && part[i+1]=='0')
                {
                    final_answer+="0";
                    flagg=1;
                    break;
                }
                else if(part[i]=='*' && part[i+1]=='(' && part[i+2]=='0' && part[i+3]==')')
                {
                    final_answer+="0";
                    flagg=1;
                    break;
                }   
            }
            if(flagg==0)
            {
                final_answer+=part;
            }
            part="";
            answer="";
            cout<<"       ="<<final_answer<<endl;
            for(i=0;i<final_answer.size();i++)
            {
                if((final_answer[i]=='+' || final_answer[i]=='-') && final_answer[i+1]=='0')
                {
                    i++;
                }
                else 
                {
                    answer+=final_answer[i];
                }
            }
            cout<<"       ="<<answer<<endl;
            final_answer="";
            for(i=0;i<answer.size();i++)
            {
                if(answer[i]=='0' && answer[i+1]=='+')
                {
                    i++;
                    continue;
                }
                else if(answer[i]=='0' && answer[i]=='-')
                {
                    continue;
                }
                else 
                {
                    final_answer+=answer[i];
                }
            }
            cout<<"       ="<<final_answer<<endl;
        }
        else if(choice==3)
        {
            break;
        }
        else 
        {
            cout<<"Enter a valid choice"<<endl;
        }
    }
    cout<<"--------------------------Thank You---------------------------------"<<endl;
}
string initial_checking(string equation)
{
    string answer_for="";
    int i;
     if(check_uv_function(equation))
    {
        answer_for+=as_uv_function(equation);
    }
    else if(check_udivv_function(equation))
    {
        answer_for+=as_udivv(equation);
    }
    else 
    {
        if(check_trigonometry_funtion(equation))
        {
            answer_for+=as_trigonometry_function(equation);
        }
        else if(check_ln_function(equation))
        {
            answer_for+=as_ln_function(equation);
        }
        else if(check_expotentail_function(equation))
        {
            answer_for+=as_expotential_function(equation);
        }
        else if(check_square_root_function(equation))
        {
            answer_for+=as_square_root_function(equation);
        }
        else 
        {
            answer_for+=partitioning_equation(remove_bracket(equation));
        }
    }
    return answer_for;
}
string partition_based_on_operator(string equation)
{
    string part,answer,part_answer;
    stack<char>bracket;
    int i,j;
    for(i=0;i<equation.size();i++)
    {
        if(equation[i]=='(')
        {
            bracket.push(equation[i]);
            part+=equation[i];
        }
        else if(equation[i]==')')
        {
            bracket.pop();
            part+=equation[i];
        }
        else if(equation[i]=='+' || equation[i]=='-')
        {
            if(bracket.size()==0)
            {
                cout<<"d/dx("<<part<<")=";
                part_answer=initial_checking(part);
                answer+=part_answer;
                answer+=equation[i];
                part="";
            }
            else 
            {
                part+=equation[i];
            }
        }
        else 
        {
            part+=equation[i];
        }
    }
    cout<<"d/dx("<<part<<")=";
    part_answer=initial_checking(part);
    answer+=part_answer;
    part="";
    return answer;
}
int check_algebric_equation(string equation)
{
    if(check_uv_function(equation))
    {
        return 0;
    }
    else if(check_udivv_function(equation))
    {
        return 0;
    }
    else if(check_trigonometry_funtion(equation))
    {
        return 0;
    }
    else if(check_ln_function(equation))
    {
        return 0;
    }
    else if(check_expotentail_function(equation))
    {
        return 0;
    }
    else if(check_square_root_function(equation))
    {
        return 0;
    }
    else 
    {
        return 1;
    }
}
void show_formula()
{
    cout<<"   Some basic formula of differentiation are given below : "<<endl;
    cout<<"1. Constant Formula:"<<endl;
    cout<<"        d/dx(c)=0"<<endl;
    cout<<"2. Power Formula:"<<endl;
    cout<<"        d/dx(x^n)=nx^(n-1)"<<endl;
    cout<<"3. Multiple Rule:"<<endl;
    cout<<"        d/dx(cf(x))=c*d/dx(f(x))"<<endl;
    cout<<"4. Sum Rule:"<<endl;
    cout<<"        d/dx(f(x)+g(x))=d/dx(f(x))+d/dx(g(x))"<<endl;
    cout<<"5. Difference Rule:"<<endl;
    cout<<"        d/dx(f(x)-g(x))=d/dx(f(x))-d/dx(g(x))"<<endl;
    cout<<"6. Product Rule:"<<endl;
    cout<<"        d/dx(f(x)*g(x))=f(x)*d/dx(g(x))+g(x)*d/dx(f(x))"<<endl;
    cout<<"7. Division Rule:"<<endl;
    cout<<"        d/dx(f(x)/g(x))=(g(x)*d/dx(f(x))+f(x)*d/dx(g(x)))/(g(x))^2"<<endl;
    cout<<"8. Expotential Rule:"<<endl;
    cout<<"        d/dx(e^x)=e^x"<<endl;
    cout<<"9. Logarithmic Rule:"<<endl;
    cout<<"        d/dx(ln(x))=1/x"<<endl;
    cout<<"10.Square Root Rule:"<<endl;
    cout<<"        d/dx(sqrt(x))=1/(2*sqrt(x))"<<endl;
    cout<<"11.Trigonometry Rule:"<<endl;
    cout<<"       (i)   d/dx(sin(x))  =    cos(x)"<<endl;
    cout<<"       (ii)  d/dx(cos(x))  =    - sin(x)"<<endl;
    cout<<"       (iii) d/dx(sec(x))  =    sec(x)*tan(x)"<<endl;
    cout<<"       (iv)  d/dx(cosec(x))=    - cosec(x)*cot(x)"<<endl;
    cout<<"       (v)   d/dx(tan(x))  =    sec^2(x)"<<endl;
    cout<<"       (vi)  d/dx(cot(x))  =    - cosec^2(x)"<<endl;
}


