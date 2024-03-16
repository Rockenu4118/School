#include <iostream>

#include "./Map.h"


Map::Map() : root(nullptr)
{}

Map::Map(const Map& rhs) : root(nullptr)
{
    KeyType   key;
    ValueType val;

    // Get every key/val pair from rhs map and insert into newly created map
    for (int i = 0 ; i < rhs.size() ; i++)
    {
        rhs.get(i, key, val);
        insert(key, val);
    }
}

Map::~Map()
{
    destroySubTree(root);
}

const Map& Map::operator=(const Map& rhs)
{
    // Destroy current map data
    destroySubTree(root);

    KeyType   key;
    ValueType val;

    // Get every key/val pair from rhs map and insert into newly created map
    for (int i = 0 ; i < rhs.size() ; i++)
    {
        rhs.get(i, key, val);
        insert(key, val);
    }

    return *this;
}

bool Map::empty() const
{
    // If root is null, map is empty
    return root == nullptr ? true : false;
}

int Map::size() const
{
    return nodeCount(root);   
}

bool Map::insert(const KeyType& key, const ValueType& value)
{
    // Create a new node and assign it initial values
    Node* newNode = new Node;
    newNode->left  = nullptr;
    newNode->right = nullptr;
    newNode->key   = key;
    newNode->val   = value;

    bool success = true;

    insertNode(root, newNode, success);

    // If insertion fails, delete node
    if (!success)
        delete newNode;

    return success;
}

bool Map::update(const KeyType& key, const ValueType& value)
{
    Node* nodePtr = root;

    // Traverse nodes to find the one with the given key.
    while (nodePtr != nullptr)
    {
        // If found, update with given value and return true.
        if (nodePtr->key == key)
        {
            nodePtr->val = value;
            return true;
        }
        else if (key < nodePtr->key)
        {
            nodePtr = nodePtr->left;
        }
        else
        {
            nodePtr = nodePtr->right;
        }
    }

    // If not found, return false
    return false;
}

bool Map::insertOrUpdate(const KeyType& key, const ValueType& value)
{
    if (contains(key))
        return update(key, value);
    else
        return insert(key, value);
}

bool Map::erase(const KeyType& key)
{
    if (contains(key))
    {
        deleteNode(key, root);
        return true;
    }
    
    return false;
}

