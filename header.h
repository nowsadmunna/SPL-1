#ifndef HEADER_H
#define HEADER_H


#include<bits/stdc++.h>
using namespace std;
void display();
string removespaces(string equation);
bool check_uv_function(string equation);
string as_uv_function(string equation);
int check_trigonometry_funtion(string equation);
int derivative_sign_of_trigonometry();
string as_trigonometry_function(string equation);
int char_type(char c);
bool an_alphabet(char c);
bool a_digit(char c);
bool an_operator(char c);
bool a_power(char c);
bool a_bracket(char c);
string partitioning_equation(string equation);
void as_algebric(string equation);
int check_u_or_uplusv(string equation);
void show_as_uplusv(string equation);
string calculate_derivative(char variable,int power,int coefficient);
string initial_checking(string equation);
string partition_based_on_operator(string equation);
string remove_bracket(string equation);
bool check_udivv_function(string equation);
string as_udivv(string equation);
string inside_of_bracket(string equation);
int check_ln_function(string equation);
string as_ln_function(string equation);
int check_square_root_function(string equation);
string as_square_root_function(string equation);
int check_expotentail_function(string equation);
string as_expotential_function(string equation);
void show_formula();
int check_inverse_trigonometry_funtion(string equation);
int derivative_sign_of_inverse_trigonometry();
string as_inverse_trigonometry_function(string equation);
string inside_of_inverse_bracket(string equation);
string minimized_answer(string equation);
string zero_minimization(string equation);
#endif