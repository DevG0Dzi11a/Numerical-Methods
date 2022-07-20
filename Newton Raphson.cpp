#include<bits/stdc++.h>
using namespace std;

double func(double x)
{
    return x;
}

double func_der(double x)
{
    return x;
}

int main()
{
    double x0, t_error, x1;
    double f1;
    cout<<"Input initial guess :";
    cin>>x0;
    cout<<"Input tolerable error :";
    cin>>t_error;

    while(f1>t_error)
    {
        if(func_der(x0) == 0.0)
        {
            cout<<"Mathematical Error!"<<endl;
            exit(0);
        }
        x1 = x0 - (func(x0)/func_der(x0));
        x0 = x1;
        f1 = func(x1);
    }
    cout<<"Root :"<<x1<<endl;
    return 0;
}
