#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

#include <iostream>
#include <list>
#include <fstream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
using namespace std;
using std::chrono::system_clock;

const size_t DEFAULT_SIZE = 1048576;

template<typename T>
class HashTable
{
    public:
        ///Constructor.  tableSz will determine the size of the hash table.
        ///If the argument is blank it will use the default.
        HashTable(size_t tableSz = DEFAULT_SIZE);
        ///Range constructor.  Insert data element of the InputIterator from first to last into the hash table.
        template<typename InputIterator> HashTable(InputIterator first, InputIterator last, size_t tableSz = DEFAULT_SIZE);
        ///Destructor
        ~HashTable(){delete[] hashTable;}
        ///HashTable<T>::iterator class.  Declared here, defined below.
        class iterator;
        ///returns the first non-empty element of the hash table
        iterator begin() const;
        ///returns an iterator pointing to the end element of the list in the last valid bucket of the table
        iterator end() const;
        ///Uses the hashing function to insert a data element into the table.  Do not allow duplicates.
        ///Currently only string is supported.
        ///Hash the given element to find the index, then push_back T into the list at that index.
        void insert(const T& item);
        ///Uses the hashing function to determine if an element exists in the table.
        ///Hash the given element, then call find on the list there.
		///Be sure to use a reference variable for the hashed list local variable, if you use one.
        iterator find(const T& item);

    private:
        list<T>* hashTable;
        size_t hash_it(const string&);  ///string hashi function, given below
        size_t tableSize;
};

template<typename T>
class HashTable<T>::iterator
{
    private:
        list<T>* bucket;  ///current bucket
        typename list<T>::iterator node;   ///current element within the current bucket
        list<T>* lastBucket;   ///last valid bucket.  Used as an endpoint for ++.
    public:
        iterator(list<T>* _bucket, list<T>* _lastBucket, typename list<T>::iterator _node)
        {
            bucket = _bucket;
            lastBucket = _lastBucket;
            node = _node;
        }
        iterator& operator++()
        {
			///increment the node.
            ++node;
			///If the node has reached the end of the bucket and the current bucket has not reached the last bucket
            if((node == bucket->end()) && (bucket != lastBucket)) {
			    ///then increment the bucket to either the first non-empty bucket or the last bucket and assign node to the first element there
                ++bucket;
                while((bucket->empty()) && (bucket != lastBucket)) {
                    ++bucket;
                }
                node = bucket->begin();
            }

            return *this;
        }
        const T& operator*() const { return *node; } ///return the data at the current node
        bool operator==(const iterator& b) const { return ((this->bucket == b.bucket) && (this->node == b.node)); } ///the buckets are equal and the nodes are equal
        bool operator!= (const iterator& b) const { return !((this->bucket == b.bucket) && (this->node == b.node)); } ///invert the above condition
};

template<typename T>
typename HashTable<T>::iterator HashTable<T>::begin() const
{
	///create a temporary pointer equal to hashTable
    list<T>* temp = hashTable;
	///increment it until a non-empty bucket is found or the last bucket is reached
    while((temp == nullptr) && (temp != &(hashTable[tableSize]))) {
        ++temp;
    }
	///construct an iterator using the pointer, the last valid bucket, and the first element of the pointer's list and return it.
    return iterator(temp, &(hashTable[tableSize]), temp->begin());
}

template<typename T>
typename HashTable<T>::iterator HashTable<T>::end() const
{
	///construct and return an iterator that points to the last valid bucket's end element.
    return iterator(&(hashTable[tableSize - 1]), &(hashTable[tableSize - 1]), hashTable[tableSize - 1].end());
}

template <typename T>
void HashTable<T>::insert(const T& item) {
    size_t hash = hash_it(item);
    if(std::find(hashTable[hash].begin(), hashTable[hash].end(), item) == hashTable[hash].end()) {
        hashTable[hash].push_back(item);
    }
}

template <typename T>
typename HashTable<T>::iterator HashTable<T>::find(const T& item) {
    size_t hash = hash_it(item);
    typename std::list<T>::iterator tempIt = std::find(hashTable[hash].begin(), hashTable[hash].end(), item);

    if(tempIt == (hashTable[hash]).end()) {
        cout << "It never makes it to here.\n";
        return end();
    }
    else {
        cout << "Only here.\n";
        return iterator(&hashTable[hash], &hashTable[tableSize - 1], tempIt);
    }
}


template<typename T>
HashTable<T>::HashTable(size_t tableSz)
{
    ///assign tableSize
    tableSize = tableSz;
	///allocate hashTable using new
    hashTable = new list<T>(tableSize);
}

template<typename T>
template<typename InputIterator>
HashTable<T>::HashTable(InputIterator first, InputIterator last, size_t tableSz)
{
    ///assign tableSize
    tableSize = tableSz;
	///allocate hashTable using new
    hashTable = new list<T>(tableSize);
	///insert the data at first while first does not equal last, then increment first.
    while(first != last) {
        insert(*first);
        ++first;
    }
}

///Given string hash function
template<typename T> size_t HashTable<T>::hash_it(const string& key)
{
    size_t hash = 0;
    for (size_t i=0, n = key.size(); i < n; i++)
        hash = (hash << 2) ^ key[i];
    return hash % tableSize;
}

template<typename T>
ostream& operator<<(ostream& os, const HashTable<T>& table)
{
	///iterate from table.begin() to table.end(), use your increment operator (prefix)
	///output the data at the iterator to os
	return os;
}

#endif // HASHTABLE_H_INCLUDED
