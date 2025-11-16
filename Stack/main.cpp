#include <iostream>
#include <chrono>
#include "ArrStack.h"
#include "LinkStack.h"

using namespace std;

int main() {
    const int N = 1000000;

    
    ArrayStack<int> arrayStack(N);
    LinkedStack<int> linkedStack;

    // ---- ArrayStack ----
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) arrayStack.push(i);
    for (int i = 0; i < N; i++) arrayStack.pop();
    auto end = chrono::high_resolution_clock::now();

    cout << "ArrayStack time: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";

    // ---- LinkedStack ----
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) linkedStack.push(i);
    for (int i = 0; i < N; i++) linkedStack.pop();
    end = chrono::high_resolution_clock::now();

    cout << "LinkedStack time: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";

    return 0;
}
