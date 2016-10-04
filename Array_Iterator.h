//
//  Array_Iterator.h
//  490calculator
//
//  Created by Armen Nahapetian on 3/7/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef Array_Iterator_h
#define Array_Iterator_h

#include <stdio.h>
#include "Array.h"


template <typename T>
class Array_Iterator{
    
public:
    
    /// Type definition of the element type.
    typedef T type;

    Array_Iterator(Array <T> & a);
    
    ~Array_Iterator (void);
    
    bool is_done (void); //{ return this->curr_ >= this->a_.cur_size_; }
    
    bool advance (void); //{ ++ this->curr_; }
    
    T & operator * (void); //{ return this->a.data_[this->curr_]; }
    
    T * operator -> (void); // { return &this->a_.data_[this->curr_]; }
    
private:
    
    Array <T> & a_;
    size_t curr_;
    
    
};

#include "Array_Iterator.cpp"
#endif /* Array_Iterator_h */
