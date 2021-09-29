/*
 * 洛谷 P1090，在题解中看到了“小根堆”这个概念。学习之后自己实现了一个。
 *
 * 感谢 https://www.luogu.com.cn/user/69166 大佬的题解。看起来十分轻松愉快，谢谢！
 */

#include "cstring"

template<typename T>
class min_heap {
    int len, expected_len;
    T *heap;
public:
    explicit min_heap(int _expected_len);
    ~min_heap();

    void push(T data);
    void pop();
    T top();
    int size();
    void resize(int _expected_len);
};

template<typename T>
min_heap<T>::min_heap(int _expected_len): expected_len(_expected_len), len(0) {
    heap = new T[expected_len];
}

template<typename T>
min_heap<T>::~min_heap() {
    delete heap;
}

template<typename T>
void min_heap<T>::push(T data) {
    if (len + 1 > expected_len)
}

template<typename T>
void min_heap<T>::resize(int _expected_len) {
    T *new_array = new T[_expected_len];
    memcpy()
}
