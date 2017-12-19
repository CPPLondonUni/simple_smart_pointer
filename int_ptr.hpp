
#ifndef INT_PTR_HPP_INCLUDED
#define INT_PTR_HPP_INCLUDED

#include <iostream>

struct int_ptr {
    // Default constructor
    // Requirement: sets ptr to an appropriate default value
    int_ptr() = default;

    // Int constructor
    // Requirement: creates a new dynamically-allocated int with value i and assigns it to ptr
    explicit int_ptr(int i)
        : ptr(new int{i})
    {
    }

    // Destructor
    // Requirement: deallocates ptr
    ~int_ptr()
    {
        delete ptr;
    }

    // Copy constructor
    // Requirement: allocates a new dynamically-allocated int with the same value as other
    int_ptr(const int_ptr& other)
    {
        if (other.ptr) {
            ptr = new int{*other.ptr};
        }
    }

    // Copy assignment operator
    // Requirement: sets the value of our int to the same as the value of other
    int_ptr& operator=(const int_ptr& other)
    {
        if (this != &other) {
            delete ptr;
            ptr = nullptr;
            if (other.ptr) {
                ptr = new int{*other.ptr};
            }
        }
        return *this;
    }


    // Boolean conversion operator
    // Requirement: returns true iff ptr is allocated
    explicit operator bool() const
    {
        return ptr != nullptr;
    }

    // Dereference operator
    // Requirement: returns a reference to our contained object
    // Note: the return value of the prototype is not correct!
    int& operator*() const
    {
        return *ptr;
    }

    // Requirement: returns the contained pointer
    int* get() const
    {
        return ptr;
    }

    // Requirement: replaces the contained pointer with other_ptr
    void reset(int* other_ptr = nullptr)
    {
        delete ptr;
        ptr = other_ptr;
    }


// private:
    // N.B. This member variable would normally be private, it is left public
    // here to avoid crashing the tests when functions are not implemented
    int* ptr = nullptr;
};



#endif
