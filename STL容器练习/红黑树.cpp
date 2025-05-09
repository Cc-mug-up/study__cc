#include <iostream>
#include <sstream>
#include <string>
enum class Color
{
    RED,
    BLACK
};
template <typename Key, typename Value>
class RedBlackTree
{
    class Node
    {
    public:
        Key key;
        Value value;
        Color color;
        Node *left;
        Node *right;
        Node *parent;
        Node(const Key &k, const Value &v, Color c, Node *p = nullptr)
            : key(k), value(v), color(c), left(nullptr), right(nullptr), parent(p) {}
        Node()
            : color(Color::BLACK), left(nullptr), right(nullptr), parent(nullptr) {}
    };

private:
    Node *root;
    size_t size;
    Node *Nil;
    Node *lookUp(Key key)
    {
        Node *cmpNode = root;
        while (cmpNode)
        {
            if (cmpNode->key < key)
            {
                cmpNode = cmpNode->right;
            }
            else if (cmpNode->key > key)
            {
                cmpNode = cmpNode->left;
            }
            else
            {
                return cmpNode;
            }
        }
        return cmpNode;
    }
    void rightRotate(Node *node)
    {
        Node *l_son = node->left;
        node->left = l_son->right;
        if (l_son->right != nullptr)
        {
            l_son->right->parent = node;
        }
        l_son->parent = node->parent;
        if (!node->parent)
        {
            root = l_son;
        }
        else if (node->parent->left == node)
        {
            node->parent->left = l_son;
        }
        else
        {
            node->parent->right = l_son;
        }
        l_son->right = node;
        node->parent = l_son;
    }
    void leftRotate(Node *node)
    {
        Node *r_son = node->right;
        node->right = r_son->left;
        if (r_son->left != nullptr)
        {
            r_son->left->parent = node;
        }
        r_son->parent = node->parent;
        if (node->parent == nullptr)
        {
            root = r_son;
        }
        else if (node->parent->left == node)
        {
            node->parent->left = r_son;
        }
        else
        {
            node->parent->right = r_son;
        }
        r_son->left = node;
        node->parent = r_son;
    }
    void insertFixup(Node *target)
    {
        while (target->parent && target->parent->color == Color::RED)
        {
            if (target->parent == target->parent->parent->left)
            {
                Node *uncle = target->parent->parent->right;
                if (uncle && uncle->color == Color::RED)
                {
                    uncle->color = Color::BLACK;
                    target->parent->color = Color::BLACK;
                    target->parent->parent->color = Color::RED;
                    target = target->parent->parent;
                }
                else
                {
                    if (target == target->parent->right)
                    {
                        target = target->parent;
                        leftRotate(target);
                    }
                    target->parent->color = Color::BLACK;
                    target->parent->parent->color = Color::RED;
                    rightRotate(target->parent->parent);
                }
            }
            else
            {
                Node *uncle = target->parent->left;
                if (uncle && uncle->color == Color::RED)
                {
                    uncle->color = Color::BLACK;
                    target->parent->color = Color::BLACK;
                    target->parent->parent->color = Color::RED;
                    target = target->parent->parent;
                }
                else
                {
                    if (target->parent->left == target)
                    {
                        target = target->parent;
                        rightRotate(target);
                    }
                    target->parent->parent->color = Color::RED;
                    target->parent->color = Color::BLACK;
                    leftRotate(target->parent->parent);
                }
            }
            if (target == root)
                break;
        }
        root->color = Color::BLACK;
    }
    void insertNode(const Key &key, const Value &value)
    {
        Node *newnode = new Node(key, value, Color::RED);
        Node *cmpnode = root;
        Node *parent = nullptr;
        while (cmpnode)
        {
            parent = cmpnode;
            if (cmpnode->key < newnode->key)
            {
                cmpnode = cmpnode->right;
            }
            else if (cmpnode->key > newnode->key)
            {
                cmpnode = cmpnode->left;
            }
            else
            {
                delete newnode;
                return;
            }
        }
        ++size;
        newnode->parent = parent;
        if (parent == nullptr)
        {
            root = newnode;
        }
        else if (newnode->key < parent->key)
        {
            parent->left = newnode;
        }
        else
        {
            parent->right = newnode;
        }
        insertFixup(newnode);
    }
    void inorderTraversal(Node *node) const
    {
        if (node == nullptr)
            return;
        inorderTraversal(node->left);
        std::cout << node->key << " ";
        std::cout << node->value << " ";
        inorderTraversal(node->right);
        return;
    }

public:
    RedBlackTree() : root(nullptr), size(0), Nil(new Node())
    {
        Nil->color = Color::BLACK;
    }
    void insert(const Key &key, const Value &value)
    {
        insertNode(key, value);
    }
    void print()
    {
        inorderTraversal(root);
        std::cout << std::endl;
    }
};
int main()
{
    RedBlackTree<int, int> rbt;
    rbt.insert(1, 1);
    rbt.insert(2, 3);
    rbt.print();
    return 0;
}
