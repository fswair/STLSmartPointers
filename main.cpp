#include <iostream>
#include <memory>

using namespace std;

template <typename T>
using uptr = std::unique_ptr<T>;

template <typename T>
uptr<T> foo(uptr<T> ptr) {
    return ptr;
}

int main() {
    uptr<int> tp1{new int};
    uptr<int> tp2{new int};
    // tp = new int; syntax error
    tp1 = make_unique<int>(4); // legal
    // tp1 = tp2; illegal , no copy ctor declared
    tp2 = std::move(tp1); // legal

    // foo(tp2); call to deleted copy ctor
    foo(make_unique<int>(5)); // legal
    foo(std::move(tp2)); // legal because move ctors declared, copy ctors is not declared

    uptr<int> tp3;

    UBCHECK *tp3; // UB
    return 0;
}
