#include <iostream>

int main() {

    char repeat;

    do {
        int n;
        std::cout << "Введіть кількість членів послідовності: ";
        std::cin >> n;

        int prev, curr;
        bool increasing = true, decreasing = true;
        int m = 1;

        std::cout << "Введіть значення для 1-го члена послідовності: ";
        std::cin >> prev;

        for (int i = 2; i <= n; ++i) {
            std::cout << "Введіть значення для " << i << "-го члена послідовності: ";
            std::cin >> curr;

            if (increasing && curr < prev) {
                increasing = false;
                m = i - 1; // Оновлюємо m при першому виявленні спадання
            }

            if (decreasing && curr > prev) {
                decreasing = false;
                m = i - 1; // Оновлюємо m при першому виявленні зростання
            }

            prev = curr;
        }

        if (increasing || decreasing) {
            std::cout << "m не існує" << std::endl;
        }
        else {
            std::cout << "Значення m: " << m << std::endl;
        }

        std::cout << "Бажаєте повторити? (y/n): ";
        std::cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
