#include <stdio.h>
#include <stdlib.h>
void heapify(int arr[], int n, int i ) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if ( l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i) {
		int temp = arr[largest];
		arr[largest] = arr[i];
		arr[i] = temp;
		heapify(arr, n, largest);
	}
}

void heap_sort(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i);
	}

}




int main() {
	int arr[] = {21, 17, 14, 12, 11, 9, 16};
	heap_sort(arr, 7);

	printf("8. Suppose a priority queue consists of five elements implemented as max-heap which and"
	       "the level-order traversal of the heap is as follows as 21,17,14,12,11. In addition, extra two"
	       "more new elements are inserted such as '9' and '16’, in the heap, based on the order. Obtain"
	       "the level order traversal of the heap following the insertion of the element.\n\n");
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
		printf("%d ", arr[i]);
}