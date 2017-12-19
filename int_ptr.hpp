
#ifndef INT_PTR_HPP_INCLUDED
#define INT_PTR_HPP_INCLUDED

#include <iostream>

struct int_ptr {
    // Default constructor
    // Requirement: sets ptr to an appropriate default value
    int_ptr()
    {
    }

    // Int constructor
    // Requirement: creates a new dynamically-allocated int with value i and assigns it to ptr
    explicit int_ptr(int i)
    {
    }

    // Destructor
    // Requirement: deallocates ptr
    ~int_ptr()
    {
    }

    // Copy constructor
    // Requirement: allocates a new dynamically-allocated int with the same value as other
    int_ptr(const int_ptr& other)
    {
    }

    // Copy assignment operator
    // Requirement: sets the value of our int to the same as the value of other
    int_ptr& operator=(const int_ptr& other)
    {
        return *this;
    }


    // Boolean conversion operator
    // Requirement: returns true iff ptr is allocated
    explicit operator bool() const
    {
        return false;
    }

    // Dereference operator
    // Requirement: returns a reference to our contained object
    // Note: the return value of the prototype is not correct!
    int operator*() const
    {
        return 0;
    }

    // Requirement: returns the contained pointer
    int* get() const
    {
        return nullptr;
    }

    // Requirement: replaces the contained pointer with other_ptr
    void reset(int* other_ptr = nullptr)
    {
    }


// private:
    // N.B. This member variable would normally be private, it is left public
    // here to avoid crashing the tests when functions are not implemented
    int* ptr = nullptr;
};



#endif
