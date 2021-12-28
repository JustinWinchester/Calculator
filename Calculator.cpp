/* **************************************************************************************************
Programmer: Justin Winchester
Class     : Data Structures
Synopsis  : This will be the ".cpp" file the defines the function we prototyped in the Calculator 
		header file. And whose funtion implementations will be used in the main drive file 
		that works subsequently to this one.
Task      : Create a class that works cohesively with other files, such as a header file and imple
            mentaion file. This is the second file that elaborates the code and develops it! 
**************************************************************************************************** */
//This will be my Calculator Class Calculator.cpp file , containing function definitions!


#include <iostream>
#include "Calculator.h"

using namespace std; 

//First Function defined will be constructor

Calculator :: Calculator () 
 {
	infix = postfix = " "; 
	//cout <<" enter an infix please: " << endl;
	
 }

void Calculator::start( )
{
	do{
		cout<<"\nEnter an infix expression please: ";
		getline(cin,infix);//read the expression from the keyboard!

		if(check_match())
		{
			convert_infix_to_postfix();
			cout<<postfix<<endl;
			cout<<"The Result Is: " << evaluate_postfix()<<endl; 
		}else
			continue;//Go back to the beginning of loop! 

		cout<<"\nDo you want to perform another operation? y/n: ";
		cin>>answer;
		cin.ignore();
		
		if(tolower(answer)=='y')
			
		continue;//Go back to beginning of loop!
		else{
			cout<<"Thank You Very Much!"<<endl; 
			break;//Break the loop!
		}		
	
	}while(true);

}


int Calculator::precedence(char ch)
{
        if(ch == '+' || ch == '-')
                return 1;
        else
                return 2;
}


 string Calculator ::  convert_infix_to_postfix()
 {		
		//string postfix; 
		int i = 0; 
		stack<char> char_stack; 
		
		for(i=0; i < infix.length();)
		{
			char ch = infix[i]; 
			switch(ch)
			{
			case'0': 
			case'1':
			case'2':
			case'3':
			case'4':
			case'5':
			case'6':
			case'7':
			case'8':
			case'9':

				postfix += ch; 
				i++; 
		
				while(isdigit(infix[i]))
				{	
				postfix += infix[i++];
				}
			postfix += " ";//Append a space afterwards

			break;

			case'(': char_stack.push(ch);i++; break;
			case')': while(char_stack.top() != '(' )
				{
					postfix += 	
char_stack.top();
					postfix+=" ";
					char_stack.pop();
			}
			char_stack.pop();
			i++;
			break; 
		case'-':
		case'+':
		case'/':
		case'*':
			while(!char_stack.empty() && 
			precedence(ch) <= precedence(char_stack.top())&&
			char_stack.top() != '(')
			{
				postfix += char_stack.top();
				postfix += " ";
				char_stack.pop();
			}
			char_stack.push(ch);
			i++;
			break;
		}
	}
	while(!char_stack.empty())
	{
		postfix += char_stack.top();
		postfix += " "; 
		char_stack.pop();
	}
	return postfix;
}

bool Calculator :: check_match()
{
	stack <char> s;
	string in_string; 
	int i, len=in_string.size();
	
	for(i = 0; i < len; i++)
	{
		if(in_string[i] == '(' )
		{
			s.push(in_string[i]);
		}
		else if(in_string[i] == ')' )
		{
			if(s.empty())
			{
				return false; 
			}
			else 
				s.pop(); 
			}
		else
			;
	}
	if(s.empty())
		return true; 
	else
		return false;
}

int Calculator :: evaluate_postfix()
{
	stack<int> mystack;
	char op;
	int ap1, ap2;
	
	cout <<endl<<postfix<<endl;

	int len = postfix.length();
	cout<<endl<<len<<endl;

	for(int i = 0; i < len; i++)
	{
		if(isspace(postfix[i]))
			;
		else if(isdigit(postfix[i]))
		{
			int temp = 0; 
			while(isdigit(postfix[i]))
			{
				temp = temp * 10 + (postfix[i] - '0'); 
				i++;
			}
			mystack.push(temp);
		}
		else
		{
			op = postfix[i];
			
			if(!mystack.empty())
			{
				ap1 = mystack.top(); 
				mystack.pop();
			}

			else{
				cout<<"\nOnly ONE operand. ERROR\n";
				//return; 
			}
			
			if(!mystack.empty())
			{
				ap2 = mystack.top();
				mystack.pop();
			}
			else{
				cout<<"\nOnly ONE operand.ERROR!\n"; 
				;
			}
			
			switch(op)
			{
				case'+': mystack.push(ap1 + ap2);
				break;
				
				case'-': mystack.push(ap2 - ap1);
				break; 
				
				case'*': mystack.push(ap1 * ap2); 
				break;
			
				case'/': mystack.push(ap2/ap1);
				}
			}
	}
	
	if(!mystack.empty())
	{
			
		cout<<"\nThe result is: " << mystack.top();
		mystack.pop();
	}
	if(!mystack.empty())		

		cout<<"\nOOPS, The Result Is NOT Correct!\n";
		cout<<endl<<endl; 

	return mystack.top();
}


