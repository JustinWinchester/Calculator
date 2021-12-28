/* **************************************************************************************************
Programmer: Justin Winchester 
Class     : Data Structures 
Synopsis  : Create a calculator that converts infix to postfix and evaluates the equation.
Task	  : Create a class that works cohesively with other files, such as a header file and imple
	    mentaion file. 
**************************************************************************************************** */
//This will be my Calculator Class Header File, containing function protoypes 

#include <iostream>
#include<stack>
#include<string>
#include<ctype.h>
#include<stdio.h>
#ifndef Calculator_h 
#define Calculator_h 

using namespace std; 
class Calculator 
	{
		public:
		Calculator(); 
		void start();
		bool check_match();  
		string convert_infix_to_postfix(); 
		int evaluate_postfix(); 
		int precedence(char ch);
		void print(); 
	
		private: 
		string infix, postfix;
		char answer;  

	};
	
#endif  
		
