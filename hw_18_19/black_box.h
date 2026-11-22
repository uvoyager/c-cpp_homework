#ifndef CLIONPROJECTS_BLACK_BOX_H
#define CLIONPROJECTS_BLACK_BOX_H

#include <cstddef>
#include <queue>
#include <vector>

template <typename T = int>
class BlackBox {
private:
    std::queue<T> queue_;
    std::size_t k_ = 0;

    std::vector<T> drain_to_vector();
    void refill_from_vector(const std::vector<T>& items);

public:
    BlackBox() = default;

    void add(const T& value);
    T next_kth_min();
    void reset_counter() noexcept;
    std::size_t counter() const noexcept;
    std::size_t size() const noexcept;
    bool empty() const noexcept;
};
#endif //CLIONPROJECTS_BLACK_BOX_H
