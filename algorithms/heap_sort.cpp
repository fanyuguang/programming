#include <iostream>

using namespace std;

class MaxHeap {
public:
  MaxHeap(int *array, int size) {
		heap = new int[size];
		for (int i = 0; i < size; i++) {
			heap[i] = array[i];
		}
		heap_size = size;
  }
	
  void heap_fix_up(int index) {
    if (index >= heap_size || index < 0) {
			return;
		}
		int element_copy = heap[index];
		int index_parent = (index - 1) / 2;
		while (index_parent > 0 && heap[index_parent] < element_copy) {
			heap[index] = heap[index_parent];
			index = index_parent;
			index_parent = (index - 1) / 2;
		}
		heap[index] = element_copy;
	}

	void heap_fix_down(int index, int end_index) {
		if (index >= heap_size || index < 0) {
			return;
		}
		int index_child = index * 2 + 1;
		while (index_child < end_index) {
			if (index_child + 1 < end_index && heap[index_child + 1] > heap[index_child]) {
				index_child++;
			}
			if (heap[index_child] > heap[index]) {
				int temp = heap[index];
				heap[index] = heap[index_child];
				heap[index_child] = heap[index];
			} else {
				break;
			}
			index = index_child;
			index_child = index * 2 + 1;
		}
	}

	void heap_sort() {
		for (int i = heap_size / 2 - 1; i > 0; i--) {
			heap_fix_down(i, heap_size);
		}
		for (int i = heap_size - 1; i > 0; i--) {
			int temp = heap[i];
			heap[i] = heap[0];
			heap[0] = temp;
			heap_fix_down(0, i - 1);
		}
	}

	void print_max_heap() {
		for (int i = 0; i < heap_size; i = i * 2 + 1) {
			for (int j = i; j < i * 2 + 1 && j < heap_size; j++) {
				cout << j << " ";
			}
			cout << endl;
		}
	}

	~MaxHeap() {
		delete [] heap;
	}

private:
  int *heap;
  int heap_size;
};

int main() {
	int array[] = {14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	MaxHeap max_heap(array, 15);
	max_heap.heap_sort();
	max_heap.print_max_heap();
  return 0;
}
