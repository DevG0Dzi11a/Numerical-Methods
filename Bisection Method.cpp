#include<bits/stdc++.h>
#include<cmath>
using namespace std;

double bisection(double x)
{
    double res;
    res = (x*x*x)-x-1;

    return res;
}

int main()
{
    double x1, x2, t_error, x3, ret_1, final_ans, ret;
    cin>>x1>>x2>>t_error;

    while(fabs(bisection(x2))>t_error)
    {
        ret = bisection(x1) * bisection(x2);
        if(ret>0)
        {
            cout<<"Incorrect initial guesses\n";
            break;
        }
        x3 = (x1+x2)/2;
        ret_1 = bisection(x1) * bisection(x3);
        if(ret_1<0)
            x2 = x3;
        else
            x1 = x3;
        final_ans = x3;
    }
    cout<<"Root:"<<x3;
    return 0;
}
