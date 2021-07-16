#include <memory>

// persistent binary tree

template<class T>
class Tree {
private:
    struct Node
    {
        Node(std::shared_ptr<const Node> const & lft
            , T val
            , std::shared_ptr<const Node> const & rgt)
        : _lft(lft), _val(val), _rgt(rgt)
        {}

        std::shared_ptr<const Node> _lft;
        T _val;
        std::shared_ptr<const Node> _rgt;
    };

    std::shared_ptr<const Node> _root;

public:
Tree(Tree const & lft, T val, Tree const & rgt)
    : _root(std::make_shared<const Node>(lft._root, val, rgt._root))
{}

};
