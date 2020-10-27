#include <iostream>
#include "SimpleVector.h"
#include <vector>
#include <chrono>

using namespace std;

int main() {
    int n;
    cin >> n;
	SimpleVector<int>MyVector(n);
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> MyVector[i];
    }
    for (int i = 0; i < n; i++) {
        cout << MyVector[i] << " ";
    }
    cout << "\nIterator: ";
    for (SimpleVector<int>::iterator it = MyVector.begin(); it != MyVector.end(); it++) {
        cout << *it << " ";
    }
    auto Begin1 = std::chrono::steady_clock::now();
    cout << "\nMyVector.size() - " << MyVector.size();
    auto End1 = std::chrono::steady_clock::now();
    auto elapsed_vector1 = std::chrono::duration_cast<std::chrono::milliseconds>(End1 - Begin1);
    std::cout << "The time: " << elapsed_vector1.count() << " ms\n";
    
    auto Begin2 = std::chrono::steady_clock::now();
    cout << "\nMyVector.begin() - " << MyVector.begin();
    auto End2 = std::chrono::steady_clock::now();
    auto elapsed_vector2 = std::chrono::duration_cast<std::chrono::milliseconds>(End2 - Begin2);
    std::cout << "The time: " << elapsed_vector2.count() << " ms\n";

    auto Begin3 = std::chrono::steady_clock::now();
    cout << "\nMyVector.end() - " << MyVector.end();
    auto End3 = std::chrono::steady_clock::now();
    auto elapsed_vector3 = std::chrono::duration_cast<std::chrono::milliseconds>(End3 - Begin3);
    std::cout << "The time: " << elapsed_vector3.count() << " ms\n";

    auto Begin4 = std::chrono::steady_clock::now();
    cout << "\nMyVector.print() - ";  MyVector.print();
    auto End4 = std::chrono::steady_clock::now();
    auto elapsed_vector4 = std::chrono::duration_cast<std::chrono::milliseconds>(End4 - Begin4);
    std::cout << "The time: " << elapsed_vector4.count() << " ms\n";
	return 0;
}