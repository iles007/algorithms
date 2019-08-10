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

  int temp; // временная переменная для обмена элементов местами

// Сортировка массива пузырьком
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {

        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

// Вывод отсортированного массива на экран
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  delete [] arr; // освобождение памяти;

  return 0;
}
