#include <iostream>

using namespace std;

  void quicksort(int *numbers, int left, int right)
  {
    int pivot;
    int left_hold = left;
    int right_hold = right;
    pivot = numbers[left];

    while (left < right){

      while ((numbers[right] >= pivot) && (left < right))
      right--; // сдвигаем правую границу пока элемент [right] больше [pivot]

      if (left != right){ // если границы не сомкнулись

        numbers[left] = numbers[right]; // перемещаем элемент [right] на место разрешающего
        left++; // сдвигаем левую границу вправо
      }

      while ((numbers[left] <= pivot) && (left < right))
      left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]

      if (left != right){ // если границы не сомкнулись

        numbers[right] = numbers[left]; // перемещаем элемент [left] на место [right]
        right--; // сдвигаем правую границу вправо
      }

    }

    numbers[left] = pivot; // ставим разрешающий элемент на место
    pivot = left;
    left = left_hold;
    right = right_hold;
    if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
      quicksort(numbers, left, pivot - 1);
    if (right > pivot)
      quicksort(numbers, pivot + 1, right);

  }


int main(){

    int *arr;
    int size;

    size = 1 + rand() % 100;

    if (size <= 0){
      cerr << "Invalid size" << endl;
      return 1;
    }

    arr = new int[size];

    for(int i = 0; i < size; i++){
      arr[i] = 1 + rand() % 100;
    }

    quicksort(arr, 0, size - 1);

    for (int i = 0; i < size; i++){
      cout<< arr[i] << " ";
    }
    cout << endl;

    delete [] arr;

    return 0;
  }
