/*
map 사용법

//선언
map<string, string> users;

//삽입
users.insert(make_pair(key, value));

//삭제
users.erase(key);

//검색
auto user_pair = users.find(key);
if (user_pair != users.end())
    value = user_pair->second;

*/

/* vector 사용법

//선언
vector<string> users;

//삽입
users.push_back(value);
users.insert(value);

//삭제
users.pop_back();
users.erase(index);
users.erase(value);

//검색
value = users.at(index);

//정렬
bool compare(T i, T j) { return i.d < j.d; } //오름차순
sort(users.begin(), users.end(), compare);
//greater<T>()
//less<T>()

*/


/*
//퀵 정렬
int compare(const void *a, const void *b) {
    T arg1 = *(const T*) a;
    T arg2 = *(const T*) b;

    if (arg1.d < arg2.d) return -1;
    if (arg1.d > arg2.d) return 1;
    return 0;
}

int size = sizeof(arr) / sizeof(int);
int typeSize = sizeof(T);
qsort(arr, size, typeSize, compare);

*/