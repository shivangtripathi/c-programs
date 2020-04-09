#include<iostream>
#include<stack>
#include<algorithm>
#include<string>

using namespace std;

//function for calculating the priority order of the operators
int precedenceOrder(char c)
{
    if(c=='^')
        return 3;
    else if(c=='*' || c=='/')
        return 2;
    else if(c=='+' || c=='-')
        return 1;
    else 
        return -1;
}
//Main function for the conversion of INFIX to PreFIX
void InfixToPrefix(string s)
{
    //Creating a Stack for getting the operators stored 
    stack<char> Stack;
    Stack.push('N');
    int l = s.length();
    //string to output the Prefix expression
    string out;
    //loop for going through all the input chracters
    for(int i=l-1;i>=0;i--)
    {   
        //If Operand then add it to output string
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
        {
            out+=s[i];
        }
        //else if input is '(' store it as it is
        else if(s[i]==')')
        {
            Stack.push(')');
        }
        //else if input in '(' remove every value till ')' from the stack by joining it to the output string
        else if(s[i] == '(') 
        { 
            while(Stack.top() != 'N' && Stack.top() != ')') 
            { 
                char c = Stack.top(); 
                Stack.pop(); 
                out += c; 
            } 
            //Also remove ')' from the stack
            if(Stack.top() == ')') 
            { 
                Stack.pop(); 
            } 
        }
        //if the read character is an operand
        else
        {
            //if the top charcter of stack is of lower order then remove the higher order and add it to output string and add the lower order to the stack
            while(Stack.top()!='N' && precedenceOrder(s[i]) <= precedenceOrder(Stack.top()))
            { 
                char c = Stack.top(); 
                Stack.pop(); 
                out += c; 
            } 
            Stack.push(s[i]); 
        }     
    }
    //add the stack members to the output string
    while(Stack.top() != 'N') 
    { 
        char c = Stack.top(); 
        Stack.pop(); 
        out += c; 
    } 
     //printing prefix expression  
     //reversing the generated string
    reverse(out.begin(),out.end()); 
    cout << out << endl; 
  
} 

int main()
{
    string exp = "A*B+C/D"; 
    InfixToPrefix(exp); 
    return 0; 
}
