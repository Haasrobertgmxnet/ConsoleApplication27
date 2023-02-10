// ConsoleApplication27.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <array>

const size_t BUFFER_SIZE = 5;

template <typename T>
struct BufferItem {
    T content;
    BufferItem<T>* next;
};

template <typename T>
struct CircularBuffer {
    BufferItem<T>* getFirstItem() const {
        return firstItem;
    }
    BufferItem<T>* getFirstFreePlace()const {
        return getFirstFreePlace;
    }
    void setNewItem(const T& _content) {
        if (isCircularBufferFull()) {
            return;
        }
        firstFreePlace->content = _content;
        incrementFirstFreePlace();
    }
    void deleteFirstItem() {
        incrementFirstItem();
    }
    void incrementFirstItem() {
        firstItem = firstItem->next;
    }
    void incrementFirstFreePlace() {
        if (firstFreePlace->next != firstItem) {
            firstFreePlace = firstFreePlace->next;
        }
    }
    bool isCircularBufferFull() const {
        return firstFreePlace->next == firstItem;
    }
    CircularBuffer() {
        for (size_t j = 0; j < BUFFER_SIZE; ++j) {
            BufferItem<T>* item = &Items[j];
            try {
                item->content = T();
            }
            catch (std::exception &ex) {
                //
            }
            item->next = &Items[(1 + j) % BUFFER_SIZE];
        }
        firstItem = &Items[0];
        firstFreePlace = firstItem;
    }
private:
    BufferItem<T>* firstItem;
    BufferItem<T>* firstFreePlace;
    std::array<BufferItem<T>, BUFFER_SIZE> Items;
};

int main()
{
    CircularBuffer<int> circularBuffer;
    int w = 42;
    circularBuffer.setNewItem(w++);
    circularBuffer.setNewItem(w++);
    std::cout << "Circular Buffer!\n";
}

