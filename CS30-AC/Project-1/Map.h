#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>

using KeyType   = std::string;
using ValueType = double;


class Map
{
    private:
        struct Node
        {
            KeyType   key;
            ValueType val;
            Node*     left;
            Node*     right;
        };

        Node* root;

        void destroySubTree(Node*& nodePtr);
        // For use with ~Map()

        int nodeCount(Node* nodePtr) const;
        // For use with size()

        void insertNode(Node*& nodePtr, Node*& newNode, bool& success);
        // For use with insert()

        void deleteNode(const KeyType& key, Node*& nodePtr);
        void makeDeletion(Node*& nodePtr);
        // For use with erase()

        void traverseNodes(Node* nodePtr, KeyType keys[], ValueType vals[], int& currI) const;
        // For use with get();

    public:
        Map();                                  // Create an empty map (i.e., one with no key/value pairs)

        Map(const Map& rhs);                    // Copy constructor

        ~Map();                                 // Destroy map, deallocate all dynamically allocated objects

        const Map& operator=(const Map& rhs);   // Assignment operator

        bool empty() const;                     // Return true if the map is empty, otherwise false.

        int size() const;                       // Return the number of key/value pairs in the map.

        bool insert(const KeyType& key, const ValueType& value);
        // If key is not equal to any key currently in the map, and if the
        // key/value pair can be added to the map, then do so and return true.
        // Otherwise, make no change to the map and return false (indicating
        // that either the key is already in the map).

        bool update(const KeyType& key, const ValueType& value);
        // If key is equal to a key currently in the map, then make that key no
        // longer map to the value it currently maps to, but instead map to
        // the value of the second parameter; return true in this case.
        // Otherwise, make no change to the map and return false.

        bool insertOrUpdate(const KeyType& key, const ValueType& value);
        // If key is equal to a key currently in the map, then make that key no
        // longer map to the value it currently maps to, but instead map to
        // the value of the second parameter; return true in this case.
        // If key is not equal to any key currently in the map then add it and 
        // return true. In fact this function always returns true.

        bool erase(const KeyType& key);
        // If key is equal to a key currently in the map, remove the key/value
        // pair with that key from the map and return true.  Otherwise, make
        // no change to the map and return false.

        bool contains(const KeyType& key) const;
        // Return true if key is equal to a key currently in the map, otherwise
        // false.

        bool get(const KeyType& key, ValueType& value) const;
        // If key is equal to a key currently in the map, set value to the
        // value in the map that that key maps to, and return true.  Otherwise,
        // make no change to the value parameter of this function and return
        // false.

        bool get(int i, KeyType& key, ValueType& value) const;
        // If 0 <= i < size(), copy into the key and value parameters the
        // key and value of one of the key/value pairs in the map and return
        // true.  Otherwise, leave the key and value parameters unchanged and
        // return false.  (See below for details about this function.)

        void swap(Map& other);
        // Exchange the contents of this map with the other one.

};

bool combine(const Map& m1, const Map& m2, Map& result);
void subtract(const Map& m1, const Map& m2, Map& result);

#endif