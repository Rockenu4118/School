#include <iostream>

using namespace std;


class null_ptr_exception : public logic_error
{
    public:
        null_ptr_exception(const char* s) : logic_error(s)
        {}
};

template <typename T>
class smart_ptr {
    public:
        smart_ptr() noexcept : ptr_(nullptr), ref_(nullptr) {}
        // Create a smart_ptr that is initialized to nullptr. The reference count
        // should be initialized to nullptr.

        explicit smart_ptr(T* &raw_ptr)
        {
            ptr_ = raw_ptr;
            ref_ = new int(1);
        }
        // Create a smart_ptr that is initialized to raw_ptr. The reference count
        // should be one. No change is made to raw_ptr.
      
        explicit smart_ptr(T* &&raw_ptr)
        {
            ptr_ = raw_ptr;

            try
            {
                ref_ = new int(1);
            }
            catch(const std::exception& e)
            {
                delete ptr_;
                std::cerr << e.what() << '\n';
                throw;
            }
        }
        // Create a smart_ptr that is initialized to raw_ptr. The reference count
        // should be one. If the constructor fails raw_ptr is deleted.	

        smart_ptr(const smart_ptr& rhs) noexcept
        {
            ptr_ = rhs.ptr_;
            ref_ = rhs.ref_;
            
            *ref_ = *ref_ + 1;
        }
        // Copy construct a pointer from rhs. The reference count should be
        // incremented by one.

        smart_ptr(smart_ptr&& rhs) noexcept
        {
            ptr_ = rhs.ptr_;
            rhs.ptr_ = nullptr;

            ref_ = rhs.ref_;
            rhs.ref_ = nullptr;
        }
        // Move construct a pointer from rhs.

        smart_ptr& operator=(const smart_ptr& rhs) noexcept
        {
            if (ref_count() < 2)
            {
                delete ptr_;
                delete ref_;
            } 
            else
            {
                *ref_ = *ref_ - 1;
            }

            ptr_ = rhs.ptr_;
            ref_ = rhs.ref_;

            if (ref_ != nullptr)
                *ref_ = *ref_ + 1;

            return *this;

        }
        // This assignment should make a shallow copy of the right-hand side's
        // pointer data. The reference count should be incremented as appropriate.

        smart_ptr& operator=(smart_ptr&& rhs) noexcept
        {
            delete ptr_;
            ptr_ = rhs.ptr_;
            rhs.ptr_ = nullptr;

            delete ref_;
            ref_ = rhs.ref_;
            rhs.ref_ = nullptr;

            return *this;
        }
        // This move assignment should steal the right-hand side's pointer data.
      
        bool clone()
        {
            if (ref_ == nullptr)
                return false;

            if ((ptr_ == nullptr) || (*ref_ == 1))
                return false;

            // Create tmp pointers for allocation
            T*   tmpPtr = nullptr;
            int* tmpRef = nullptr;

            // Make sure allocations are able to go through before modifying
            // current data, providing a strong gurantee.
            try
            {
                tmpPtr = new T(*ptr_);
                tmpRef = new int(1);
            }
            catch(const std::bad_alloc& e)
            {
                delete tmpPtr;
                delete tmpRef;
                std::cerr << e.what() << '\n';
                throw;
            }
            
            ptr_ = tmpPtr;

            *ref_ = *ref_ - 1;
            ref_ = tmpRef;

            return true;
        }
        // If the smart_ptr is either nullptr or has a reference count of one, this
        // function will do nothing and return false. Otherwise, the referred to
        // object's reference count will be decreased and a new deep copy of the
        // object will be created. This new copy will be the object that this
        // smart_ptr points and its reference count will be one. 
      
        int ref_count() const noexcept
        { 
            if (ref_ == nullptr)
                return 0;
        
            return *ref_;
        }
        // Returns the reference count of the pointed to data.

        T& operator*()
        {
            if (ptr_ == nullptr)
                throw null_ptr_exception("Ptr null");

            return *ptr_;
        }
        // The dereference operator shall return a reference to the referred object.
        // Throws null_ptr_exception on invalid access. 

        T* operator->()
        {
            if (ptr_ == nullptr)
                throw null_ptr_exception("Ptr null");

            return ptr_;
        }
        // The arrow operator shall return the pointer ptr_. Throws null_ptr_exception
        // on invalid access.

        ~smart_ptr() noexcept
        {
            if (ref_ == nullptr)
                return;

            if (*ref_ == 1)
            {
                delete ptr_;
                delete ref_;
                return;
            }

            *ref_ = *ref_ - 1;
        }
        // deallocate all dynamic memory
    
    private:
        T*   ptr_;             // pointer to the referred object
        int* ref_;             // pointer to a reference count
};
