#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
void vectordisplay(vector<double> rnd)
{
	int n = rnd.size();
	for (int i = 0; i < n; i++)
	{
		cout << rnd[i] << "\n";

	}
}
void matrixdisplay(vector< vector<double> > rnd) //prettily displays the matrix 
{
	int n = rnd.size();
	for (int i = 0; i< n; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			cout << rnd[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << endl;
}
struct LUP
{
	vector < vector<double> > Lower;
	vector < vector<double> > Upper;
	vector <double> Permute;
};
LUP luop(vector< vector<double> > A)
{
	int n = A.size();
	vector<double> P;
	P = vector<double>(n);
	for (int i = 0; i < n; i++)
	{
		P[i] = i;
	}
	vector< vector<double> > U;
	U = A;
	vector < vector<double> > L;
	L = vector<vector<double> >(n, vector<double>(n, 0));
	for (int i = 0; i < n; i++)
	{
		L[i][i] = 1;
	}
	for (int j = 0; j < n; j++)
	{
		double maxim = abs(A[j][j]); //the first entry will hold value of largest
		int Maximrow = j; //the row which holds maxim
		for (int i = j + 1; i < n; i++)
		{
			if (abs(A[P[i]][j]) > maxim)
			{
				maxim = abs(A[P[i]][j]);
				Maximrow = i;
			}
		}
		double tmp;
		tmp = P[Maximrow]; //row swapping permutation
		P[Maximrow] = P[j];
		P[j] = tmp;
		for (int i = j; i < n + 1; i++) //dictates the whole row equivalent to : in Matlab
		{
			double tmp;
			tmp = U[Maximrow][i];
			U[Maximrow][i] = U[j][i];
			U[j][i] = tmp;
			if (j >= 2)
			{
				tmp = L[Maximrow][i];
				L[Maximrow][i] = L[j][i];
				L[j][i] = tmp;
			}
		}
		for (int i = j + 1; i <= n; i++)
		{
			L[i][j] = U[i][j] / U[j][j];
			U[i][i] = U[i][i] - L[i][j] * U[j][i];
			U[i][j] = 0;
		}
	}
		LUP defined;
		defined.Lower = L;
		defined.Upper = U;
		defined.Permute = P;
		return defined;
}
vector<double> substitution(LUP defined, vector<double> B)
{
	int n = defined.Upper.size();
	vector<double> x(n);
	for (int i = 2; i <= n; i++)
	{
		int sum;
		sum = B[defined.Permute[i]];
		for (int j = 1; j < i; j++)
		{
			sum -= defined.Lower[i][j] * B[defined.Permute[j]];
		}
		B[defined.Permute[i]] = sum;
	}
	x[n] = B[defined.Permute[n]] / defined.Upper[n][n];
	for (int i = n - 1; i >= 1; i--)
	{
		int sum = 0;
		for (int j = i + 1; i <= n; i++)
		{
			sum += defined.Upper[i][j] * x[j];
		}
		x[i] = (B[defined.Permute[i]] - sum) / defined.Upper[i][i];
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
	vector<double> B;
	for (int i = 0; i < n; i++)
	{
		cin >> B[i];
	}
	matrixdisplay(A);
	vectordisplay(B);
	vector<double> x(n);
	LUP defined;
	defined = luop(A);
	x = substitution(defined, B);
	matrixdisplay(defined.Upper);
	matrixdisplay(defined.Lower);
	vectordisplay(defined.Permute);
	vectordisplay(x);
}
