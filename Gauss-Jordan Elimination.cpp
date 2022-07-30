#include<bits/stdc++.h>
using namespace std;
int order_n;
double matrix[100][100], x[100];

void gauss_jordan_elimination()
{
    double pivot;
    for(int i=1; i<=order_n; i++)
    {
        if(matrix[i][i] == 0)
        {
            cout<<"Mathematical Error!";
            break;
        }
        for(int j=1; j<=order_n; j++)
        {
            if(i!=j)
            {
                pivot = matrix[j][i]/matrix[i][i];
                for(int k=1; k<=order_n+1; k++)
                {
                    matrix[j][k] = matrix[j][k] - pivot * matrix[i][k];
                }
            }
        }
    }
    for(int i=1; i<=order_n; i++)
    {
        x[i] = matrix[i][order_n+1]/matrix[i][i];
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

    gauss_jordan_elimination();
    cout<<"After Elimintation"<<endl;


    for(int i=1; i<=order_n;i++)
    {
        cout<<"x"<<i<<" = "<<x[i]<<endl;
    }
    return 0;
}
