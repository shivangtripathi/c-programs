#include<iostream>
#include<vector>
using namespace std;

//SHIFTING ZEORES IN AN ARRAY TO THE END OF THE ARRAY KEEPING THE ORDER OF THE NON ZERO ELEMENTS SAME
//PUSH ALL THE NON ZERO VALUES INTO AN ARRAY AND THEN FILL THE VACANT SPACES OF THE ARRAY WITH 0
void shifzero(vector<int> &v)
{
    int l = v.size();
    vector<int> solution;
    int next=0;
    int arr[l];
    for(auto x:v)
    {
        if(x!=0)
        {
            arr[next]=x;
            next++;
        }
    }
    for(int i=next;i<l;i++)
    {
       arr[i]=0;
    }
    for(int i=0;i<l;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    vector<int> v = {4,0,6,0,5,0,0};
    shifzero(v);
}