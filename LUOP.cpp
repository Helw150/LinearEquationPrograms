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
	cout << endl;
}
void matrixdisplay(vector< vector<double> > rnd) //prettily displays the matrix 
{
	int n = rnd.size();
	for (int i = 0; i< n; i++)
	{
		for (int j = 0; j < n; j++)
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
	vector< vector<double> > U(n, vector<double>(n, 0));
	U = A;
	vector < vector<double> > L;
	L = vector<vector<double> >(n, vector<double>(n, 0));
	for (int i = 0; i < n; i++)
	{
		L[i][i] = 1;
	}
	for (int i = 0; i < n - 1; i++)
	{
		double maxim = abs(U[i][i]); //the first entry will hold value of largest
		int Maximrow = i; //the row which holds maxim
		for (int j = i + 1; j < n; j++)
		{
			if (abs(U[j][i]) > maxim)
			{
				maxim = abs(U[j][i]);
				Maximrow = j;
			}
		}
		double tmp;
		tmp = P[Maximrow]; //row swapping permutation
		P[Maximrow] = P[i];
		P[i] = tmp;
		for (int j = i; j < n; j++) //dictates the whole row equivalent to : in Matlab
		{
			tmp = U[Maximrow][j];
			U[Maximrow][j] = U[i][j];
			U[i][j] = tmp;
		}
		for (int j = 0; j < i; j++)
		{
			tmp = L[Maximrow][j];
			L[Maximrow][j] = L[i][j];
			L[i][j] = tmp;
		}
		for (int j = i + 1; j < n; j++)
		{
				L[j][i] = U[j][i] / U[i][i];

				for (int k = i + 1; k < n; k++)
				{
					U[j][k] = U[j][k] - L[j][i] * U[i][k];
					U[j][i] = 0;
				}
				matrixdisplay(U);
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
	double n = defined.Upper.size();
	vector<double> x(n);
	
	for (double i = 1; i < n; i++)
	{
		double sum;
		sum = B[defined.Permute[i]];
		for (double j = 0; j < i; j++)
		{
			sum -= defined.Lower[i][j] * B[defined.Permute[j]];
		}
		B[defined.Permute[i]] = sum;
	}
	x[n-1] = B[defined.Permute[n-1]] / defined.Upper[n-1][n-1];
	for (double i = n-2; i >= 0; i--)
	{
		double sum = 0;
		for (double j = i + 1; j < n; j++)
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
	vector<double> line(n, 0);
	vector< vector<double> > A(n, line);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}
	vector<double> B(n);
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
	cout << "\n";
	matrixdisplay(defined.Upper);
	cout << "\n";
	matrixdisplay(defined.Lower);
	cout << "\n";
	vectordisplay(defined.Permute);
	cout << "\n";
	vectordisplay(x);
	int Y;
	cin >> Y;
	return 0;

}
