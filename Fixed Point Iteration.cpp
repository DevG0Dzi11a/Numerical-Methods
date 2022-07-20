#include<bits/stdc++.h>
using namespace std;

double func(double x)
{
    return x;
}
double func_conv(double x)
{
    return x;
}

int main()
{
    double x0, t_error, x1;
    int N;
    cout<<"Input initial guess :";
    cin>>x0;
    cout<<"Input tolerable error :";
    cin>>t_error;
    cout<<"Input max iteration :";
    cin>>N;
    int step_counter = 1;

    while(abs(func(x1))>t_error)
    {
        x1 = func_conv(x0);
        step_counter++;
        if(step_counter>N)
        {
            cout<<"Not convergent"<<endl;
            exit(0);
        }
        x0 = x1;
    }
    cout<<"Root :"<<x1<<endl;

    return 0;
}
