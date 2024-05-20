#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
using namespace std;
// Шаблонный класс queue, использующий list для хранения элементов
template<typename T>
class Queue {
private:
    list<T> data;  // Список для хранения элементов очереди

public:
    // Конструктор по умолчанию
    Queue() {}

    // Метод для добавления элемента в конец очереди
    void enqueue(const T& element) {
        data.push_back(element);
    }

    // Метод для удаления элемента из начала очереди
    void dequeue() {
        if (data.empty()) {
            throw out_of_range("Невозможно удалить элемент из пустой очереди.");
        }
        data.pop_front();//удаляет первый элемент очереди
    }

    // Метод для доступа к первому элементу в очереди (неконстантная версия)
    T& front() {
        if (data.empty()) {
            throw out_of_range("Невозможно получить доступ к элементу из пустой очереди.");
        }
        return data.front();
    }

    // Метод для доступа к первому элементу в очереди (константная версия)
    const T& front() const {
        if (data.empty()) {
            throw out_of_range("Невозможно получить доступ к элементу из пустой очереди.");
        }
        return data.front();
    }

    // Метод для проверки, пуста ли очередь
    bool isEmpty() const {
        return data.empty();
    }

    // Метод для получения текущего размера очереди
    size_t size() const {
        return data.size();
    }
};

int main() {
    setlocale(0, "ru");
    Queue<int> intQueue;
    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);
    cout << "Первый элемент intQueue: " << intQueue.front() << endl;
    intQueue.dequeue();
    cout << "Первый элемент intQueue после удаления: " << intQueue.front() << endl;

    // Инстанцирование шаблона для типа double
    Queue<double> doubleQueue;
    doubleQueue.enqueue(1.1);
    doubleQueue.enqueue(2.2);
    doubleQueue.enqueue(3.3);
    cout << "Первый элемент doubleQueue: " << doubleQueue.front() << endl;
    doubleQueue.dequeue();
    cout << "Первый элемент doubleQueue после удаления: " << doubleQueue.front() << endl;

    // Инстанцирование шаблона для типа std::string
    Queue<string> stringQueue;
    stringQueue.enqueue("Привет");
    stringQueue.enqueue("Мир");
    cout << "Первый элемент stringQueue: " << stringQueue.front() << endl;
    stringQueue.dequeue();
    cout << "Первый элемент stringQueue после удаления: " << stringQueue.front() << endl;

    return 0;
}

