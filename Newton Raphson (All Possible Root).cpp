#include<bits/stdc++.h>

using namespace std;

int n;
double ar[100],apr[100],br[100];

double horner(double x)
{
    double res=ar[n];
    for(int i=n-1; i>=0; i--)
    {
        res=res*x+ar[i];
    }
    return res;
}

double fprime(double x)
{
    for(int i=n; i>0; i--)
    {
        apr[i-1]=ar[i]*i;
    }
    double res=apr[n-1];
    for(int i=n-2; i>=0; i--)
    {
        res=res*x+apr[i];
    }
    return res;

}

void p(double x0)
{
    double f1,f2,f3,x1,x2,f0,xr;
    while(n>1)
    {
        while(true)
        {
            double y=horner(x0);
            double z=fprime(x0);
            xr=x0-(y/z);
            double err=abs((xr-x0)/xr);
            if(err<=.001)
            {
                cout<<"The "<<n<<" order polynomial is:  ";
                for(int i=n; i>=0; i--)
                {
                    cout<<ar[i]<<"x^"<<i<<'+';
                }
                cout<<'\n';

                cout<<std::fixed << std::setprecision(6)<<"At order "<<n<<" the root is  "<<xr<<endl;
                cout<<'\n';
                break;
            }
            x0=xr;
        }
        br[n]=0;
        for(int i=n; i>0; i--)
        {
            br[i-1]=ar[i]+xr*br[i];
        }
        n=n-1;

        for(int i=0; i<=n; i++)
        {
            ar[i]=br[i];
        }
        x0=xr;
    }
    double x=-ar[0]/ar[1];
    cout<<"The "<<n<<" order polynomial is:  ";
    for(int i=n; i>=0; i--)
    {
        cout<<ar[i]<<"x^"<<i<<'+';
    }
    cout<<'\n';

    cout<<std::fixed << std::setprecision(6)<<"\nAt order "<<n<<" the root is  "<<x<<endl;
    return;
}

int main()
{
    cout<<"Enter the degree of the equation:";
    cin>>n;
    cout<<"Enter co-efficients:\n";
    for(int i=n; i>=0; i--)
    {
        cout<<"Coefficient x[ "<<i<<" ] = ";
        cin>>ar[i];
        cout<<'\n';
    }
    double x0,xr;
    cout<<"Enter the initial value : ";

    cin>>x0;
    p(x0);

    cout<<"\nThese are 3 roots for the given polynomial";
    return 0;
}
