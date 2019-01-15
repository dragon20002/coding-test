import java.util.*;
import java.lang.*;
import java.io.*;

class MinHeap {
	int[] heap;
	int size;
	
	public MinHeap(int maxSize) {
		heap = new int[maxSize];
		size = 0;
	}
	
	public void insert(int v) {
		int i = ++size;
		while (i != 1 && v < heap[i/2]) {
			heap[i] = heap[i/2];
			i/=2;
		}
		heap[i] = v;
	}
	
	public int delete() {
		int parent = 1, child = 2;
		int v = heap[1], tmp = heap[size--];
		
		while (child <= size) {
			if (child < size && heap[child] > heap[child+1]) child++;
			if (tmp < heap[child]) break;

			heap[parent] = heap[child];
			parent = child;
			child += child;
		}
		heap[parent] = tmp;
		return v;
	}

	public static void main (String[] args) throws java.lang.Exception
	{
        MinHeap heap = new MinHeap(5);
        heap.insert(10);
        heap.insert(5);
        heap.insert(30);
        System.out.println(heap.delete());
        System.out.println(heap.delete());
        System.out.println(heap.delete());
	}

}
