#include <iostream>


int starting_point(int* arr,int size, int& point) {
	int left = 0;
	int right = size - 1;
	int counter = 0;
	if (point < arr[0])return size;
	else if (point > arr[size-1])return 0;
	else {
		while (left < right) {
			int middle = (left + right) / 2;

			if (arr[middle] == point) {
				if (arr[middle + 1] > point) return size - middle + 1;
				else left = middle + 1;
			}
			else if (arr[middle] > point) {

				if (arr[middle - 1] <= point)return size - middle;
				else right = middle - 1;

			}
			else if (arr[middle] < point) {
				left = middle + 1;
			}

		}
	}
	

}



int main(int argc, char** argv)
{

	setlocale(LC_ALL, "russian");
	const int size = 9;
	int mass[size] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
	int point = 0;
	std::cout << "Введите точку отсчета: ";
	std::cin >> point;

	
	std::cout <<"Количество элементов в массиве больших, чем " << point << " : "  << starting_point(mass, size, point);
	return 0;
}