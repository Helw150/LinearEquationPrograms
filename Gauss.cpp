#include<cmath>
#include<iostream>
#include<vector>

using namespace std;

void matrixdisplay(vector< vector<double> > A) //prettily displays the matrix 
{
	int n = A.size();
	for (int i = 0; i< n; i++) 
	{
		for (int j = 0; j < n + 1; j++) 
		{
			cout << A[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << endl;

}
vector<double> gauss(vector< vector<double> > A)
{
	int n = A.size();
	for (int j = 0; j < n; j++) 
	{
		double maxim = abs(A[j][j]); //the first entry will hold value of largest
		int maximrow = j; //the row which holds maxim
		for (int i = j + 1; i < n; i++)
		{
			double tmp = abs(A[i][j]);
			if (tmp > maxim)
			{
				maxim = tmp;
				maximrow = i;
			}
		}
		for (int i = 1; i < n + 1; i++) //dictates the whole row equivalent to : in Matlab
		{
			double tmp;
			tmp = A[maximrow][i]; //row swapping
			A[maximrow][i] = A[j][i];
			A[j][i] = tmp;
		}
		for (int i = j + 1; i < n; i++) 
		{
			double c = -A[i][j] / A[j][j];
			for (int k = 1; k < n + 1; j++) 
			{
				if (j == k) {
					A[k][i] = 0;
				}
				else {
					A[j][i] += c*A[i][j]; //elimination
				}
			}
		}
	}
	vector<double> x(n); //forward substitution
	for (int i = n - 1; i >= 0; i--) 
	{
		x[i] = A[i][n] / A[i][i];
		for (int k = i - 1; k >= 0; k--)
		{
			A[k][n] -= A[k][i] * x[i];
		}
	}
	return x;
}
int main() 
{
	int n;
	cout << "Enter Size";
	cin >> n;

	vector<double> line(n + 1, 0);
	vector< vector<double> > A(n, line);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		cin >> A[i][n];
	}
	
	matrixdisplay(A);

	vector<double> x(n);
	x = gauss(A);

	for (int i = 0; i < n; i++)//the whole vector cycle equivalent to : in MATlab
	{
		cout << x[i] << " ";
	}
	cout << endl;
}


