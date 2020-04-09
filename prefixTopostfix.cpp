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

// main function for conversion from PREFIX to POSTFIX
//the code is same as prefix to infix only the operator is added ahead of operands
//similarly fo Postfix to prefix the operator is added before the operands 
void prefixTopostfix(string str)
{
    stack<string> st;
    int l = str.length();
    for(int i=l-1;i>=0;i--)
    {
        if(isOperator(str[i]))
        {
            string c1,c2;
            c1 = st.top();
            st.pop();
            c2 = st.top();
            st.pop();
            string temp = c1 + c2 + str[i]  ;
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
    str = "*-A/BC-/AKL";
    prefixTopostfix(str);
    return 0;
}