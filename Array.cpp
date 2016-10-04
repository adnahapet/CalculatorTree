// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.



#include <iostream>

//
// Array
//creates a default Array of size 100 with a default max size 200
template <typename T>
Array <T>::Array (void):
    Array_Base <T>(200),
    max_size_(0)
{
    this->cur_size_=100;
    max_size_=200;
}

//
// Array (size_t)
// creates an Array of size length with a maximum size of length * 2
template <typename T>
Array <T>::Array (size_t length):
    Array_Base <T> (length),
    max_size_(0)
{
    this->max_size_ = length*2;
    this->cur_size_= length;
}

//
// Array (size_t, char)
// creates an Array of size length * 2 and iterates over cur_size_/length fills all available indicies with element T fill
template <typename T>
Array <T>::Array (size_t length, T fill):
    Array_Base <T> (length*2),
    max_size_(0)
{
    this->max_size_ = length*2;
    this->cur_size_ = length;
    Array_Base <T> :: fill (fill);
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array):
    Array_Base <T> (array),
    max_size_(0)
{
   this->max_size_ = array.max_size_;
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{

}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
    if( this != &rhs){
        Array::resize(rhs.max_size_);
        for(int i=0;i<rhs.cur_size_;i++){
            this->data_[i]=rhs.data_[i];
        }
    }
    return *this;
}



//
// resize
//checks to see if new_size is smaller than *this max allotment
// if it is then there is no need to adjust heap allotment
// makes cur_size = new_size effectively truncating or expanding array
// if new_size > max_size then all data is move to a new allotment on heap
template <typename T>
void Array <T>::resize (size_t new_size)
{
    if(this->max_size_>=new_size){
        this->cur_size_=new_size;
    }
    else{

        T * Temp = new T[new_size];
        max_size_=new_size;

        for(int i=0;i<this->cur_size_;i++)
        {
            Temp[i] = this->data_[i];
        }

        this->cur_size_ = new_size;

        T * swap = this->data_;
        this->data_ = Temp;
       Temp = swap;
		
		delete [] Temp;
		
    }
}



