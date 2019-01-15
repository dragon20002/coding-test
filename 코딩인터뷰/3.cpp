#include <stdio.h>
#include <stdlib.h>

class Animal {
public:
	int order = 0;
	const char* name;
	Animal() {}
	Animal(const char* name) : name(name) {}
	virtual void f() {}
};
class Dog : public Animal {
public:
	Dog() {}
	Dog(const char* name) : Animal(name) {}
};
class Cat : public Animal {
public:
	Cat() {}
	Cat(const char* name) : Animal(name) {}
};

template <typename T>
class ValueNode {
public:
	T value;
	ValueNode* next;
	T min;

	ValueNode(T value) {
		this->value = value;
		this->next = NULL;
	}

	ValueNode(T value, ValueNode* next) {
		this->value = value;
		this->next = next;
	}
};

// min을 기록하는 stack을 하나 더 만들어 볼 것
template <typename T>
class Stack {
	int size = 0;

public:
	ValueNode<T>* top = NULL;
	Stack* next;

	T pop() {
		if (top == NULL) {
			printf("empty");
			exit(1);
		}
		T value = top->value;
		ValueNode<T>* del = top;
		top = top->next;
		delete del;
		size--;
		return value;
	}

	void push(T item) {
		ValueNode<T>* tmp = top;

		top = new ValueNode<T>(item, top);

		top->min = (tmp == NULL || tmp->min > item) ? item : tmp->min;
	
		size++;
	}

	T peek() {
		if (top == NULL) {
			printf("empty");
			exit(1);
		}

		return top->value;
	}

	T min() {
		if (top == NULL) {
			printf("empty");
			exit(1);
		}
		return top->min;
	}

	bool isEmpty() {
		return top == NULL;
	}

	int getSize() {
		return size;
	}

	void sort() {
		Stack<int> tmpstack;
		while (!isEmpty()) {
			int a = pop();

			while (!tmpstack.isEmpty() && tmpstack.peek() > a)
				push(tmpstack.pop());

			tmpstack.push(a);
		}

		while (!tmpstack.isEmpty())
			push(tmpstack.pop());
	}
};

template <typename T>
class SetOfStacks {
	int maxSize = 3;

	Stack<T>* top = NULL;

public:
	T pop() {
		if (top == NULL) {
			printf("empty");
			exit(1);
		}
		T value = top->pop();
		if (top->isEmpty()) {
			Stack<T>* del = top;
			top = top->next;
			delete del;
		}
		return value;
	}

	void push(T item) {
		if (top == NULL || top->getSize() >= maxSize) {
			Stack<T>* s = new Stack<T>();
			s->next = top;
			top = s;
		}
		top->push(item);
	}

	T peek() {
		if (top == NULL) {
			printf("empty");
			exit(1);
		}
		return top->top->value;
	}

	T min() {
		if (top == NULL) {
			printf("empty");
			exit(1);
		}
		return top->top->min;
	}

	bool isEmpty() {
		return top == NULL;
	}

};

template <typename T>
class Queue {
	ValueNode<T> *first = NULL, *last = NULL;

public:
	void add(T item) {
		ValueNode<T>* t = new ValueNode<T>(item);
		if (last != NULL) last->next = t;
		last = t;
		if (first == NULL) first = last;
	}

	T remove() {
		if (first == NULL) {
			printf("empty");
			exit(1);
		}

		T value = first->value;
		ValueNode<T>* del = first;
		first = first->next;
		delete del;
		if (first == NULL)
			last = NULL;
		return value;
	}

	T peek() {
		if (first == NULL) {
			printf("empty");
			exit(1);
		}
		return first->value;
	}

	bool isEmpty() {
		return first == NULL;
	}

};

class AnimalQueue {
	Queue<Dog> q1;
	Queue<Cat> q2;
	int order = 0;

public:
	void enqueue(Animal* animal) {
		animal->order = order++;

		if (Dog* dog = dynamic_cast<Dog*>(animal))
			q1.add(*dog);
		else if (Cat* cat = dynamic_cast<Cat*>(animal))
			q2.add(*cat);
		else
			printf("enqueue failed\n");
	}

	Animal dequeueAny() {
		if (q1.isEmpty())
			return q2.remove();
		else if (q2.isEmpty())
			return q1.remove();

		if (q1.peek().order < q2.peek().order)
			return q1.remove();
		else
			return q2.remove();
	}

	Dog dequeueDog() {
		return q1.remove();
	}

	Cat dequeueCat() {
		return q2.remove();
	}

};

int main() {
	Stack<int> stack;
	Queue<int> queue;

	stack.push(1);
	stack.push(2);
	stack.push(30);
	stack.push(4);
	stack.push(5);

	stack.sort();

	while (!stack.isEmpty())
		printf("%d\n", stack.pop());

	AnimalQueue aq;
	Dog dog1("dog1"), dog2("dog2"), dog3("dog3");
	Cat cat1("cat1"), cat2("cat2"), cat3("cat3");
	aq.enqueue(&dog1);
	aq.enqueue(&dog2);
	aq.enqueue(&cat1);
	aq.enqueue(&dog3);
	aq.enqueue(&cat2);
	aq.enqueue(&cat3);

	printf("A %s\n", aq.dequeueAny().name);
	printf("D %s\n", aq.dequeueDog().name);
	printf("C %s\n", aq.dequeueCat().name);
	printf("A %s\n", aq.dequeueAny().name);
	printf("C %s\n", aq.dequeueCat().name);
	printf("A %s\n", aq.dequeueAny().name);
}