#include <iostream>
#include "SimpleVector.h"
#include <chrono>
#define SP system("pause")
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int n; 
    cin >> n;
    SimpleVector<int>MyVector(n);
    for (int i = 0; i < n; i++) {
        MyVector[i] = i;
    }
    cout << "\nВывод вектора на экран:";
    for (int i = 0; i < n; i++) {
        cout << MyVector[i] << " ";
    }
    cout << "\nВывод вектора по итератором: ";
    for (SimpleVector<int>::iterator it = MyVector.begin(); it != MyVector.end(); it++) {
        cout << *it << " ";
    }

    auto Begin1 = std::chrono::steady_clock::now(); // засекаем время

    cout << "\nMyVector.erase - ";  MyVector.erase(1, 5); MyVector.print();
    cout << "\nMyVector.push.back(m) - ";  MyVector.push_back(666); MyVector.push_back(666); MyVector.print();
    cout << "\nMyVector.pop_back() - ";  MyVector.pop_back(); MyVector.print();
    cout << "\nMyVector.size() - " <<  MyVector.size();
    cout << "\nMyVector.back() - " << MyVector.back();
    cout << "\nMyVector.front() - " <<  MyVector.front();
    cout << "\nMyVector.clear() - ";  MyVector.clear();

    auto End1 = std::chrono::steady_clock::now(); // обрываем
    auto elapsed_vector1 = std::chrono::duration_cast<std::chrono::milliseconds>(End1 - Begin1);
    std::cout << "The time: " << elapsed_vector1.count() << " ms\n";
    /*
    * Список доступных функций:
    * SimpleVector<int>myvector(n)
    * SimpleVector<int>::iterator it = ***
    * MyVector.push_back();
    * MyVector.pop_back();
    * MyVector.erase();
    * MyVector.size();
    * MyVector.clear();
    * MyVector.empty();
    * back();
    * front();
    */
    return 0;
}