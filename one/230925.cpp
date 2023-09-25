#include <iostream>
using namespace std;

int * argSelectionSort(int *a, const int n);
int* SelectionSort(int *a, const int n);

int main() {
	int test[5] = {20, 30, 10, 15, 40};
	int *index = SelectionSort(test, 5);
	//{2,0,1}
	for (int i = 0; i < 5; i++)
	{
		cout << index[i];
	}
}

int * argSelectionSort(int *a, const int n) {
	int * a2 = new int[n];
	for (int i = 0; i < n; i++)
	{
		a2[i] = a[i];
	}

	int * arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = i;
	}

	for (int i = 0; i < n; i++)
    {
		int j = i;
		for (int k = i + 1; k < n; k++)
		{
    		if (a2[k] < a2[j]) j = k;
		}
		swap(a2[i], a2[j]);
		swap(arr[i], arr[j]);
	}

	delete[] a2;
	return arr;
}

int* SelectionSort(int *a, const int n) {
    int *result = new int[n];
    for (int i = 0; i < n; i++) {
        result[i] = i;
    }

    for (int i = 0; i < n; i++) {
        int j = i;
        for (int k = i + 1; k < n; k++) {
            if (a[result[k]] < a[result[j]]) {
                j = k;
            }
        }
        
        swap(result[i], result[j]);
    }

    return result;
}