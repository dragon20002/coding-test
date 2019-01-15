#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
	int key;
	Node *left, *right;

	Node(int key): key(key), left(NULL), right(NULL) {}
};

struct bst {
	Node* root = NULL;

	void insertNode(int key) {
		// 노드를 추가할 위치 선택
		Node *parent = NULL, *current = root;
		while (current != NULL) {
			parent = current;
			if (key < current->key)
				current = current->left;
			else if (key > current->key)
				current = current->right;
			else {
				//printf("key duplicated!\n");
				return;
			}
		}

		// 노드 생성
		Node* node = new Node(key);

		// 노드 추가
		if (parent == NULL)
			root = node;
		else {
			if (key < parent->key)
				parent->left = node;
			else
				parent->right = node;
		}
	}

	Node* search(Node* node, int key) {
		// 노드가 없으면 NULL 반환
		if (node == NULL) return NULL;

		// key와 비교하여 node 반환
		if (key == node->key) return node;
		else if (key < node->key)
			return search(node->left, key);
		else
			return search(node->right, key);
	}

	void search(int key) {
		Node* current = root;
		while (current != NULL) {
			// key와 비교하여 node 출력
			if (key < current->key) {
				current = current->left;
				printf("L");
			}
			else if (key > current->key) {
				current = current->right;
				printf("R");
			}
			else {
				printf("%d\n", current->key);
				return;
			}
		}
		printf("no key!\n");
	}


    void deleteNode(int key) {
        Node *parent, *child;
        Node *succ, *succP, *temp;

		// 노드를 삭제할 위치 선택
        parent = NULL, temp = root;
        while (temp != NULL && temp->key != key) {
            parent = temp;
            temp = (key < temp->key) ? temp->left : temp->right;
        }
        // 삭제할 노드가 없으면 종료
        if (temp == NULL) return;

        // temp가 단말노드인 경우
        if (temp->left == NULL && temp->right == NULL) {
            if (parent != NULL) {
                if (parent->left == temp)
                    parent->left = NULL;
                else
                    parent->right = NULL;
            }
            else root = NULL;
        }
        // 한 쪽에 자식노드가 있는 경우
        else if (temp->left == NULL || temp->right == NULL) {
            child = (temp->left != NULL) ? temp->left : temp->right;
            if (parent != NULL) {
                if (parent->left == temp)
                    parent->left = child;
                else
                    parent->right = child;
            }
            else root = child;
        }
        // 양 쪽에 자식노드가 있는 경우
        else { //temp->left != NULL && temp->right != NULL
            succP = temp, succ = temp->right;
            while (succ->left != NULL) {
                succP = succ;
                succ = succ->left;
            }

            if (succP->left == succ)
                succP->left = succ->right;
            else
                succP->right = succ->right;

            temp->key = succ->key;
            temp = succ;
        }

        delete temp;
    }

};


int main(void) {
	bst bst;

	bst.insertNode(5);
	bst.insertNode(4);
	bst.insertNode(7);
	bst.insertNode(3);
	bst.search(5);
	bst.search(4);
	bst.search(7);
	bst.search(3);
	bst.deleteNode(4);
	bst.search(3);
}
