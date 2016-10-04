//
//  Delete_Expression_Tree.hpp
//  treecalcfinal
//
//  Created by Armen Nahapetian on 4/16/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef Delete_Expression_Tree_h
#define Delete_Expression_Tree_h

#include <stdio.h>

#include "Expression_Node_Visitor.h"
#include "Stack.h"
#include "Add_Node.h"
#include "Number_Node.h"
#include "Mod_Node.h"
#include "Multiply_Node.h"
#include "Division_Node.h"
#include "Sub_Node.h"

class Delete_Expression_Tree: public Expression_Node_Visitor{
    
public:
    
    
    Delete_Expression_Tree  (void);
    
    ~Delete_Expression_Tree (void);
    
    // Methods for visiting concrete nodes
    void Visit_Addition_Node (const Add_Node & node);
    void Visit_Number_Node (const Number_Node & node);
    void Visit_Division_Node (const Division_Node & node);
    void Visit_Mod_Node (const Mod_Node & node);
    void Visit_Sub_Node (const Sub_Node & node);
    void Visit_Multiply_Node (const Multiply_Node & node);
    
    
};



#endif /* Delete_Expression_Tree_h */
