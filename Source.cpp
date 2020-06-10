#include <iostream>
#include <math.h>
using namespace std;

int MaxV(int N, double** arraySM)
{
	double max = 0; //max значение вершины
	int maxv = 0; //номер max вершины
	double cur = 0; //сумма рёбер текущей вершины
	for (int i = 0; i < N; i++)
	{
		cur = 0;
		for (int j = 0; j < N; j++)
		{
			cur += arraySM[i][j];
		}
		if (cur > max)
		{
			max = cur;
			maxv = i;
		}
	}
	return maxv;
}

void track(int N, double **arraySM, int *minv)
{
	double min = INT_MAX;
	for (int j = 0; j < N; j++)
	{
		if ((arraySM[*minv][j] < min)&&(arraySM[*minv][j]!=0)) 
			min = arraySM[*minv][j];
	}

	for (int j = 0; j < N; j++)
	{
		if (arraySM[*minv][j] == min)
		{
			*minv = j;
			break;
		}
	}
}

void input(int N, double** arraySM)
{
	int* arrayX = new int[N];
	int* arrayY = new int[N];

	cout << "Enter the coordinates of the elements"<<endl;
	for (int i = 0; i < N; i++)
	{
		cout << i + 1 << ":" << endl << "X=";
		cin >> arrayX[i];
		cout << "Y=";
		cin >> arrayY[i];
	}

	double a, b, c;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			a = arrayX[i] - arrayX[j];
			b = arrayY[i] - arrayY[j];
			c = sqrt(a * a + b * b);
			arraySM[i][j] = c;
			//cout << "c=" << c << endl;
		}
	}

	int count = 0; //как связаны между собой элементы, направленный граф
	cout << "How are the elements connected? If elements are connected put 1, otherwise 0"<<endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			count = 0;
			cout << i + 1 << "-" <<j+1<<": ";
			cin >> count;
			if (count == 0)
				arraySM[i][j] = 0;
		}
	}

	delete arrayX;
	delete arrayY;
}

int main()
{
	int N = 0; //количество элементов
	cout << "Enter the number of circuit elements: ";
	cin >> N;
	double** arraySM = new double* [N];
	for (int i = 0; i < N; i++) 
	{          
		arraySM[i] = new double[N];
	}

	input(N, arraySM);

	/*cout << "Fill in the matrix"<<endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin>>arraySM[i][j];
		}
	}*/

	int max = MaxV(N, arraySM);
	int cur = max;
	cout << cur + 1;
	do
	{
		track(N, arraySM, &cur);
		cout<<"-"<<cur+1;
	} while (max != cur);

	for (int i = 0; i < N; i++) 
	{
		delete[] arraySM[i];  // удаляем массив
	}
	return 0;
}