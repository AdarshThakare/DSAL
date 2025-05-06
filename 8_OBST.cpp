#include <iostream>
using namespace std;
class obst 
{
    int a[10], r[10][10], n;
    float p[10], q[10], w[10][10], c[10][10];
    public:
    void accept();
    void cons_obst();
    int knuthmin(int, int);
    void tree(int i, int j);
};
void obst::accept() 
{
    int i;
    cout << "how many elements are there in the tree?\n";
    cin >> n;
    cout << "enter" << n << "elements \n";
    for (i = 1; i <= n; i++)
    cin >> a[i] ;
    cout << "enter" << n << "their probabilities\n";
    for (i = 1; i <= n; i++)
    cin >>  p[i];
    cout << "enter" << n + 1 << "failure probabilities\n";
    for (i = 0; i <= n; i++)
    cin >> q[i];
}
void obst::cons_obst() 
{
    int i, m, j, k;
    for (i = 0; i < n; i++) /* Initialize the weight and cost matrices */
    {
        w[i][i] = q[i];
        r[i][i] = c[i][i] = 0;
        w[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
        r[i][i + 1] = i + 1;
        c[i][i + 1] = w[i][i + 1];
    }
    w[n][n] = q[n];
    r[n][n] = c[n][n] = 0;
    for (m = 2; m <= n; m++) /* calculate the weight and cost matrices */
    {
        for (i = 0; i <= n - m; i++) 
        {
            j = i + m;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            k = knuthmin(i, j); /* find minimum value in the range r[i-1][j] to r[i][j-1] */
            c[i][j] = w[i][j] + c[i][k - 1] + c[k][j];
            r[i][j] = k;
        }
    }
    cout << "root node is " << a[r[0][n]];
    cout << "\nleft child of " << a[r[0][n]] << " is ";
    tree(0, r[0][n] - 1);
    cout << "\nright child of " << a[r[0][n]] << " is ";
    tree(r[0][n], n);
}
int obst::knuthmin(int i, int j) 
{
    int min = 999, k, z;
    for (k = r[i][j - 1]; k <= r[i + 1][j]; k++) 
    {
        if (min > c[i][k - 1] + c[k][j]) 
        {
            min = c[i][k - 1] + c[k][j];
            z = k;
        }
    }
    return (z);
}
void obst::tree(int i, int j) 
{
    if (r[i][j] == 0) 
    {
    cout<<" NULL\n";
    return;
    }
    cout << " :: " << a[r[i][j]];
    cout << "\n left child of is ::" << a[r[i][j]];
    tree(i, r[i][j] - 1);
    cout << "\n right child of is :: " << a[r[i][j]];
    tree(r[i][j], j);
}
int main() 
{
    obst o;
    o.accept();
    o.cons_obst();
}



