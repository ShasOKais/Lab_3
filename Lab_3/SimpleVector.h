#include <iostream>

using namespace std;

template <typename T> class SimpleVector {
public:
    typedef T* iterator; // указатель на объект
protected:
    int Size; // Размер вектора
    int maxsize; // Выделенная память для вектора
    const int C = 2; // Множитель выделяемой памяти
    T* a; // адрес вектора
    iterator begin_; // Итератор на начало массива
    iterator end_; // Итератор на конец массива
    void recreate() { // Выделение памяти для вектора
        maxsize = maxsize ? maxsize : 1; // Условие при котором размер вектора не будет равен 0
        T* b = new T[this->maxsize * C]; // Выделение памяти для объекта массива
        for (int i(0); i < this->Size; i++) {
            b[i] = a[i]; // Перераспределние памяти с 100 -> 200 и последующего удаления "а[]"
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
        a = new T[sz]; // Выделяем память под объекты
        begin_ = &a[0]; // Присваиваем итератору begin_ на начало вектора
        end_ = &a[Size - 1]; // Присваиваем итератору end_ на начало вектора
        end_++; // Чтобы конец вектора не указывал на последний индекс
    }
    T& operator [] (int index) {
        try {
            if (index >= this->Size) {
                throw(index);
            }
        }
        catch (int nm) {
            cout << "Выход за границы массива :" << nm << endl;
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
            cout << "Невозможно удалить";
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
            cout << "Выход за границы";
        }
        for (int i(last + 1), j(first); i < this->Size; i++, j++) {
            a[j] = a[i];
        }
        this->Size -= (last - first + 1);
        end_ = &a[Size];
        end_++;
    }
    void print() {
        for (int i(0); i < this->Size; i++) {
            cout << a[i] << " ";
        }
    }
    int size() {
        return this->Size;
    }
    void clear() {
        Size = maxsize = 0;
        if (a) delete[] a;
        end_ = begin_ = NULL;
    }
    bool empty() {
        return !(this->Size);
    }
    T back() {
        try {
            if (!Size) throw(2);
        }
        catch (int i) {
            cout << "Запрос несущуствующего элемента";
        }
        return a[Size - 1];
    }
    T front() {
        try {
            if (!Size) throw(1);
        }
        catch (int i) {
            cout << "Запрос несущуствующего элемента";
        }
        return a[0];
    }
    ~SimpleVector() {
        delete[]a;
    }
};