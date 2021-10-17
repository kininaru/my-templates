#include "iostream"
#include "./trees/min_heap.h"

using namespace std;

void print_heap(min_heap<int> h) {
    int len = h.size();
    for (int i = 1; i <= len; ++i) cout << h[i] << " ";
}

int main() {
    min_heap<int> h(2);
    h.push(1);
    h.push(2);
    h.push(3);
    h.push(4);
    h.push(5);
    h.push(6);
    return 0;
}
