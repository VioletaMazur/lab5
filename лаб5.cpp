#include <iostream>
#include <vector>
#include <algorithm>
int main() {
	// Введення кількості чисел
	std::cout << "Введіть кількість чисел: ";
	int n;
	std::cin >> n;
	// Введення послідовності чисел
	std::vector<int> numbers;
	std::cout << "Введіть послідовність чисел: ";
	for (int i = 0; i < n; ++i) {
		int num;
		std::cin >> num;
		numbers.push_back(num);
	}
	// Перевірка чи послідовність вже впорядкована
	bool isSortedAscending = std::is_sorted(numbers.begin(), numbers.end());
	bool isSortedDescending = std::is_sorted(numbers.begin(), numbers.end(),
		std::greater<int>());
	if (isSortedAscending) {
		std::cout << "Послідовність впорядкована." << std::endl;
		return 0;
	}
	else if (isSortedDescending) {
		std::cout << "Послідовність впорядкована." << std::endl;
		return 0;
	}
	// Вибір способу сортування
	std::cout << "Оберіть спосіб сортування (1 - зростання, 2 - спадання): ";
	int sortOption;
	std::cin >> sortOption;
	// Сортування у вибраному порядку
	if (sortOption == 1) {
		std::sort(numbers.begin(), numbers.end());
	}
	else if (sortOption == 2) {
		std::sort(numbers.begin(), numbers.end(), std::greater<int>());
	}
	else {
		std::cout << "Неправильний вибір способу сортування." << std::endl;
		return 1;
	}
	if (numbers.size() >= 2) {
		int lastIdx = numbers.size() - 1;
		int secondLastIdx = lastIdx - 1;
		if (sortOption == 1) {
			std::swap(numbers[lastIdx], numbers[secondLastIdx]);
		}
		else {
			std::swap(numbers[secondLastIdx], numbers[lastIdx]);
		}
	}
	// Виведення відсортованої та зміненої послідовності
	std::cout << "Відсортована послідовність: ";
	for (const auto& num : numbers) {
		std::cout << num << " ";
	}
	return 0;
}