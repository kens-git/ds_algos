#pragma once

#include <initializer_list>

using std::initializer_list;

template <typename T>
class DArray {
    public:
        DArray();
        DArray(const initializer_list<T>& params);
        DArray(const int& capacity);
        DArray(const DArray<T>& src);
        virtual ~DArray();
        
        // TODO: figure out what leaving off the '<T>' does, because
        // it works either way
        DArray<T>& operator=(const DArray<T>& rhs);
        T& operator[](const unsigned int& index) const;
        
        int size() const;
        T& back() const;
        int capacity() const;
        int defaultCapacity() const;
        void push_back(const T& element);
        void push_back(const DArray<T>& arr);
        void pop_back();
        T& at(const unsigned int& index) const;
        void insert(const T& element, unsigned int index);
        void remove(unsigned int index);
        void swap(unsigned int index1, unsigned int index2);
        void resize(unsigned int newSize);
        void clear();
        DArray<T> sub(unsigned int start, unsigned int end); // returns an inclusive subset of the array

    private:
        int mSize = 0;
        int mCapacity;
        const int mDefaultCapacity = 100;

        T* mElements = nullptr;
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
    mElements = nullptr;
}

template <typename T>
DArray<T>::DArray(const DArray<T>& src) {
    if (mElements != nullptr) {
        delete mElements;
        mElements = nullptr;
    }

    mSize = src.size();
    mCapacity = src.capacity();

    mElements = new T[mCapacity];
    for (unsigned int i = 0; i < mSize; i++) {
        mElements[i] = src[i];
    }
}

template <typename T>
T& DArray<T>::operator[](const unsigned int& index) const {
    return mElements[index];
}

template <typename T>
DArray<T>& DArray<T>::operator=(const DArray<T>& rhs) {
    if (this == &rhs) {
        return *this;
    }
    
    delete[] mElements;
    mElements = nullptr;
    
    mSize = rhs.size();
    mCapacity = rhs.capacity();
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
T& DArray<T>::back() const {
    return mElements[mSize - 1];
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
    if (mSize >= mCapacity) {
        resize(mCapacity * 2);
    }

    mElements[mSize] = element;
    mSize++;
}

template <typename T>
void DArray<T>::push_back(const DArray<T>& arr) {
    for (unsigned int i = 0; i < arr.size(); i++) {
        push_back(arr[i]);
    }
}

template <typename T>
void DArray<T>::pop_back() {
    mSize--;
}

template <typename T>
T& DArray<T>::at(const unsigned int& index) const {
    return mElements[index];
}

template <typename T>
void DArray<T>::insert(const T& element, unsigned int index) {
    if (mSize == mCapacity) {
        resize(mCapacity * 2);
    }
    if (index < size()) {
        if (index < 0) {
            index = 0;
        }
        for (unsigned int i = size() - 1; i >= index; i--) {
            swap(i, i + 1);
        }
        mElements[index] = element;
    } else {
        mElements[size()] = element;
    }
    mSize++;
}

template <typename T>
void DArray<T>::remove(unsigned int index) {
    if (index < mSize - 1) {
        for (unsigned int i = index; i < mSize - 1; i++) {
            mElements[i] = mElements[i + 1];
        }
    }

    mSize--;
}

template <typename T>
void DArray<T>::swap(unsigned int index1, unsigned int index2) {
    T temp = mElements[index1];
    mElements[index1] = mElements[index2];
    mElements[index2] = temp;
}

template <typename T>
void DArray<T>::resize(unsigned int newSize) {
    if (newSize > mSize) {
        mCapacity = newSize;
        T* temp = new T[mCapacity];
        for (unsigned int i = 0; i < mSize; i++) {
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

template <typename T>
DArray<T> DArray<T>::sub(unsigned int start, unsigned int end) {
    DArray<T> temp;

    for (unsigned int i = start; i < end + 1; i++) {
        temp.push_back(mElements[i]);
    }

    return temp;
}
