#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <sstream>
#include <string>
template <typename Key, typename Value, typename Hash = std::hash<Key>>
class HashTable
{
    class HashNode
    {
    public:
        Key key;
        Value value;
        explicit HashNode(const Key &k) : key(k), value() {}
        HashNode(const Key &k, const Value &v) : key(k), value(v) {}
        // bool operator==(const HashNode &other) const { return key == other.key; }
        bool operator==(const Key &k) const { return key == k; }
        bool operator>=(const Key &k) const { return key >= k; }
        bool operator<=(const Key &k) const { return key <= k; }
        bool operator>(const Key &k) const { return key > k; }
        bool operator<(const Key &k) const { return key < k; }
        bool operator!=(const Key &k) const { return key != k; }
        void print()
        {
            std::cout << key << " " << value << std::endl;
        }
    };

private:
    using Bucket = std::list<HashNode>;
    size_t tableSize;
    size_t numElements;
    Hash hashFunction;
    std::vector<Bucket> buckets;
    float maxLoadFactor = 0.75;
    size_t hash(const Key &key)
    {
        return hashFunction(key) % tableSize;
    }
    void rehash(size_t newSize)
    {
        std::vector<Bucket> newbuckets(newSize);
        for (Bucket &bucket : buckets)
        {
            for (HashNode &hashNode : bucket)
            {
                size_t index = hashFunction(hashNode.key) % newSize;
                newbuckets[index].push_back(hashNode);
            }
        }
        buckets = std::move(newbuckets);
        tableSize = newSize;
    }

public:
    HashTable(size_t size = 10, const Hash &hashFuc = Hash())
        : tableSize(size), numElements(0), buckets(size), hashFunction(hashFuc) {}
    void insert(const Key &key, const Value &value)
    {
        if (numElements + 1 > maxLoadFactor * tableSize)
        {
            if (tableSize == 0)
                tableSize = 1;
            rehash(2 * tableSize);
        }
        size_t index = hash(key);
        std::list<HashNode> &bucket = buckets[index];
        if (std::find(bucket.begin(), bucket.end(), key) == bucket.end())
        {
            bucket.push_back(HashNode(key, value));
            ++numElements;
        }
    }
    void erase(const Key &key)
    {
        int index = hash(key);
        std::list<HashNode> &bucket = buckets[index];
        auto it = std::find(bucket.begin(), bucket.end(), key);
        if (it != bucket.end())
        {
            bucket.erase(it);
            --numElements;
        }
    }
    Value *find(const Key &key)
    {
        int index = hash(key);
        std::list<HashNode> &bucket = buckets[index];
        auto it = std::find(bucket.begin(), bucket.end(), key);
        if (it != bucket.end())
        {
            return &it->value;
        }
        return nullptr;
    }
    void print()
    {
        for (Bucket &bucket : buckets)
        {
            for (HashNode &hashNode : bucket)
            {
                std::cout << hashNode.key << " " << hashNode.value << std::endl;
            }
        }
    }
    size_t size()
    {
        return numElements;
    }
    void clear()
    {
        this->buckets.clear();
        this->numElements = 0;
        this->tableSize = 0;
    }
};
int main()
{
    HashTable<int, int> hash;
    hash.insert(1, 1);
    hash.insert(3, 2);
    hash.insert(5, 5);
    hash.print();
    hash.erase(5);
    std::cout << *hash.find(3) << std::endl;
    hash.print();
    return 0;
}
