/*
 * thanks: https://www.luogu.com.cn/user/69166
 */

#include "cstring"

template<typename T>
class min_heap {
    int len, max_len, expected_len;
    T *core;

    void exchange_value(int a, int b);
    void sort();
    bool resize(int _len);
public:
    explicit min_heap(int _expected_len);
    ~min_heap();
    bool push(T data);
    void pop();
    T top();
    int size();
    T operator[](int index);
};

template<typename T>
min_heap<T>::min_heap(int _expected_len): expected_len(_expected_len), max_len(_expected_len), len(0) {
    core = new T[max_len + 1];
}

template<typename T>
min_heap<T>::~min_heap() {
    delete[] core;
}

template<typename T>
bool min_heap<T>::push(T data) {
    if (len + 1 > max_len && !this->resize(max_len + 1)) return false;
    core[++len] = data;
    this->sort();
}

// returns false when resizing failed
// makes sure that the object can be accessed from 1 to _len.
template<typename T>
bool min_heap<T>::resize(int _len) {
    T *new_core = new T[_len + 1];
    if (new_core == nullptr) return false;
    int _min = std::min(_len, len);
    for (int i = 1; i <= _min; i++) new_core[i] = core[i];
    delete[] core;
    core = new_core;
    max_len = _len;
    return true;
}

template<typename T>
void min_heap<T>::exchange_value(int a, int b) {
    if (a == b) return;
    T tmp = core[a];
    core[a] = core[b];
    core[b] = tmp;
}

template<typename T>
void min_heap<T>::pop() {
    if (len == 0) return;
    exchange_value(1, len);
    sort();
    if (--len >= this->expected_len) resize(len);
}

template<typename T>
T min_heap<T>::top() {
    return core[1];
}

template<typename T>
void min_heap<T>::sort() {
    int ptr = len, parent = len / 2;
    while (parent > 0) {
        if (core[ptr] < core[parent]) exchange_value(ptr, parent);
        ptr = parent;
        parent /= 2;
    }
}

template<typename T>
int min_heap<T>::size() {
    return len;
}

template<typename T>
T min_heap<T>::operator[](int index) {
    return core[index];
}
