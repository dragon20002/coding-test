#include <iostream>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

int op_rate(string op) {
	if (op.compare("*") == 0 || op.compare("/") == 0) return 0;
	else return 1;
}

string mid2back(string mid) {
	int bcnt = 0;
	stack<string> st;
	string back = "";

	stringstream ss = stringstream(mid);
	string tok;
	while (getline(ss, tok, ' ')) {

		// st.top 과 우선순위( 0순위, 1순위, ... )를 비교하여 st.top 을 pop 할 지 결정한다.
		if (tok.compare("+") == 0 || tok.compare("-") == 0
				|| tok.compare("*") == 0 || tok.compare("/") == 0) {

			while (!st.empty() && op_rate(st.top()) < op_rate(tok)) { //st.top의 우선순위가 높으면
				back += st.top() + ' '; st.pop();
			}
			st.push(tok);
		}
		// '(' 는 바로 push
		else if (tok.compare("(") == 0) {
			st.push(tok);
			bcnt++;
		}
		// ')' 는 짝이 되는 '(' 를 찾을 때까지 stack 내용을 pop 한다.
		else if (tok.compare(")") == 0) {
			while (!st.empty() && st.top().compare("(")) {
				back += st.top() + ' '; st.pop();
			}
			st.pop(); //pop left bracket
			bcnt--;
		}
		// 숫자는 무조건 'back' 뒤에 추가
		else {
			back += tok + ' ';
		}
	}

	while (!st.empty()) { //flush stack
		back += st.top() + ' '; st.pop();
	}

	if (bcnt != 0) return ""; //괄호갯수 불일치
	return back;
}

int eval(string back) {
	stack<string> st;
	stringstream ss = stringstream(back);

	string tok;
	while (getline(ss, tok, ' ')) {
		if (tok.compare("+") == 0) {
			int p1 = stoi(st.top()); st.pop();
			int p2 = stoi(st.top()); st.pop();
			st.push(to_string(p1 + p2));
		}
		else if (tok.compare("-") == 0) {
			int p1 = stoi(st.top()); st.pop();
			int p2 = stoi(st.top()); st.pop();
			st.push(to_string(p1 - p2));
		}
		else if (tok.compare("*") == 0) {
			int p1 = stoi(st.top()); st.pop();
			int p2 = stoi(st.top()); st.pop();
			st.push(to_string(p1 * p2));
		}
		else if (tok.compare("/") == 0) {
			int p1 = stoi(st.top()); st.pop();
			int p2 = stoi(st.top()); st.pop();
			if (p2 == 0) return 0;
			st.push(to_string(p1 / p2));
		}
		else { //num 은 무조건 push
			st.push(tok);
		}
	}

	return stoi(st.top());
}

int main() {
	cin.sync_with_stdio(false);
	string mid;
	while (getline(cin, mid, '\n'))
		cout << eval(mid2back(mid)) << '\n';
}

/**
 * 1. 연산자가 들어오면 스택의 top과 반복 비교하여 top의 우선순위가 높으면 top을 후위식으로 pop한다.
 *  스택이 비었거나 top의 우선순위가 낮거나 같으면 반복종료한 다음 새로 들어 온 연산자를 push한다.
 * 1.1. 우선순위는 * / 를 0 나머지 연산자 및 숫자 등을 1로 두고 0이 1보다 우선순위가 높다고 판단한다.
 * 2. (가 들어오면 스택에 push한다.
 * 3. )가 들어오면 스택이 비어있지 않고 스택의 top이 (가 아니면 top을 후위식으로 pop을 반복한다.
 *  반복이 종료되면 (를 pop한다.
 * 4. 그 이외의 경우 (숫자), 후위식에 추가한다.
 * 
 *    infix -> postfix
 *    3*(5*2+3)
 *    stack   back
 *            3
 *    *       3
 *    *(      3
 *    *(      35
 *    *(*     35
 *    *(*     352
 *    *(+     352*
 *    *(+     352*3
 *    *       352*3+
 *            352*3+*
 */

/**
 *    eval postfix
 *    352*3+*
 *    stack     postfix
 *    3         52*3+*
 *    3 5       2*3+*
 *    3 5 2     *3+*
 *    3 10      3+*
 *    3 10 3    +*
 *    3 13      *
 *    39
 */
