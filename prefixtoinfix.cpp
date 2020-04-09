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

// main function for conversion from PREFIX to INFIX
void prefixToinfix(string str)
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
            string temp = "(" + c1 + str[i] + c2 + ")" ;
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
    prefixToinfix(str);
    return 0;
}