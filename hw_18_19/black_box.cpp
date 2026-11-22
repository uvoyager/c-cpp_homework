#include "black_box.h"

#include <algorithm>
#include <stdexcept>

template <typename T>
std::vector<T> BlackBox<T>::drain_to_vector() {
    std::vector<T> items;
    items.reserve(queue_.size());
    while (!queue_.empty()) {
        items.push_back(queue_.front());
        queue_.pop();
    }
    return items;
}
template <typename T>
void BlackBox<T>::refill_from_vector(const std::vector<T>& items) {
    for (const T& item : items) {
        queue_.push(item);
    }
}
template <typename T>
void BlackBox<T>::add(const T& value) {
    queue_.push(value);
}
template <typename T>
T BlackBox<T>::next_kth_min() {
    ++k_;
    if (k_ > queue_.size()) {
        throw std::out_of_range("k exceeds the number of elements in the BlackBox");
    }
    std::vector<T> items = drain_to_vector();
    std::sort(items.begin(), items.end());
    T result = items[k_ - 1];
    refill_from_vector(items);
    return result;
}
template <typename T>
void BlackBox<T>::reset_counter() noexcept {
    k_ = 0;
}
template <typename T>
std::size_t BlackBox<T>::counter() const noexcept {
    return k_;
}
template <typename T>
std::size_t BlackBox<T>::size() const noexcept {
    return queue_.size();
}
template <typename T>
bool BlackBox<T>::empty() const noexcept {
    return queue_.empty();
}
template class BlackBox<int>;
