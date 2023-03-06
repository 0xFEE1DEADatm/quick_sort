#include <iostream>
#include <random>

int partition(int* A, int len);
void input_array(int array[], int len);
void output_array(int array[], int len);
void quick_sort(int* A, int len);
int find_max(int* A, int len);

int main()
{
	srand(time(0));
	const int N = 8;
	int array[N];
	input_array(array, N);
	output_array(array, N);
	quick_sort(array, N);
	output_array(array, N);
	std::cin.get();
	return 0;
}

int find_max(int* A, int len) {
	if (len > 1) {
		int s = partition(A, len);
		find_max(A + s, len - s - 1);
	}
	else return *A;
}

void quick_sort(int* A, int len)
{
	if (len > 1) {
		int s = partition(A, len);
		quick_sort(A, s);
		quick_sort(A + s + 1, len - s - 1);
	}
}

int partition(int* A, int len) {
	int p = *A;
	int i = 0, j = len;

	do {
		do {
			++i;
		} while (A[i] < p);

		do {
			--j;
		} while (A[j] > p);

		std::swap(A[i], A[j]);
	} while (i <= j);
	std::swap(A[i], A[j]);
	std::swap(*A, A[j]);
	return j;
}

void output_array(int array[], int len) {
	for (int i = 0; i < len; ++i)
		std::cout << array[i] << ' ';
	std::cout << '\n';
}

void input_array(int array[], int len) {
	for (int i = 0; i < len; ++i)
		array[i] = rand() % 10;
}
