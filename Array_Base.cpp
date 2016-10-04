// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $
//
//  Array_Base.cpp
//  TemplateTesting
//
//  Created by Armen Nahapetian on 2/25/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.


#include <stdexcept>         // for std::out_of_bounds exception
#include <iostream>

//
// Array
//creates a default Array of size 100
template <typename T>
Array_Base <T>::Array_Base (void):
    data_(nullptr),
    cur_size_(0)
{
    
    this->data_= new T[DEFAULTSIZE];
    this->cur_size_ = DEFAULTSIZE;

}

//
// Array (size_t)
// creates an Array of size length
template <typename T>
Array_Base <T>::Array_Base (size_t length):
    data_(nullptr),
    cur_size_(0)
{
    
    this->data_= new T[length];
    this->cur_size_ = length;
    
}

//
// Array (size_t, char)
// creates an Array of size length and iterates over length fills all available indicies with element T fill
template <typename T>
Array_Base <T>::Array_Base (size_t length, T fill):
    data_(nullptr),
    cur_size_(0)
{  

    this->data_ = new T[length];
    this->cur_size_=length;

    this->fill(fill);
}

//
// Array (const Array &)
// 
template <typename T>
Array_Base <T>::Array_Base (const Array_Base & array):
    data_(nullptr),
    cur_size_(0)
{

    this->data_ = new T[array.cur_size_];
    this->cur_size_=array.cur_size_;

    for(int i=0;i<array.cur_size_;i++)
    {
        data_[i]= array.data_[i];
    }

}

//
// ~Array
//
template <typename T>
Array_Base <T>::~Array_Base<T> (void)
{
    delete [] this->data_;
}


//
// operator []
//
template <typename T>
T & Array_Base <T>::operator [] (size_t index)
{
    if (index >= cur_size_ || index < 0){
        throw std::out_of_range ("That index is out of range");
    }
    else{
        return data_[index];
    }
}

//
// operator [] 
//
template <typename T>
const T & Array_Base <T>::operator [] (size_t index) const
{
    if (index >= cur_size_ || index < 0){
        throw std::out_of_range ("That index is out of range");
    }
    else{
        return data_[index];
    }
}

//
// get
//
template <typename T>
T Array_Base <T>::get (size_t index) const
{
    if (index >= cur_size_ || index < 0){
        throw std::out_of_range ("That index is out of range");
    }
    return data_[index];
}

//
// set
//
template <typename T>
void Array_Base <T>::set (size_t index, T value)
{
    if (index >= cur_size_ || index < 0){
        throw std::out_of_range ("That index is out of range");
    }
    data_[index] = value;
}



//
// find (char)
//
template  <typename T>
int Array_Base <T>::find (T value) const
{
    for(int i=0;i<cur_size_;i++)
    {
        if(data_[i] == value)
            return i;
    }
    
    return -1;
}

//
// find (char, size_t) 
//
template <typename T>
int Array_Base <T>::find (T val, size_t start) const
{
    if (start >= cur_size_ || start < 0){
        throw std::out_of_range ("That index is out of range");
    }
    else{
        for(int i=start;i<cur_size_;i++)
        {
            if(*(data_+i) == val)
                return i;
        }
        return -1;
    }
}

//
// operator ==
//
template <typename T>
bool Array_Base <T>::operator == (const Array_Base & rhs) const
{
    if(cur_size_==rhs.cur_size_){
        for(int i=0;i<rhs.cur_size_;i++)
        {
            if(this->data_[i]!=rhs.data_[i])
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

//
// operator !=
//
template <typename T>
bool Array_Base <T>::operator != (const Array_Base & rhs) const
{
    if((*this == (rhs))== true)
        return false;
    return true;
}

//
// fill
//
template <typename T>
void Array_Base <T>::fill (T value)
{
    for(int i=0;i<cur_size_;i++)
    {
        data_[i] = value;
    }
}
