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


LUP LUdecomp(vector< vector<double> > A)
{
	int n = A.size();
	vector <double> P;
	P = vector<double>(n);
	for (int i = 0; i < n; i++)
	{
		P[i] = n;
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
		for (int i = 1; 1 < j; i++)
		{
			L[i][1] = A[P[i]][1];
			U[i][i] = 1;
		}
		for (int i = 2; i < n; i++)
		{
			U[1][i] = A[P[1]][i] / L[1][1];
		}
		for (int k = 2; k < j; k++)
		{
			for (int i = 1; i < k - 1; i++)
			{
				L[j][k] = (A[P[j]][k] - L[j][i] * U[i][k]);
			}
		}
		for (int k = j + 1; k < n; k++)
		{
			for (int i = 1; i < j - 1; i++)
			{
				U[j][k] = (A[P[j]][k] - L[j][i] * U[i][k]) / L[j][j];
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
	vectordisplay(defined.Permute);

}

