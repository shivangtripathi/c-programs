#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool set(int x)
{
    if(x==0)
    return false;
    else
    return true;
    
}

bool ones_zeroes_both(vector<int> v)
{int one=0,zero=0;
  for(auto x:v)
  {
      if(x==1)
          one++;
      else
          zero++;
  }
  if(one!=0 && zero!=0)
    return true;
  else
  {
      return false;
  }
    
}
bool counter(int x)
{
 vector<int> v;
 int count=0;
 int counter=0;
 //CONVERTING INTEGER INTO BINARY FORM IN A VECTOR v 
 while(x!=0)
 {
     auto t = x&1;
     v.push_back(t);
     x = x>>1;
 }
 //CHECKING IF BOTH ZEROES AND ONES ARE PRESENT
 if(ones_zeroes_both(v)==false)
 {
     return false;
 }
 stack<int> s;
 s.push(v.front());
 for(auto l = 0;l<v.size();)
 {
     while(s.top()==v[l])
     {
         count++;
         l++;
     }
     s.push(v[l]);

    if(set(counter)==false)
    {counter=count;
      }
    else
    {
        if(counter!=count)
        {
            return false;
        };
    }
 }
 return true;
}

int main()
{
    int x= 7;
    if(counter(x))
        cout<<"TRUE";
    else
        cout<<"FASLE";
    return 0;
}