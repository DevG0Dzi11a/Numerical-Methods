#include<bits/stdc++.h>
#include <math.h>
using namespace std;

int degree, itr = 0, deg1, r = 0;
double e, q[100],a[100], a0, a1;
int initial;

double horner(double n)
{


    double p[100];

    p[deg1] = q[deg1];

    for(int i = deg1; i > 0; i--)
    {

        p[i-1] = p[i]*n + q[i-1];                     // honers equation
    }

    return p[0];
}

double difHorner(double x)
{

    double p1[100], d[100];

    for(int i = 1; i <= deg1; i++)
    {

        d[i-1] = q[i]*i;
    }

    p1[deg1 - 1] = d[deg1 - 1];

    for(int i = deg1-1; i > 0; i--)
    {

        p1[i-1] = p1[i]*x + d[i-1];
    }

    return p1[0];
}
double f(double x)
{
    return ((x*x*x*x)+(3*x*x*x)-(2*x*x)-(12*x)-8);

}
double der_f(double x)
{
    return ((4*x*x*x)+(9*x*x)-(4*x)-12);
}

int ConditionNumber(double x)
{
    double condi = ((x*der_f(x))/(f(x)));
    return condi;
}



void syntheticDivision(double x)
{

    q[deg1] = 0;   //bn=0  highest degree =0

    for(int i = deg1; i > 0; i--)
    {

        q[i-1] = a[i] + q[i]*x;                                                   // synthetic eqn
    }

    for(int i = deg1; i > -1; i--)
    {

        a[i] = q[i];                   // new coefficient store  eqn chng holo
    }

    a0 = a[0];
    a1 = a[1];
}

double err(double a)
{

    return fabs(horner(a));   //error
}


void newton(double a)
{

    double fx, x0, fr, xr,f_derx;

    x0 = a;                           //initial



     double condi = ConditionNumber(initial);

    if(condi>1)
    {
        cout<<"System is ill Condition"<<endl;
    }
    else
    {
        cout<<"System is Well Condition"<<endl;



    if(difHorner(x0) == 0)
    {

        cout<<"Insufficient root ";
        return;
    }

    while(deg1 > 1)
    {

        while(true)
        {

            itr++;
            fx = horner(x0);                                     //Evalure f(x)
            f_derx = difHorner(x0);                      //Evalute f'(x)

            if(f_derx== 0)
            {

                cout<<"Insufficient root "<<f_derx;
                break;
            }

            else
            {

                xr = x0 - (fx/f_derx);



                if(fx == 0)
                {

                    return;                   // etai root
                }

                x0 = xr;

                if(fabs(horner(xr)) < 0.001)
                {
                    cout<<"itr "<<r++<<"  APProximate  Root "<<r+1<<":";
                    cout<<"   "<<xr<<endl;
                    printf("The Root is not Close to real Root");
                    break;

                }

                else
                {

                    x0 = xr;
                }

            }

        }

        syntheticDivision(xr);
        deg1--;
    }


    double root1 = -a0/a1;

    cout<<"itr "<<r++<<"  Approximate  Root "<<r+1<<":"<<"   "<<root1<<endl;
       printf("The Root is not Close to real Root");
}
}

int main()
{


    double root;

    cout<<"Enter the degree of the equation: ";
    cin>>degree;
    deg1 = degree;
    cout<<endl;
    cout<<"Enter the coefficients of the equation: ";
    for(int i = degree; i > -1; i--)
    {
        cin>>a[i];
        q[i] = a[i];
    }

    cout<<endl;
    cout<<"Enter the initial guess : ";
    cin>>initial;

    newton(initial);

    return 0;
}

