#ifndef ARRAYLIST_H
#define ARRAYLIST_H

class ArrayList
{
    public:
        // Constructor
        ArrayList() = default;

        // Utility
        void insert(int num);
        void remove();
        bool isFull();
        int  find(int index);
        int  getLength();
        void makeEmpty();
        void showValues();

    private:
        int _nums[5];
        int _elements = 0;
};

#endif