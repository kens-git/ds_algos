#pragma once

#include <initializer_list>

using std::initializer_list;

template <typename T>
class DArray {
    public:
        DArray();
        DArray(const initializer_list<T>& params);
        DArray(const int& capacity);
        ~DArray();
        
        DArray& operator=(const DArray& rhs);
        T& operator[](const int& index);
        
        int size() const;
        int capacity() const;
        int defaultCapacity() const;
        void push_back(const T& element);
        void pop_back();
        T& at(const int& index) const;
        void insert(const T& element, int index);
        void swap(int index1, int index2);
        void resize(int newSize);
        void clear();

    private:
        int mSize = 0;
        int mCapacity;
        const int mDefaultCapacity = 100;

        T* mElements;
};

template <typename T>
DArray<T>::DArray() {
    mSize = 0;
    mCapacity = mDefaultCapacity;
    mElements = new T[mDefaultCapacity];
}

template <typename T>
DArray<T>::DArray(const initializer_list<T>& params) {
    mSize = 0;
    mCapacity = params.size();
    mElements = new T[mCapacity];
    for (const T value : params) {
        push_back(value);
    }
}

template <typename T>
DArray<T>::DArray(const int& capacity) {
    mSize = 0;
    mCapacity = capacity;
    mElements = new T[mCapacity];
}

template <typename T>
DArray<T>::~DArray() {
    delete[] mElements;
}

template <typename T>
T& DArray<T>::operator[](const int& index) {
    return mElements[index];
}

template <typename T>
DArray<T>& DArray<T>::operator=(const DArray& rhs) {
    if (this == &rhs) {
        return *this;
    }
    
    delete[] mElements;
    mElements = nullptr;
    
    mSize = rhs.size();
    mCapacity = rhs.capacity();
    mDefaultCapacity = rhs.defaultCapacity();
    mElements = new T[mCapacity];
    for (int i = 0; i < mSize; i++) {
        mElements[i] = rhs.at(i);
    }
}

template <typename T>
int DArray<T>::size() const {
    return mSize;
}

template <typename T>
int DArray<T>::capacity() const {
    return mCapacity;
}

template <typename T>
int DArray<T>::defaultCapacity() const {
    return mDefaultCapacity;
}

template <typename T>
void DArray<T>::push_back(const T& element) {
    if (mSize > mCapacity) {
        resize(mCapacity * 2);
    }

    mElements[mSize] = element;
    mSize++;
}

template <typename T>
void DArray<T>::pop_back() {
    mSize--;
}

template <typename T>
T& DArray<T>::at(const int& index) const {
    return mElements[index];
}

template <typename T>
void DArray<T>::insert(const T& element, int index) {
    if (mSize == mCapacity) {
        resize(mCapacity * 2);
    }
    if (index < size()) {
        if (index < 0) {
            index = 0;
        }
        for (int i = size() - 1; i >= index; i--) {
            swap(i, i + 1);
        }
        mElements[index] = element;
    } else {
        mElements[size()] = element;
    }
    mSize++;
}

template <typename T>
void DArray<T>::swap(int index1, int index2) {
    T temp = mElements[index1];
    mElements[index1] = mElements[index2];
    mElements[index2] = temp;
}

template <typename T>
void DArray<T>::resize(int newSize) {
    if (newSize > mSize) {
        mCapacity = newSize;
        T* temp = new T[mCapacity];
        for (int i = 0; i < mSize; i++) {
            temp[i] = mElements[i];
        }
        delete[] mElements;
        mElements = temp;
    }
}

template <typename T>
void DArray<T>::clear() {
    delete[] mElements;
    mElements = nullptr;
    mSize = 0;
    mElements = new T[mDefaultCapacity];
}
