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
    cout<<"                                Welcome to Derivative Calculator"<<endl<<endl<<endl<<endl;
    int choice,i,j;
    stack<char>answer_minimization;
    string equation,answer,final_answer;
    while(1)
    {
        cout<<"                            1. Show Formula"<<endl;
        cout<<"                            2. Input Equation"<<endl;
        cout<<"                            3. Exit"<<endl<<endl;
        cout<<"                            Enter your choice: ";
        cin>>choice;
        getchar();
        answer="";
        final_answer="";
        //part="";
        if(choice==1)
        {
            show_formula();
        }
        else if(choice==2)
        {
            stack<char>bracket;
            string part;
            cout<<"Enter the equation: ";
            getline(cin,equation);
            cout<<"step by step derivative calculation of d/dx("<<equation<<") are given below : "<<endl<<endl<<endl;
            string initial_equation;
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
                        //part_by_part.push(part); 
                        initial_equation+="d/dx(";
                        initial_equation+=part;
                        initial_equation+=")";
                        initial_equation+=equation[i];
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
            //part_by_part.push(part);
            initial_equation+="d/dx(";
            initial_equation+=part;
            initial_equation+=")";
            part="";
            cout<<initial_equation<<endl;
            string new_solution;
            while(1)
            {
                new_solution="";
                int flag=0;
                stack<char>brc;
                for(i=0;i<initial_equation.size();i++)
                {
                    if(initial_equation[i]=='d' && initial_equation[i+1]=='/' && initial_equation[i+2]=='d' && initial_equation[i+3]=='x')
                    {
                        flag=1;
                    }
                    else if(flag==0)
                    {
                        new_solution+=initial_equation[i];
                    }
                    else if(flag==1)
                    {
                        i=i+3;
                        string der_part;
                        new_solution+='(';
                        for(j=i; ; j++)
                        {
                            if(initial_equation[j]=='(')
                            {
                                if(brc.size()==0)
                                {
                                    brc.push('(');
                                }
                                else 
                                {
                                    der_part+='(';
                                    brc.push('(');
                                }
                            }
                            else if(initial_equation[j]==')')
                            {
                                brc.pop();
                                if(brc.size()==0)
                                {
                                    break;
                                }
                                else 
                                {
                                    der_part+=initial_equation[j];
                                }
                            }
                            else 
                            {
                                der_part+=initial_equation[j];
                            }
                        }
                        i=j;
                        stack<char>an_br_stack;
                        string inside_dx;
                        for(j=0;j<der_part.size();j++)
                        {
                            if(der_part[j]=='(')
                            {
                                an_br_stack.push('(');
                                inside_dx+='(';
                            }
                            else if(der_part[j]==')')
                            {
                                an_br_stack.pop();
                                inside_dx+=')';
                            }
                            else if(der_part[j]=='+' || der_part[j]=='-')
                            {
                                if(an_br_stack.size()==0)
                                {
                                    new_solution+=initial_checking(inside_dx);
                                    new_solution+=der_part[j];
                                    inside_dx="";
                                }
                                else 
                                {
                                    inside_dx+=der_part[j];
                                }
                            }
                            else 
                            {
                                inside_dx+=der_part[j];

                            }
                        }
                        new_solution+=initial_checking(inside_dx);
                        inside_dx="";
                        der_part="";
                        flag=0;
                        new_solution+=')';
                    }
                }
                if(new_solution==initial_equation)
                {
                    break;
                }
                else 
                {
                    cout<<new_solution<<endl<<endl;
                    initial_equation=new_solution;
                }
        }
            // cout<<"Answer ="<<answer<<endl;
            // for(i=0;i<answer.size();i++)
            // {
            //     if(answer[i]=='(')
            //     {
            //         answer_minimization.push(answer[i]);
            //         part+=answer[i];
            //     }
            //     else if(answer[i]==')')
            //     {
            //         answer_minimization.pop();
            //         part+=answer[i];
            //     }
            //     else if(answer[i]=='+' || answer[i]=='-')
            //     {
            //         if(answer_minimization.size()==0)
            //         {
            //             int flag=0;
            //             for(j=0;j<part.size();j++)
            //             {
            //                 if(part[j]=='*' && part[j+1]=='0')
            //                 {
            //                     final_answer+="0";
            //                     flag=1;
            //                     break;
            //                 }
            //                 else if(part[j]=='*' && part[j+1]=='(' && part[j+2]=='0' && part[j+3]==')')
            //                 {
            //                     final_answer+="0";
            //                     flag=1;
            //                     break;
            //                 }   
            //             }
            //             if(flag==0)
            //             {
            //                 final_answer+=part;
            //             }
            //             final_answer+=answer[i];
            //             part="";
            //         }
            //         else 
            //         {
            //             part+=answer[i];
            //         }
            //     }
            //     else 
            //     {
            //         part+=answer[i];
            //     }
            // }
            // int flagg=0;
            // for(i=0;i<part.size();i++)
            // {
            //     if(part[i]=='*' && part[i+1]=='0')
            //     {
            //         final_answer+="0";
            //         flagg=1;
            //         break;
            //     }
            //     else if(part[i]=='*' && part[i+1]=='(' && part[i+2]=='0' && part[i+3]==')')
            //     {
            //         final_answer+="0";
            //         flagg=1;
            //         break;
            //     }   
            // }
            // if(flagg==0)
            // {
            //     final_answer+=part;
            // }
            // part="";
            // answer="";
            // cout<<"       ="<<final_answer<<endl;
            // for(i=0;i<final_answer.size();i++)
            // {
            //     if((final_answer[i]=='+' || final_answer[i]=='-') && final_answer[i+1]=='0')
            //     {
            //         i++;
            //     }
            //     else 
            //     {
            //         answer+=final_answer[i];
            //     }
            // }
            // cout<<"       ="<<answer<<endl;
            // final_answer="";
            // for(i=0;i<answer.size();i++)
            // {
            //     if(answer[i]=='0' && answer[i+1]=='+')
            //     {
            //         i++;
            //         continue;
            //     }
            //     else if(answer[i]=='0' && answer[i]=='-')
            //     {
            //         continue;
            //     }
            //     else 
            //     {
            //         final_answer+=answer[i];
            //     }
            // }
           // cout<<"       ="<<final_answer<<endl;
        }
        else if(choice==3)
        {
            break;
        }
        else 
        {
            cout<<"                                Enter a valid choice"<<endl;
        }
    }
    cout<<"                                        Thank You"<<endl;
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
        if(check_inverse_trigonometry_funtion(equation))
        {
            answer_for+=as_inverse_trigonometry_function(equation);
        }
        else if(check_trigonometry_funtion(equation))
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
            answer_for+=partitioning_equation(equation);
        }
    }
    return answer_for;
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


