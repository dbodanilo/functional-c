#include <memory>

// List a = Empty | Cons a (List a)
// [a] = [] | (a : [a])

template <class T>
class List
{
    struct Item
    {
        Item(T v, std::shared_ptr<const Item> const & tail)
            : _val(v), _next(tail) {}
        T _val;
        std::shared_ptr<const Item> _next;
    };

public:
    List() {}
    List(T val, List const & tail) 
        : _head(std::make_shared<Item>(val, tail._head)) {}

    bool isEmpty() const { return !_head; }

    T front() const
    {
        assert(!isEmpty());
        return _head->_val;
    }
    List pop_front() const
    {
        assert(!isEmpty());
        return List(_head->_next);
    }

    List push_front(T v) const {
        return List(v, *this);
    }

private:
    explicit List (Item const * items) : _head(items) {}

    // may be null
    std::shared_ptr<const Item> _head;
};
