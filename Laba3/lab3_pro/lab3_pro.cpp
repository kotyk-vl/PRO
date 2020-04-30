#include <iostream>
#include<iomanip>
#include <random>
using namespace std;

int main()
{
	
	srand(time(NULL));
	int n, m, count = 0;
	cout << "Input n: ";
	cin >> n;
	cout << "Input m: ";
	cin >> m;
	vector<vector<int>> mat(n, vector<int>(m));
	cout <<endl << "1.Manual input " << endl <<
		"2.Randomize" << endl; 
	start:
	cout << "Your choice: ";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "----------------------------------------------------" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << "mat[" << i << "][" << j << "] = ";
				cin >> mat[i][j];
			}
		}
		break;
	}
	case 2:
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				mat[i][j] = rand() % 4;
			}
		}
		break;
	}
	default:
		goto start;
	}
	cout << "----------------------------------------------------" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "mat[" << i << "][" << j << "] = " << mat[i][j] << "\t";
			
		}
		cout << endl;
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < m-1; j++)
		{
			if (mat[i][j] != mat[i + 1][j] && 
				mat[i][j] != mat[i][j+1] && 
				mat[i][j] != mat[i + 1][j+1] && 
				mat[i][j+1] != mat[i + 1][j] && 
				mat[i][j+1] != mat[i+1][j+1] && 
				mat[i+1][j] != mat[i+1][j+1]
				)
			{
				count++;
			}
		}
	}
	cout << "----------------------------------------------------" << endl;
	cout << "Amount of groups which all element different = " << count<< endl;
	cout << "----------------------------------------------------" << endl;
}
