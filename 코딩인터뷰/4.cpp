#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

const int GO_MAX = 10;

struct Node {
	int v;
	Node *left, *right;

	Node(int v): v(v), left(NULL), right(NULL) {}
};

struct Bst {
	Node* root = NULL;

	void insert(int v) {
		Node* cur = root;
		Node* parent = NULL;

		while (cur != NULL) {
			parent = cur;
			if (cur->v > v)
				cur = cur->left;
			else
				cur = cur->right;
		}

		Node* node = new Node(v);
		if (parent == NULL)
			root = node;
		else {
			if (parent->v > v)
				parent->left = node;
			else
				parent->right = node;
		}
	}

	void insertArr(int* arr, int s, int e) {
		if (s == e) return;

		int mid = (s + e) / 2;
		insert(arr[mid]);
		insertArr(arr, s, mid);
		insertArr(arr, mid + 1, e);
	}

	void search(Node* node, int h) {
		if (node == NULL) return;
		printf("%d (%d)\n", node->v, h);
		search(node->left, h + 1);
		search(node->right, h + 1);
	}

	void getHeightLists(vector<list<Node*>*> hLists, Node* node, int h) {
		if (node == NULL) return;
		hLists.at(h)->push_back(node);
		getHeightLists(hLists, node->left, h + 1);
		getHeightLists(hLists, node->right, h + 1);
	}

	int getHeight(Node* node) {
		if (node == NULL) return 0;
		int lh = getHeight(node->left);
		int rh = getHeight(node->right);
		return 1 + ((lh > rh) ? lh : rh);
	}

	bool isBalanced(Node* node) {
		if (node == NULL) return true;
		if (!isBalanced(node->left) || !isBalanced(node->right)) return false;

		int lh = getHeight(node->left);
		int rh = getHeight(node->right);
		int diff = lh - rh;
		if (diff >= -1 && diff <= 1)
			return true;
		return false;
	}

};

struct Trie {
	Trie* go[GO_MAX];
	bool output;
	bool goexist;

	Trie() {
		fill(go, go + GO_MAX, nullptr);
		output = goexist = false;
	}
	~Trie() {
		for (int i = 0; i < GO_MAX; i++)
			if (go[i]) delete go[i];
	}

	bool insert(const char* key) {
		if (*key == '\0') {
			output = true;
			return !goexist;
		}
		else {
			int next = *key - '0';
			if (!go[next]) go[next] = new Trie;
			goexist = true;
			return !output && go[next]->insert(key + 1);
		}
	}

};

int main() {
	int arr[] = { 1, 2, 4, 10 };
	Bst bst;
	bst.insert(1);
	//for (int a : arr)
	//	bst.insert(a);
	//bst.insertArr(arr, 0, 4);
	bst.search(bst.root, 1);

	vector<list<Node*>*> hLists(4);
	for (int i = 0; i < 4; i++)
		hLists.at(i) = new list<Node*>();
	bst.getHeightLists(hLists, bst.root, 0);

	for (int i = 0; i < 4; i++) {
		printf("%d : ", i);
		for (Node* node : *hLists.at(i))
			printf("%d -> ", node->v);
		printf("\n");
	}

	printf("height : %d\n", bst.getHeight(bst.root));

	if (bst.isBalanced(bst.root))
		printf("TRUE\n");
	else
		printf("FALSE\n");
}