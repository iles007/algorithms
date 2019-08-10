#include <iostream>



int main ()
{
  int *arr; // указатель для выделения памяти под массив
  int size; // размер массива

// Генерация случайного кол-ва элементов
  size = 1 + rand() % 100;

  if (size <= 0) {
// Размер массива должен быть положительным
  std::cerr << "Invalid size" << std::endl;
  return 1;
  }

  arr = new int[size]; // выделение памяти под массив

// заполнение массива случайными элементами
  for (int i = 0; i < size; i++) {
    arr[i] = 1 + rand() % 100;
  }

	// ----------- Сортировка ------------

    int sh = 0; // Смещение
    bool b;
    do
    {
	    b = false;
	    for (int i = 0; i < size; i++)
      {

	        if (i * 2 + 2 + sh < size)
            {
		        if ((arr[i + sh] > arr[i * 2 + 1 + sh]) || (arr[i + sh] >  arr[i * 2 + 2 + sh]))
                {
		            if (arr[i * 2 + 1 + sh] < arr[i * 2 + 2 + sh])
                    {
			            std::swap(arr[i + sh], arr[i * 2 + 1 + sh]);
			            b = true;
		            }
                    else if (arr[i * 2 + 2 + sh] < arr[i * 2 + 1 + sh])
                    {
		                std::swap(arr[i + sh], arr[i * 2 + 2 + sh]);
		                b = true;
		            }
		        }
		        // Дополнительная проверка для последних двух элементов;
                // с её помощью можно отсортировать пирамиду
                // состоящую всего лишь из трёх элементов
		        if (arr[i * 2 + 2 + sh] < arr[i * 2 + 1 + sh])
                {
			        std::swap(arr[i * 2 + 1 + sh], arr[i * 2 + 2 + sh]);
                    b = true;
			    }
	        }
            else if (i * 2 + 1 + sh < size)
            {
	            if (arr[i + sh] > arr[ i * 2 + 1 + sh])
                {
	                std::swap(arr[i + sh], arr[i * 2 + 1 + sh]);
	                b = true;
	            }
	          }
	    }
	    if (!b)
        sh++; // Смещение увеличивается, когда на текущем этапе сортировать больше нечего

    } while (sh + 2 < size); // Конец сортировки

    for (int i = 0; i < size; i++)
        std::cout << arr[i] << ' ';

    return 0;
}
