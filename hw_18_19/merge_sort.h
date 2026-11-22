#ifndef CLIONPROJECTS_MERGE_SORT_H
#define CLIONPROJECTS_MERGE_SORT_H

#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <utility>

template <typename T>
class Array {
private:
    std::size_t size_;
    T* data_;
    void merge_range(std::size_t left, std::size_t mid, std::size_t right, T* buffer) {
        std::size_t i = left;
        std::size_t j = mid + 1;
        std::size_t k = left;
        while (i <= mid && j <= right) {
            if (data_[i] <= data_[j]) {
                buffer[k++] = std::move(data_[i++]);
            } else {
                buffer[k++] = std::move(data_[j++]);
            }
        }
        while (i <= mid) {
            buffer[k++] = std::move(data_[i++]);
        }
        while (j <= right) {
            buffer[k++] = std::move(data_[j++]);
        }
        for (std::size_t idx = left; idx <= right; ++idx) {
            data_[idx] = std::move(buffer[idx]);
        }
    }

    void merge_sort_rec(std::size_t left, std::size_t right, T* buffer) {
        if (left >= right) {
            return;
        }
        std::size_t mid = left + (right - left) / 2;
        merge_sort_rec(left, mid, buffer);
        merge_sort_rec(mid + 1, right, buffer);
        merge_range(left, mid, right, buffer);
    }

public:
    explicit Array(std::size_t size = 0)
        : size_(size), data_(size > 0 ? new T[size]() : nullptr) {}
    Array(const Array& other)
        : size_(other.size_), data_(other.size_ > 0 ? new T[other.size_] : nullptr) {
        for (std::size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    Array& operator=(const Array& other) {
        if (this == &other) {
            return *this;
        }
        T* new_data = other.size_ > 0 ? new T[other.size_] : nullptr;
        for (std::size_t i = 0; i < other.size_; ++i) {
            new_data[i] = other.data_[i];
        }
        delete[] data_;
        data_ = new_data;
        size_ = other.size_;
        return *this;
    }
    Array(Array&& other) noexcept
        : size_(other.size_), data_(other.data_) {
        other.size_ = 0;
        other.data_ = nullptr;
    }
    Array& operator=(Array&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        delete[] data_;
        size_ = other.size_;
        data_ = other.data_;
        other.size_ = 0;
        other.data_ = nullptr;
        return *this;
    }
    ~Array() {
        delete[] data_;
    }
    std::size_t size() const noexcept {
        return size_;
    }
    T& operator[](std::size_t index) {
        return data_[index];
    }
    const T& operator[](std::size_t index) const {
        return data_[index];
    }
    T& at(std::size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }
    const T& at(std::size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }
    void merge_sort() {
        if (size_ <= 1) {
            return;
        }
        T* buffer = new T[size_];
        try {
            merge_sort_rec(0, size_ - 1, buffer);
        } catch (...) {
            delete[] buffer;
            throw;
        }
        delete[] buffer;
    }
    void print(std::ostream& os = std::cout) const {
        os << "[";
        for (std::size_t i = 0; i < size_; ++i) {
            os << data_[i];
            if (i + 1 < size_) {
                os << ", ";
            }
        }
        os << "]\n";
    }
};

#endif //CLIONPROJECTS_MERGE_SORT_H
