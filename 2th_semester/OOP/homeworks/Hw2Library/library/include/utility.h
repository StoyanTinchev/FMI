#ifndef UTILITY_H
#define UTILITY_H

template<typename T>
void resize(T **&arr, int &currentSize, int &capacity) {
    capacity *= 2;
    T **temp = new T *[capacity];
    for (int i = 0; i < currentSize; ++i) {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
}

template<typename T>
void swap(T *&a, T *&b) {
    T *temp = a;
    a = b;
    b = temp;
}

template<typename T, typename Compare>
void selectionSort(T **arr, int count, Compare compare) {
    for (int i = 0; i < count - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < count; ++j) {
            if (compare(arr[j], arr[minIndex])) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}


#endif // UTILITY_H
