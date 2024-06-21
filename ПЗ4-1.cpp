#include <iostream>
#include <vector>

template <typename T> class Iterator {
public:
    Iterator(std::vector<T>& container) : container_(container), index_(0) {}
    void next() { ++index_; }
    T& value() { return container_[index_]; }
    bool hasMore() { return index_ < container_.size(); }
private:
    std::vector<T>& container_;
    size_t index_;
};

int main() {
    std::vector<int> vec = { 6, 2, 1, 15, 5 };
    Iterator<int> it(vec);
    while (it.hasMore()) {
        std::cout << it.value() << " ";
        it.next();
    }
    return 0;
}
