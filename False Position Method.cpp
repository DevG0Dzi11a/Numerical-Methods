#include<bits/stdc++.h>
#include<cmath>
using namespace std;

double false_position(double x)
{
    double res;
    res = (x*x*x)-x-1;

    return res;
}

int main()
{
    double x1, x2, t_error, x3, ret_1, final_ans, ret;
    cin>>x1>>x2>>t_error;
    int itr=1;

    while(1)
    {
        ret = false_position(x1) * false_position(x2);
        if(ret>0)
        {
            cout<<"Incorrect initial guesses\n";
            continue;
        }
        x3 = x1 - (((false_position(x1))*(x2-x1))/((false_position(x2)-false_position(x1))));
        ret_1 = false_position(x1) * false_position(x3);
        if(ret_1<0)
            x2 = x3;
        else
            x1 = x3;
        double fab = fabs(false_position(x3));
        if(fab<t_error)
        {
          final_ans = x3;
          break;
        }
        cout<<"Iteration:"<<itr<<" x1:"<<x1<<" x2:"<<x2<<" x3:"<<x3<<" f\(x1\):"<<false_position(x1)<<" f\(x2\):"<<false_position(x2)<<" f\(x3\):"<<false_position(x3)<<" fab:"<<fab<<endl;
        itr++;
    }
    cout<<"Root:"<<x3;
    return 0;
}
