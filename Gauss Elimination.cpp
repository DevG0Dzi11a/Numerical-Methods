#include<bits/stdc++.h>
using namespace std;
int order_n;
double matrix[100][100], x[100];

void forward_elimination()
{
    for(int k=1; k<order_n; k++)
    {
        for(int i=k+1; i<=order_n;i++)
        {
            for(int j=k; j<=order_n+1; j++)
            {
                matrix[i][j] = matrix[i][j] - (matrix[i][k] / matrix[k][k])*matrix[k][j];
            }
        }
    }
}

void backward_substitution()
{
    x[order_n] = matrix[order_n][order_n+1]/matrix[order_n][order_n];
    double sum;
    for(int k = order_n-1; k>=1; k--)
    {
        sum = 0;
        for(int j=k+1; j<=order_n; j++)
        {
            sum = sum + matrix[k][j]*x[j];
        }
        x[k] = 1/matrix[k][k]*(matrix[k][order_n+1] - sum);
    }
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

    for(int i=1; i<=order_n; i++)
    {
        for(int j=1; j<=order_n+1; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    forward_elimination();
    cout<<"After Elimintation"<<endl;

    for(int i=1; i<=order_n; i++)
    {
        for(int j=1; j<=order_n+1; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    backward_substitution();
    cout<<"After backward substitution:"<<endl;
    for(int i=1; i<=order_n;i++)
    {
        cout<<"x"<<i<<" = "<<x[i]<<endl;
    }
    return 0;
}
