// ConsoleApplication27.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <array>
#include <algorithm>

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

	BufferItem<T>* getFirstFreePlace() const {
		return getFirstFreePlace;
	}

	void setNewItem(T&& _content) {
		if (isCircularBufferFull()) {
			return;
		}
		firstFreePlace->content = _content;
		if (firstFreePlace->next != firstItem) {
			firstFreePlace = firstFreePlace->next;
		}
		else {
			firstFreePlace = nullptr;
		}
		--freePlaces;
	}

	void deleteFirstItem() {
		if (freePlaces == BUFFER_SIZE) {
			return;
		}
		firstItem->content = 0;
		firstFreePlace = firstItem;
		firstItem = firstItem->next;
		++freePlaces;
	}

	size_t getFreePlces() const {
		return freePlaces;
	}

	bool isCircularBufferFull() const {
		return firstFreePlace == nullptr;
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
		freePlaces = BUFFER_SIZE;
	}
private:
	size_t freePlaces;
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
	circularBuffer.setNewItem(13);
	circularBuffer.setNewItem(w++);
	circularBuffer.setNewItem(w++);
	circularBuffer.setNewItem(w++);
	circularBuffer.setNewItem(w++);
	std::cout << circularBuffer.getFirstItem()->content << std::endl;
	std::cout << circularBuffer.getFirstItem()->next->content << std::endl;
	std::cout << circularBuffer.getFirstItem()->next->next->content << std::endl;
	std::cout << circularBuffer.getFirstItem()->next->next->next->content << std::endl;
	std::cout << circularBuffer.getFirstItem()->next->next->next->next->content << std::endl;
	std::cout << circularBuffer.getFirstItem()->next->next->next->next->next->content << std::endl;
	std::cout << circularBuffer.getFirstItem()->next->next->next->next->next->next->content << std::endl;
	circularBuffer.deleteFirstItem();
	circularBuffer.setNewItem(27);
	std::cout << "Circular Buffer!\n";
}

