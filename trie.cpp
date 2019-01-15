#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define GO_MAX 26

class Trie {
public:
	Trie* go[GO_MAX];
	int branch;
	int words;
	bool output;

	Trie() {
		fill(go, go + GO_MAX, nullptr);
		branch = 0;
		words = 0;
		output = false;
	}
	~Trie() {
		for (int i = 0; i < GO_MAX; i++)
			if (go[i])
				delete go[i];
	}

	void insert(const char* key) {
		if (*key == '\0') {
			// null문자는 새로운 trie 생성 대신 output을 true로
			branch++; //null문자 + 알파벳 중에 trie로 만들어진 자식 개수
			output = true;
		}
		else {
			// 새로운 trie 생성
			int next = *key - 'a';

			// 해당 노드가 없으면 새로 만듬
			if (!go[next]) {
				branch++;
				go[next] = new Trie;
			}
			words++; //key 문자를 사용하는 단어의 갯수
			printf("%d\n", words);
			go[next]->insert(key + 1);
		}
	}

	int get(bool isRoot = false) {
		long long num = 0;

		if (isRoot || branch > 1)
			num = words;

		for (int i = 0; i < GO_MAX; i++)
			if (go[i])
				num += go[i]->get();
		return num;
	}
};

int main() {
	int n;

	while (scanf("%d", &n) > 0) {
		Trie trie;

		for (int i = 0; i < n; i++) {
			char word[81];
			scanf("%s", word);
			trie.insert(word);
		}

		float avg = (float) trie.get(true) / n;

		printf("%.2f\n", avg);
	}
}