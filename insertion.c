// Insertion sort in C with argc argv

#include <stdio.h>
#include <stdlib.h>

// Function to print an array


int *insertionSort(int *array, int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<array[j] to key>array[j].
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
  return (array);
}

// Driver code
int main(int argc, char **argv) {
	int array[argc - 1];
	int i;
	i = 0;
	while (argv[i + 1])
	{
		array[i] = atol(argv[i + 1]);
		i++;
	}
  insertionSort(array, argc - 1);
  printf("Sorted array in ascending order:\n");
  i = 0;
  for (int i = 0; i < argc - 1; i++) 
  {
	printf("%d ", array[i]);
  }
  printf("\n");
}