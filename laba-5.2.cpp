#include <iostream>
#include <stdexcept>

// Шаблонный класс для представления комплексных чисел
template <typename T>
class Complex {
private:
    T real;    // Вещественная часть
    T imag;    // Мнимая часть

public:
    // Конструкторы
    Complex() : real(0), imag(0) {}
    Complex(T r, T i) : real(r), imag(i) {}

    // Методы доступа
    T getReal() const {
        return real;
    }
    T getImag() const {
        return imag;
    }
    void setReal(T r) {
        real = r;
    }
    void setImag(T i) {
        imag = i;
    }


    // Операции сложения, вычитания и умножения
    Complex<T> operator+(const Complex<T>& other) const {
        return Complex<T>(real + other.real, imag + other.imag);
    }

    Complex<T> operator-(const Complex<T>& other) const {
        return Complex<T>(real - other.real, imag - other.imag);
    }

    Complex<T> operator*(const Complex<T>& other) const {
        return Complex<T>(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Complex<T>& c) {
        os << "(" << c.real << ", " << c.imag << ")";
        return os;
    }
};

// Меню для демонстрации работы с классом Complex
void menu() {
    int choice;
    do {
        std::cout << "Меню:\n";
        std::cout << "1. Сложение комплексных чисел\n";
        std::cout << "2. Вычитание комплексных чисел\n";
        std::cout << "3. Умножение комплексных чисел\n";
        std::cout << "4. Выход\n";
        std::cout << "Выберите опцию: ";
        std::cin >> choice;

        if (choice == 4) break;

        double r1, i1, r2, i2;
        std::cout << "Введите вещественную и мнимую части первого числа: ";
        std::cin >> r1 >> i1;
        std::cout << "Введите вещественную и мнимую части второго числа: ";
        std::cin >> r2 >> i2;

        Complex<double> c1(r1, i1);
        Complex<double> c2(r2, i2);
        Complex<double> result;

        switch (choice) {
        case 1:
            result = c1 + c2;
            std::cout << "Результат сложения: " << result << "\n";
            break;
        case 2:
            result = c1 - c2;
            std::cout << "Результат вычитания: " << result << "\n";
            break;
        case 3:
            result = c1 * c2;
            std::cout << "Результат умножения: " << result << "\n";
            break;
        default:
            std::cout << "Неверный выбор\n";
        }
    } while (choice != 4);
}

int main() {
    setlocale(0, "ru");
    try {
        menu();
    }
    catch (const std::exception& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }
    return 0;
}
