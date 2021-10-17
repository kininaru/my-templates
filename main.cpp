#include "iostream"
#include "./trees/min_heap.h"

using namespace std;

int main() {
    min_heap<int> h(2);
    h.push(1);
    cout << h.top();
    return 0;
}
