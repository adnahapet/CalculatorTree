// -*- C++ -*-
// $Id: Array_Base.inl 828 2011-02-07 14:21:52Z hillj $
//
//  Array_Base.inl
//  TemplateTesting
//
//  Created by Armen Nahapetian on 2/25/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//



// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.


//
// size
//
template <typename T>
inline
size_t Array_Base <T>::size (void) const
{
    return cur_size_;
}
