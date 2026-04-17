#include <iostream>
#include <algorithm>

class Vector {
private:
    int* data{nullptr};
    unsigned int size{0};
    int capacity{0};

public:
    //Default Constructor
    Vector() : data(nullptr), size(0), capacity(0) {}

    //Parameterized Constructor
    Vector(int initial_capacity) : size(0), capacity(initial_capacity) {
        if (capacity > 0) {
            data = new int[capacity];
        }
    }

    //Copy Constructor
    Vector(const Vector& other) {
        size = other.size;
        capacity = other.capacity;
        if (other.data) {
            data = new int[capacity];
            for (unsigned int i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        } else {
            data = nullptr;
        }
    }

    //Copy Assignment Operator
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data;

            size = other.size;
            capacity = other.capacity;
            if (other.data) {
                data = new int[capacity];
                std::copy(other.data, other.data + size, data);
            } else {
                data = nullptr;
            }
        }
        return *this;
    }

    //Move Constructor
    Vector(Vector&& other) noexcept {
        data = other.data;
        size = other.size;
        capacity = other.capacity;

        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    //Move Assignment Operator
    Vector& operator=(Vector&& other) noexcept {
        if (this != &other) {
            delete[] data;

            data = other.data;
            size = other.size;
            capacity = other.capacity;

            other.data = nullptr;
            other.size = 0;
            other.capacity = 0;
        }
        return *this;
    }

    //Destructor
    ~Vector() {
        delete[] data;
    }

    void push_back(int value) {
        if (size == capacity) {
            //Double the capacity
            int newCap = (capacity == 0) ? 1 : capacity * 2;
            int* newData = new int[newCap];

            // Move old data to new location
            for (unsigned int i = 0; i < size; ++i) {
                newData[i] = data[i];
            }

            delete[] data; // Free the old block
            data = newData;
            capacity = newCap;
        }
        data[size++] = value;
    }

    // Access operator
    int& operator[](unsigned int index) {
        return data[index];
    }

    unsigned int getSize() const { return size; }
};

int main() {
    Vector v1(2);
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    std::cout << "v1 size: " << v1.getSize() << " \t Element 0: " << v1[0] << std::endl;

    // Test Copy
    Vector v2 = v1;
    std::cout << "v2 (copy) Element 0: " << v2[0] << std::endl;

    // Test Move
    Vector v3 = std::move(v1);
    std::cout << "v3 (moved) Element 0: " << v3[0] << std::endl;

    return 0;
}