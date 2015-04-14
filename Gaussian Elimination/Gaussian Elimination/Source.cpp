#include<cmath>
#include<iostream>
#include<vector>

using namespace std;

void print(vector< vector<double> > A) 
{
	int n = A.size();
	for (int i = 0; i< n; i++) 
	{
		for (int j = 0; j < n + 1; j++) 
		{
			cout << A[i][j] << "\t";
			if (j == n - 1) 
			{
				cout << "| ";
			}
		}
		cout << "\n";
	}
	cout << endl;

}

vector<double> gaussian(vector< vector<double> > A) 
{
	int n = A.size();
	for (int i = 0; i < n; i++) {
		for (int k = i + 1; k < n; k++) 
		{
			double c = -A[k][i] / A[i][i];
			for (int j = 1; j < n + 1; j++) 
			{
				if (i == j) {
					A[k][j] = 0;
				}
				else {
					A[k][i] += c*A[i][j];
				}
			}
		}
	}
	vector<double> x(n);
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
	
	print(A);

	vector<double> x(n);
	x = gaussian(A);

	cout << "Result:\t";
	for (int i = 0; i < n; i++)
	{
		cout << x[i] << " ";
	}
	cout << endl;
}