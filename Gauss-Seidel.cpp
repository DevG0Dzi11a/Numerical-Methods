#include<bits/stdc++.h>
using namespace std;
int order_n;
double matrix[100][100], x[100], b[100];

void jaccobi()
{
    double temperror, sum, error, allowed_error = 0.001, temp;
    for(int i=1; i<=order_n; i++)
    {
        b[i] = matrix[i][order_n+1];
    }
    for(int i=0; i<order_n; i++)
    {
        x[i] =  0;
    }

    do
    {
        temperror = 0.00;
        for(int i=1; i<=order_n; i++)
        {
            sum = 0.00;
            for(int j=1; j<=order_n; j++)
            {
                if(j!=i)
                {
                    sum = sum + matrix[i][j]*x[j];
                }
            }
            temp = (matrix[i][order_n+1]-sum)/matrix[i][i];
            error = fabs(x[i]-temp);
            if(error>temperror)
            {
                temperror = error;
            }
            x[i] = temp;
        }


    }
    while(temperror>=allowed_error);
}


int main()
{
    cout<<"Enter the order of the matrix:";
    cin>>order_n;
    cout<<"Enter the coefficients of the matrix:"<<endl;
    for(int i=1; i<=order_n; i++)
    {
        for(int j=1; j<=order_n+1; j++)
        {
            cin>>matrix[i][j];
        }
    }

    jaccobi();
    for(int i=1; i<=order_n; i++)
    {
        cout<<"x"<<i<<" = "<<x[i]<<endl;
    }
    return 0;
}
