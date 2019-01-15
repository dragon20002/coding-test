#include <stdio.h>
#include <stdlib.h>

class Node {
	Node* next = NULL;
	int data;

public:
	Node() {}
	Node(int data) {
		this->data = data;
	}
	Node(Node* next, int data) {
		this->next = next;
		this->data = data;
	}

	Node* append(int data) {
		Node* end = new Node(data);
		Node* n = this;
		while (n->next != NULL)
			n = n->next;
		n->next = end;
		return this;
	}

	Node* append(Node* node) {
		if (node == NULL) return this;

		Node* n = this;
		while (n->next != NULL)
			n = n->next;
		n->next = node;
		return this;
	}

	Node* remove(Node* node) {
		for (Node* n = this; n->next != NULL; n = n->next) {
			if (n->next == node) {
				n->next = node->next;
				delete(node);
				return this;
			}
		}
		return this;
	}

	int size() {
		int count = 0;
		for (Node* n = next; n; n = n->next)
			count++;
		return count;
	}

	Node* getNext() {
		return next;
	}

	void setNext(Node* next) {
		this->next = next;
	}

	int getData() {
		return data;
	}

	void setData(int data) {
		this->data = data;
	}

	void print() {
		for (Node* n = next; n != NULL; n = n->next)
			printf("%d->", n->data);
		printf("\n");
	}
};

void solution1(Node* head) {	
	// ù��°, �ι�° ��� ����
	Node *a = head->getNext(), *b = a->getNext();

	// a�� ������ ���� ��忡 ������ ������ �ݺ�
	while (a->getNext() != NULL) {
		// a�� b�� ������ ��
		if (a->getData() == b->getData()) {
			Node* rm = b;
			if (b->getNext())
				b = b->getNext();
			head->remove(rm);
		}
		else {
			b = b->getNext();
		}

		if (b == NULL) {
			a = a->getNext();
			b = a->getNext();
		}
	}
}

// two pointer
// n�� p �Բ� �̵��ϵ��� �����غ� ��!
int solution2(Node* head, int k) {
	if (k < 0) return -1;

	for (Node* n = head->getNext(); n != NULL; n = n->getNext()) {
		// n ���κ��� k-1��° ��带 p�� ����
		Node* p = n;
		for (int i = 0; i < k - 1; i++) {
			if (p->getNext() == NULL)
				return -1;
			p = p->getNext();
		}

		// p ��尡 End�� n ����� ������ ��ȯ
		if (p->getNext() == NULL)
			return n->getData();
	}
}

void solution3(Node* node) {
	// �����尡 Tail�̸� ����
	Node* n = node->getNext();
	if (n == NULL) return;

	// ������� ������ ������� ����
	node->setData(n->getData());
	node->setNext(n->getNext());

	// ������� �Ҵ�����
	delete(n);
}

void solution4(Node* head, int x) {
	Node* tail = head->getNext();
	
	// ����Ʈ�� ��尡 ������ ����
	if (tail == NULL) return;

	// ����Ʈ Tail ����
	for (; tail->getNext() != NULL; tail = tail->getNext());

	Node* stop = tail;
	Node* n = head;
	while (n->getNext() != stop->getNext() && head->getNext() != stop) {
		// x ���� ū ���� ���� ��带 tail �������� �ű�
		if (n->getNext()->getData() >= x) {
			tail->setNext(n->getNext());
			tail = n->getNext();

			n->setNext(tail->getNext());
			tail->setNext(NULL);
		}
		else {
			n = n->getNext();
		}
	}
}

Node* solution5_1(Node* alist, Node* blist) {
	Node* clist = new Node();
	Node* ctail = clist;

	int carry = 0;
	while (1) {
		int c;
		if (alist->getNext() && blist->getNext()) {
			alist = alist->getNext();
			blist = blist->getNext();
			c = alist->getData() + blist->getData();
		}
		else if (alist->getNext() && alist->getNext()->getData() != 0) {
			alist = alist->getNext();
			c = alist->getData();
		}
		else if (blist->getNext() && blist->getNext()->getData() != 0) {
			blist = blist->getNext();
			c = blist->getData();
		}
		else {
			return clist;
		}

		if (carry) {
			c += carry;
			carry = 0;
		}

		if (c >= 10) {
			carry = 1;
			c -= 10;
		}

		Node* cnode = new Node(c);
		ctail->setNext(cnode);
		ctail = cnode;
	}
}

Node* solution5_2(Node* alist, Node* blist) {
	Node* clist = new Node();
	
	int carry = 0;
	while (1) {
		int c;
		if (alist->getNext() && blist->getNext()) {
			alist = alist->getNext();
			blist = blist->getNext();
			c = alist->getData() + blist->getData();
		}
		else if (alist->getNext() && alist->getNext()->getData() != 0) {
			alist = alist->getNext();
			c = alist->getData();
		}
		else if (blist->getNext() && blist->getNext()->getData() != 0) {
			blist = blist->getNext();
			c = blist->getData();
		}
		else {
			return clist;
		}

		if (carry) {
			c += carry;
			carry = 0;
		}

		if (c >= 10) {
			carry = 1;
			c -= 10;
		}

		Node* cnode = new Node(clist->getNext(), c);
		clist->setNext(cnode);
	}
}

// �迭�� ��ȯ�Ͽ� �غ� ��!
int solution6(Node* head) {
	while (head->getNext()) {
		// ������ ���� ��� ����
		Node* tail;
		for (tail = head->getNext(); tail->getNext() && tail->getNext()->getNext(); tail = tail->getNext());

		if (head->getNext() == tail)
			return 1;

		// head, tail ��
		if (head->getNext()->getData() != tail->getNext()->getData())
			return 0;

		tail->setNext(NULL);
		head = head->getNext();
	}

	return 1;
}

int solution7(Node* array[], Node* alist, Node* blist) {
	int apos = 0;

	for (Node* a = alist->getNext(); a; a = a->getNext()) {
		for (Node* b = blist->getNext(); b; b = b->getNext()) {
			if (a == b) {
				array[apos++] = a;
				break;
			}
		}
	}
	return apos;
}

Node* solution8(Node* head) {
	if (!head->getNext()->getNext()) return NULL;

	for (Node* a = head->getNext()->getNext(); a; a = a->getNext()) {
		for (Node* b = head->getNext(); a != b->getNext(); b = b->getNext()) {
			if (a->getNext() == b)
				return b;
		}
	}
	return NULL;
}

int main() {
	Node* n = new Node();
	n->append(5)->append(4)->append(3)->append(4)
		->append(5);
	
	n->print();

	//solution1(n);
	
	//printf("%d\n", solution2(n, 5));
	
	//solution3(n->getNext()->getNext()->getNext());

	//solution4(n, 3);

	Node* n1 = new Node();
	n1->append(0)->append(9)->append(8)->append(7)
		->append(6);

	//solution5_1(n, n1)->print();

	//solution5_2(n, n1)->print();

	//printf("is palindrome? %d\n", solution6(n));
	//printf("is palindrome? %d\n", solution6(n1));
	
	//Node* inter[5];
	//int size = solution7(inter, n->getNext()->getNext(), n);
	//for (int i = 0; i < size; i++)
	//	printf("%u %d\n", inter[i], inter[i]->getData());

	n1->append(n1->getNext()->getNext()->getNext()); //0-9-8-7-6-8-...
	Node* loop_node = solution8(n1);
	printf("%u %d\n", loop_node, loop_node->getData());

	n->print();

	getchar();
	return 0;
}