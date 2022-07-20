#include<bits/stdc++.h>
using namespace std;

double func(double x)
{
    return x;
}

int main()
{
    int x0, x1, t_error, x2;
    cout<<"Input initial guesses :";
    cin>>x0>>x1;
    cout<<"Input tolerable error :";
    cin>>t_error;

    while(((x2-x1)/x2)>t_error)
    {
        x2 = ((x0*func(x1))-(x1*func(x0)))/(func(x1)- func(x0));
        x0 = x1;
        x1 = x2;
    }
    cout<<"Root :"<<x2<<endl;
    return 0;
}
