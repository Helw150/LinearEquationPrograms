#include <cmath>
#include <iostream>
#include <vector>

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
struct LUP
{
	vector < vector<double> > Lower;
	vector < vector<double> > Upper;
	vector < vector<double> > Permute;
};


LUP LUdecomp(vector< vector<double> > A)
{
	int n = A.size();
	vector < vector<double> > P;
	P = vector<vector<double> >(n, vector<double>(n, 0));
	for (int i = 0; i < n; i++)
	{
		P[i][i] = 1;
	}
	vector< vector<double> > U;
	U = vector<vector<double> >(n, vector<double>(n, 0));
	vector< vector<double> > L;
	L = vector<vector<double> >(n, vector<double>(n, 0));
	for (int j = 0; j < n; j++)
	{
		double maxim = abs(A[j][j]); //the first entry will hold value of largest
		int Maximrow = j; //the row which holds maxim
		for (int i = j + 1; i < n; i++)
		{
			if (abs(A[i][j]) > maxim)
			{
				maxim = abs(A[i][j]);
				Maximrow = i;
			}
		}
		for (int i = j; i < n + 1; i++) //dictates the whole row equivalent to : in Matlab
		{
			double tmp;
			tmp = A[Maximrow][i]; //row swapping the actual
			A[Maximrow][i] = A[j][i];
			A[j][i] = tmp;
			tmp = P[Maximrow][i]; //row swapping permutation
			P[Maximrow][i] = P[j][i];
			P[j][i] = tmp;
		}
		for (int i = 1, 1 < n, i++)
		{
			L[i][1] = A[i][1];
			U[i][i] = 1;
		}
		for (int i + 2, i < n, i++)
		{
			U[1][i] = A[1]][i] / L[1][1];
		}
		for (int k = 2, k < j, k++)
		{
			for (int i = 1, i < k-1, i++)
			{
				L[j][k] = (A[j][k] - L[j][i] * U[i][k])
			}
		}
		for (int k = j+1, k < n, k++)
		{
			for (int i = 1, i < j - 1, i++)
			{
				U[j][k] = (A[j][k] - L[j][i] * U[i][k]) / L[j][j]
			}
		}
	}
	LUP defined;
	defined.Lower = L;
	defined.Upper = U;
	defined.Permute = P;
	return defined;
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
	matrixdisplay(A);
	LUP defined;
	LUdecomp(A);

	matrixdisplay(defined.Lower);
	matrixdisplay(defined.Upper);
	matrixdisplay(defined.Permute);

}

