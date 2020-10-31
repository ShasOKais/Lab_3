#include <iostream>

using namespace std;

template <typename T> class SimpleVector {
public:
    typedef T* iterator; // ��������� �� ������
protected:
    int Size; // ������ �������
    int maxsize; // ���������� ������ ��� �������
    const int C = 2; // ��������� ���������� ������
    T* a; // ����� �������
    iterator begin_; // �������� �� ������ �������
    iterator end_; // �������� �� ����� �������
    void recreate() { // ��������� ������ ��� �������
        maxsize = maxsize ? maxsize : 1; // ������� ��� ������� ������ ������� �� ����� ����� 0
        T* b = new T[this->maxsize * C]; // ��������� ������ ��� ������� �������
        for (int i(0); i < this->Size; i++) {
            b[i] = a[i]; // ���������������� ������ � 100 -> 200 � ������������ �������� "�[]"
        }
        if (a) delete[] a;
        a = b;
        maxsize *= C;
    }
public:
    SimpleVector() {
        begin_ = end_ = NULL;
        a = NULL;
        Size = 0;
        maxsize = 0;
    }
    SimpleVector(int sz) {
        this->Size = sz;
        maxsize = sz;
        a = new T[sz]; // �������� ������ ��� �������
        begin_ = &a[0]; // ����������� ��������� begin_ �� ������ �������
        end_ = &a[Size - 1]; // ����������� ��������� end_ �� ������ �������
        end_++; // ����� ����� ������� �� �������� �� ��������� ������
    }
    T& operator [] (int index) {
        try {
            if (index >= this->Size) {
                throw(index);
            }
        }
        catch (int nm) {
            cout << "����� �� ������� ������� :" << nm << endl;
        }
        return this->a[index];
    }
    iterator begin() {
        return begin_;
    }
    iterator end() {
        return end_;
    }
    void push_back(T x) {
        if (this->Size + 1 > this->maxsize) {
            this->recreate();
        }
        this->Size++;
        a[this->Size - 1] = x;
        if (!begin_) begin_ = end_ = &a[0];
        end_++;
    }
    void pop_back() {
        try {
            if (Size == 0) throw(0);
        }
        catch (int i) {
            cout << "���������� �������";
        }
        this->a[Size - 1] = 0;
        Size--;
        end_--;
    }
    void erase(int first, int last) {
        try {
            if (first > last || first < 0 || last >= Size) throw(1);
        }
        catch (int i) {
            cout << "����� �� �������";
        }
        for (int i(last + 1), j(first); i < this->Size; i++, j++) {
            a[j] = a[i];
        }
        this->Size -= (last - first + 1);
        end_ = &a[Size];
        end_++;
    }
    void print() {
        try {
            for (int i(0); i < this->Size; i++) {
                cout << a[i] << " ";  
            }
        }
        catch (int a) {
            cout << "������ ����! ������� ����������!" << a;
        }
        
    }
    int size() {
        return this->Size;
    }
    void clear() {
        Size = maxsize = 0;
        if (a) {
            delete[] a;
        }
        end_ = begin_ = NULL;
        a = nullptr;
    }
    bool empty() {
        return !(this->Size);
    }
    T back() {
        try {
            if (!Size) throw(2);
        }
        catch (int i) {
            cout << "������ ��������������� ��������";
        }
        return a[Size - 1];
    }
    T front() {
        try {
            if (!Size) throw(1);
        }
        catch (int i) {
            cout << "������ ��������������� ��������";
        }
        return a[0];
    }
    ~SimpleVector() {
        if (a) {
            delete[]a;
        }
    }
};