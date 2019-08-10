#include <iostream>

using namespace std;

int main(){

  int *array;
  int size;

  cin>>size;

//Проверка количества элементов в массиве
  if (size <= 0) {
    cerr << "Invalid size" << endl;
    return 1;
  }

  array = new int[size]; //Выделение памяти под массив

//Заполнение массива переменными
  for(int i = 0; i < size; i++){
    array[i] = 1 + rand() % 100;
  }

//Сортировка массива выбором
  for(int i = 0; i < size; i++){
      int max;
      max = array[0];

      for(int j = i + 1; j <= size; j++){

          if (array[i] > array[j]){
              max = array[i];
              array[i] = array[j];
              array[j] = max;
          }
      }
  }

//Вывод отсортированного массива
  for(int i = 0; i < size; i++){
    cout << array[i] << " ";
  }

  delete [] array;//Освобождение памяти

  return 0;
}
