#include <iostream>

using namespace std;

class MyVector {
public:
    MyVector() : data(nullptr), size(0) {}

    void push_back(int value) {
        int* newData = new int[size + 1];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        newData[size] = value;
        delete[] data;
        data = newData;
        ++size;
    }

    int& operator[](int index) {
        return data[index];
    }

    int getSize() const {
        return size;
    }

    ~MyVector() {
        delete[] data;
    }

private:
    int* data;
    int size;
};

int main() {
    // Введення кількості чисел
    std::cout << "Введіть кількість чисел: ";
    int n;
    std::cin >> n;

    // Введення послідовності чисел
    MyVector numbers;
    std::cout << "Введіть послідовність чисел: ";
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        numbers.push_back(num);
    }

    // Перевірка чи послідовність вже впорядкована
    bool isSortedAscending = true;
    bool isSortedDescending = true;
    for (int i = 1; i < numbers.getSize(); ++i) {
        if (numbers[i - 1] > numbers[i]) {
            isSortedAscending = false;
        }
        if (numbers[i - 1] < numbers[i]) {
            isSortedDescending = false;
        }
    }

    if (isSortedAscending || isSortedDescending) {
        std::cout << "Послідовність впорядкована." << std::endl;
        return 0;
    }

    // Вибір способу сортування
    std::cout << "Оберіть спосіб сортування (1 - зростання, 2 - спадання): ";
    int sortOption;
    std::cin >> sortOption;

    // Сортування у вибраному порядку
    for (int i = 0; i < numbers.getSize(); ++i) {
        for (int j = 0; j < numbers.getSize() - i - 1; ++j) {
            if ((sortOption == 1 && numbers[j] > numbers[j + 1]) ||
                (sortOption == 2 && numbers[j] < numbers[j + 1])) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    if (numbers.getSize() >= 2) {
        int lastIdx = numbers.getSize() - 1;
        int secondLastIdx = lastIdx - 1;
        if (sortOption == 1) {
            int temp = numbers[lastIdx];
            numbers[lastIdx] = numbers[secondLastIdx];
            numbers[secondLastIdx] = temp;
        }
        else {
            int temp = numbers[secondLastIdx];
            numbers[secondLastIdx] = numbers[lastIdx];
            numbers[lastIdx] = temp;
        }
    }

    // Виведення відсортованої та зміненої послідовності   
    std::cout << "Відсортована послідовність: ";
    for (int i = 0; i < numbers.getSize(); ++i) {
        std::cout << numbers[i] << " ";
    }

    return 0;
}