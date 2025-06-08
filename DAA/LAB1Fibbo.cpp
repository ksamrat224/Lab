#include<iostream>
using namespace std;
int main()
{
    int a= 0, b=1,n,temp;
    cout<<"Enter value of n: ";
    cin>>n;
    cout<<"Fibonacci series: ";
    while(n>=0)
    {
        cout<<a<<", ";
        temp = a;
        a = b;
        b = temp+b;
        n--;
    }
    cout<<"\b\b  ";
    return 0;
}