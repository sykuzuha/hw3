#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack: public std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};

// Constructor
template<typename T>
Stack<T>::Stack() {}

// Destructor
template<typename T>
Stack<T>::~Stack() {}

template <typename T>
bool Stack<T>::empty() const
{
    return std::vector<T>::empty();
}

template <typename T>
size_t Stack<T>::size() const
{
    return std::vector<T>::size();
}

template <typename T>
void Stack<T>::push(const T& item)
{
    std::vector<T>::push_back(item);
}

template <typename T>
void Stack<T>::pop()  // throws std::underflow_error if empty
{
    if(empty())
    {
        throw std::underflow_error("Empty stack");
    }
    else{
        std::vector<T>::pop_back();
    }
}

template <typename T>
const T& Stack<T>::top() const// throws std::underflow_error if empty
{
    if(empty())
    {
        throw std::underflow_error("Empty stack");
    }
    else{
        return std::vector<T>::back();
    }
}
// Add other members only if necessary


#endif