bool Map::contains(const KeyType& key) const
{
    Node* nodePtr = root;

    // Traverse nodes until finding one with the same key
    while (nodePtr != nullptr)
    {
        // Return true if found
        if (key == nodePtr->key)
            return true;
        else if (key < nodePtr->key)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
    // Return false if not
    return false;
}

bool Map::get(const KeyType& key, ValueType& value) const
{
    Node* nodePtr = root;

    // Traverse nodes until finding one with the given key
    while (nodePtr != nullptr)
    {
        // If found, set referenced value equal to value in node
        // and return true
        if (nodePtr->key == key)
        {
            value = nodePtr->val;
            return true;
        }
        else if (key < nodePtr->key)
        {
            nodePtr = nodePtr->left;
        }
        else
        {
            nodePtr = nodePtr->right;
        }
    }

    // If not found, return false
    return false;
}

bool Map::get(int i, KeyType& key, ValueType& value) const
{
    // Verify i would fit as an index for the current map
    if (!((0 <= i) && (i < size())))
        return false;

    // Init arrays to hold all keys and vals within map in order
    KeyType keys[size()];
    ValueType vals[size()];

    int currI = 0;

    // Populate arrays with all vals in map
    traverseNodes(root, keys, vals, currI);

    // Set reference vals equal to vals of the desired index
    key   = keys[i];
    value = vals[i];

    return true;
}

void Map::swap(Map& other)
{
    Map temp;
    temp = other;
    other = *this;
    *this = temp;
}

// Private member functions
void Map::destroySubTree(Node*& nodePtr)
{
    if (nodePtr != nullptr)
    {
        destroySubTree(nodePtr->left);
        destroySubTree(nodePtr->right);
        
        delete nodePtr;
        nodePtr = nullptr;
    }
}

int Map::nodeCount(Node* nodePtr) const
{
    if (nodePtr == nullptr)
        return 0;

    int leftCount  = nodeCount(nodePtr->left);
    int rightCount = nodeCount(nodePtr->right);

    return (1 + leftCount + rightCount);
}

void Map::insertNode(Node*& nodePtr, Node*& newNode, bool& success)
{
    if (nodePtr == nullptr)
        nodePtr = newNode;
    else if (newNode->key < nodePtr->key)
        insertNode(nodePtr->left, newNode, success);
    else if (newNode->key > nodePtr->key)
        insertNode(nodePtr->right, newNode, success);
    else
        success = false;
}

void Map::deleteNode(const KeyType& key, Node*& nodePtr)
{
    // Traverse nodes until finding the one with desired key
    if (nodePtr == nullptr)
        return;
    else if (key < nodePtr->key)
        deleteNode(key, nodePtr->left);
    else if (key > nodePtr->key)
        deleteNode(key, nodePtr->right);
    else
        // When found, execute deletion of node
        makeDeletion(nodePtr);
}

void Map::makeDeletion(Node*& nodePtr)
{
    Node* temp = nullptr;

    if (nodePtr == nullptr)
        return;
    // If right node is null, set self ptr equal to the left ptr
    else if (nodePtr->right == nullptr)
    {
        temp = nodePtr;
        nodePtr = nodePtr->left;
        delete temp;
    }
    // If left node is null, set self ptr equal to the right ptr
    else if (nodePtr->left == nullptr)
    {
        temp = nodePtr;
        nodePtr = nodePtr->right;
        delete temp;
    }
    else
    {
        temp = nodePtr->right;

        // Find furthest down left ptr of the right branch
        while (temp->left)
        {
            temp = temp->left;
        }

        // Attach left branch to the furthest down left ptr of the right branch
        temp->left = nodePtr->left;
        temp = nodePtr;
        // Self self ptr to the right branch
        nodePtr = nodePtr->right;
        // Delete node
        delete temp;
    }
}

void Map::traverseNodes(Node* nodePtr, KeyType keys[], ValueType vals[], int& currI) const
{
    if (nodePtr != nullptr)
    {
        traverseNodes(nodePtr->left, keys, vals, currI);
        // Populate key/val arrays with node info
        keys[currI] = nodePtr->key;
        vals[currI] = nodePtr->val;
        // Increment index
        currI++;
        traverseNodes(nodePtr->right, keys, vals, currI);
    }
}

// Non-Member functions
bool combine(const Map& m1, const Map& m2, Map& result)
{
    // Create blank map
    Map res;

    // Status of duplicate, non-equal keys
    bool status = true;
    
    // Set blank map to m1
    res = m1;

    // Iterate through all m2 key/val pairs
    for (int i = 0 ; i < m2.size() ; i++)
    {
        KeyType   key;
        ValueType val;

        m2.get(i, key, val);

        // If resulting map contains key from m2 already,
        // verify that values are the same
        if (res.contains(key))
        {
            ValueType val2;

            res.get(key, val2);
            
            // If values are not the same erase that key/val pair and move on
            if (val != val2)
            {
                status = false;
                res.erase(key);
                continue;
            }
        }

        // Insert key/val pair if all else checks out
        res.insert(key, val);
    }

    // Assign map to the referenced map
    result = res;

    return status;
}

void subtract(const Map& m1, const Map& m2, Map& result)
{
    // Create bank map
    Map res;

    // Set blank map to m1
    res = m1;

    // Iterate through m2
    for (int i = 0 ; i < m2.size() ; i++)
    {
        KeyType key;
        ValueType val;

        m2.get(i, key, val);

        // Erase every key from m2
        res.erase(key);
    }

    // Assign map to the referenced map
    result = res;
}
