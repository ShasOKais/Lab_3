#include <iostream>
#include "SimpleVector.h"
#include <vector>
#include <chrono>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int n; 
    cin >> n;
    SimpleVector<int>MyVector(n);
    for (int i = 0; i < n; i++) {
        cin >> MyVector[i];
    }
    cout << "\n����� ������� �� �����:";
    for (int i = 0; i < n; i++) {
        cout << MyVector[i] << " ";
    }

    cout << "\n����� ������� �� ����������: ";
    for (SimpleVector<int>::iterator it = MyVector.begin(); it != MyVector.end(); it++) {
        cout << *it << " ";
    }

    auto Begin1 = std::chrono::steady_clock::now(); // �������� �����

    cout << "\nMyVector.***** - ";  MyVector.erase(1, 5);

    auto End1 = std::chrono::steady_clock::now(); // ��������
    auto elapsed_vector1 = std::chrono::duration_cast<std::chrono::milliseconds>(End1 - Begin1);
    std::cout << "The time: " << elapsed_vector1.count() << " ms\n";

    /*
    * SimpleVector<int>myvector(n)
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