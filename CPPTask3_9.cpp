#include <iostream>
#include <string>

template <typename T>
class MyContainer {
private:
    T* data;        // Динамический массив для хранения данных
    int capacity;   // Емкость контейнера
    int size;       // Размер контейнера

public:
    MyContainer(int initialCapacity = 10)
        : capacity(initialCapacity), size(0) {
        data = new T[capacity];
    }

    ~MyContainer() {
        delete[] data;
    }

    void add(const T& element) {
        if (size == capacity) {
            // Увеличение емкости контейнера вдвое при необходимости
            capacity *= 2;
            T* newData = new T[capacity];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[size++] = element;
    }

    void display() const {
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    // Использование шаблона класса с различными типами данных
    MyContainer<int> intContainer;
    intContainer.add(10);
    intContainer.add(20);
    intContainer.add(30);
    std::cout << "Int Container: ";
    intContainer.display();

    MyContainer<std::string> stringContainer;
    stringContainer.add("Hello");
    stringContainer.add("World");
    std::cout << "String Container: ";
    stringContainer.display();

    return 0;
}
