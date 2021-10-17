template<typename T>
class stack_node {
public:
    T data;
    stack_node<T> *next;
    explicit stack_node(T data);
    stack_node(T data, stack_node<T> *next);
};

template<typename T>
stack_node<T>::stack_node(T data): data(data) {
}

template<typename T>
stack_node<T>::stack_node(T data, stack_node<T> *next): data(data), next(next) {
}

template<typename T>
class stack {
    int len;
    stack_node<T> *core;
public:
    stack();
    int size();
    bool push(T data);
    void pop();
    T top();
    T operator[](int index);
};

template<typename T>
stack<T>::stack(): len(0), core(nullptr) {
}

template<typename T>
int stack<T>::size() {
    return len;
}

template<typename T>
bool stack<T>::push(T data) {
    auto new_top = new stack_node<T>(data, this->core);
    if (new_top == nullptr) return false;
    core = new_top;
    len++;
    return true;
}

template<typename T>
void stack<T>::pop() {
    if (this->len == 0) return;
    auto needs_delete = this->core;
    core = core->next;
    len--;
    delete needs_delete;
}

template<typename T>
T stack<T>::top() {
    return core->data;
}

template<typename T>
T stack<T>::operator[](int index) {
    int i = this->len - index - 1;
    auto ptr = this->core;
    while (i--) ptr = ptr->next;
    return ptr->data;
}
