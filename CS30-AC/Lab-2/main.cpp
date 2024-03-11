#include <iostream>
#include <vector>

using namespace std;

class InvalidSize : public invalid_argument
{
    public:
        InvalidSize(const char* s) : invalid_argument(s)
        {}
};

class StackFull : public runtime_error
{
    public:
        StackFull(int value, const char* s) : _value(value), runtime_error(s)
        {}

        int getValue() const { return _value; }

    private:
        int _value;
};

class StackEmpty : public runtime_error
{
    public:
        StackEmpty(const char* s) : runtime_error(s)
        {}
};

class IntStack
{
    public:
	    // MaxSize should be an unsigned int, but for the sake of example...
	    IntStack(int MaxSize)
	    {
		    if (MaxSize < 0)
		    {
                throw InvalidSize("Cannot create a negative size stack");
		    }

		    data.resize(MaxSize);
		    cur_index = 0;
	    }

	    void push(int new_data)
	    {
		    if (cur_index == data.size())
		    {
                throw StackFull(new_data, "Push to full stack");
		    }
		    else
		    {
			    data.at(cur_index) = new_data;
			    cur_index++;
		    }
	    }

	    int pop()
	    {
		    if (cur_index == 0)
		    {
                throw StackEmpty("Pop from empty stack");
		    }
		    else
		    {
			    // pop off the int and return it
			    cur_index--;
			    return data.at(cur_index);
		    }
	    }

    private:
	    vector<int> data;
	    unsigned int cur_index;
};

int main()
{
    // Testing Constructor
	try
    {
        IntStack c_test(-10);

        c_test.push(3);
	    c_test.push(4);
	    c_test.pop();
	    c_test.pop();
    }
    catch(const InvalidSize& e)
    {
        std::cerr << e.what() << '\n';
    }
	

	// Testing push
	try
    {
        IntStack push_test(5);

	    for (unsigned int i = 0; i < 7; i++) {
		    push_test.push(i);
	    }
    }
    catch(const StackFull& e)
    {
        std::cerr << e.what() << ", value = " << e.getValue() << '\n';
    }
    

	// Testing pop
	try
    {
        IntStack pop_test(2);

	    pop_test.push(1);
	    pop_test.push(2);
	    pop_test.pop();
	    pop_test.pop();
	    pop_test.pop();
    }
    catch(const StackEmpty& e)
    {
        std::cerr << e.what() << '\n';
    }
    

	cout << "Completed!" << endl;


    return 0;
}