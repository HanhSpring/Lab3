#include <iostream>

using namespace std;

int partition(int a[], int l, int r) {
	int pivot = a[l];
	int i = l - 1; int j = r + 1;
	while (1) {
		do {
			++i;
		} while (a[i] < pivot);
		
		do {
			--j;
		} while (a[j] > pivot);
		if (i < j) {
			swap(a[i], a[j]);
		}
		else
			return j;
	}
	++i;
	swap(a[i], a[r]);
	return i;
}

void quickSort(int a[], int l, int r) {
	if (l >= r)
		return;
	int p = partition(a, l, r);
	quickSort(a, l, p);
	quickSort(a, p + 1, r);
}

void shellSort(int a[], int n) {
	int interval, i, j, temp;
	for (interval = n / 2; interval > 0; interval /= 2) {
		for (i = interval; i < n; i++) {
			temp = a[i];
			for (j = i; j >= interval && a[j - interval] > temp; j -= interval) {
				a[j] = a[j - interval];
			}
			a[j] = temp;
		}
	}
}

void insertionSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int x = a[i];
		int pos = i - 1;
		while (pos >= 0 && x < a[pos]) {
			a[pos + 1] = a[pos];
			--pos;
		}
		a[pos + 1] = x;
	}
}

int main() {
	int a[] = {9,8,7,2,4,5,1,4,4};
	for (int i = 0; i < 9; i++) {
		cout << a[i] << "  ";
	}
	cout << endl;
	/*quickSort(a, 0, 9-1);*/
	/*shellSort(a, 9);*/
	insertionSort(a, 9);
	for (int i = 0; i < 9; i++) {
		cout << a[i] << "  ";
	}
}
