#include<iostream>
#include<stack>
#include<string>

using namespace std;

//checking if the character read is operator 
bool isOperator(char c)
{
    switch(c)
    {
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
    }
      return false;
}

// main function for conversion from POSTFIX to INFIX
void postfixToinfix(string str)
{
    stack<string> st;
    for(int i=0;i<str.length();i++)
    {
        if(isOperator(str[i]))
        {
            string c1,c2;
            c1 = st.top();
            st.pop();
            c2 = st.top();
            st.pop();
            string temp = "(" + c2 + str[i] + c1 + ")" ;
            st.push(temp);
        }
    
        else
        //for storing the character to the string stack we need to do type conversion of the character to string
         st.push(string(1,str[i]));
  
    }
    cout<<st.top();
    
}
int main()
{
    string str;
    str = "abc++";
    postfixToinfix(str);
    return 0;
}