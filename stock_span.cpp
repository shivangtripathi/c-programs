#include<iostream>
#include<stack>
using namespace std;

/*ALGORITHM FOR STOCK SPAN PROBLEM
let the stock prices |100 50 40 60 180 
              day    |0   1  2  3  4 
  .create a stack and push value 0 in it.
  .create an ouptut array with default value 1;
  .check for the price of the stock at current day with the day in stack.top()
  . if price[present_day] >= price[stock.top()] then remove top value of stack until this condition breaks OR the stack is empty
            if stack gets empty then add present_day number in output array
            else add present_day number  - the day in the top of the stack left
  .else if price[present_day] < price[stock.top()] then 
            add 1 to the output array
   .push present day number in the stack
*/        

void stock_span(int price[],int l)
{
    stack<int> index;
    index.push(0);
    int output_arr[l];
    output_arr[0] = 1;
    for(int i=1;i<l;i++)
    {
    
        while(!index.empty() && price[index.top()]<=price[i])
        {
            index.pop();
        }
        output_arr[i] = index.empty() ? i+1 : i-index.top();
     index.push(i) ;   
    }
    for(int i=0;i<l;i++)
    {
        cout<<output_arr[i]<<" ";
    }
}

int main()
{
    int price[] = { 100, 40, 50, 60, 180 };
    int n = sizeof(price) / sizeof(price[0]);
    stock_span(price,n);
    return 0;
}