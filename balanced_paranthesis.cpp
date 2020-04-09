#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool opening_bracket(char s)
{
    if(s=='(' || s=='{' || s=='[')
    {
        return true;
    }
    else
    {
         return false;
    }
    
}
bool balancechecker(string s)
{
    stack<char> st;
    int l = s.length();
    for(int i=0;i<l;i++)
    {
        if(opening_bracket(s[i]))
        {
            st.push(s[i]);
        }
        else
        {
            switch(s[i])
            {
                case ')':
                    if(st.top()==')')
                      st.pop();                   
                    else                   
                      return false;                   
                    break;
                case ']':
                    if(st.top()==']')
                      st.pop();
                    else                   
                      return false;                   
                    break;    
                case '}':
                    if(st.top()=='}')
                      st.pop();                   
                    else                   
                      return false;                   
                    break;
                     
            }
        }       
          }
    return(st.empty());           
}

int main()
{
    string s = "[[()]{}{[()()]()}";
    if(balancechecker(s))
     {
        cout<<"BALANCED!"<<endl;
     }
    else
     {
        cout<<"UN BALANCED!"<<endl;
     }
    return 0;
    
}