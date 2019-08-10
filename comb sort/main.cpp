#include <iostream>

using namespace std;

int main(){

  int *arr; // указатель для выделения памяти под массив
  int size; // размер массива

// Генерация случайного кол-ва элементов
  size = 1 + rand() % 100;

  if (size <= 0) {
// Размер массива должен быть положительным
  cerr << "Invalid size" << endl;
  return 1;
  }

  arr = new int[size]; // выделение памяти под массив

// заполнение массива случайными элементами
  for (int i = 0; i < size; i++) {
    arr[i] = 1 + rand() % 70;
  }

  ////////////// сортировка расческой //////////////

  int perm = 0; // количество перестановок
	double fakt = 1.2473309; // фактор уменьшения
	int step = size - 1;

	while (step >= 1)
	{
		for (int i = 0; i + step < size; i++)
		{
			if (arr[i] > arr[i + step])
			{
				swap(arr[i], arr[i + step]);
				perm++;
      }
		}
		step /= fakt;
	}
	  // сортировка пузырьком
	for (int i = 0; i < size - 1; i++)
	{
		bool swapped = false;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				swapped = true;
				perm++;
			}
		}

		if (!swapped)
			break;
	}


// Вывод отсортированного массива на экран
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  delete [] arr; // освобождение памяти;

  return 0;
}
