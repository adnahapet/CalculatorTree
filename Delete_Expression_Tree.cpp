//
//  Delete_Expression_Tree.cpp
//  treecalcfinal
//
//  Created by Armen Nahapetian on 4/16/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "Delete_Expression_Tree.h"

Delete_Expression_Tree::Delete_Expression_Tree(){
    
}

Delete_Expression_Tree::~Delete_Expression_Tree(){
    
}

void Delete_Expression_Tree::Visit_Number_Node(const Number_Node &node){
     delete this;
}

void Delete_Expression_Tree::Visit_Addition_Node(const Add_Node &node){
    node.left->accept(*this);
    node.right->accept(*this);
    
   delete this;
}

void Delete_Expression_Tree::Visit_Mod_Node(const Mod_Node &node){
    node.left->accept(*this);
    node.right->accept(*this);
    
     delete this;
}

void Delete_Expression_Tree::Visit_Sub_Node(const Sub_Node &node){
    node.left->accept(*this);
    node.right->accept(*this);
    
    delete this;
}

void Delete_Expression_Tree::Visit_Division_Node(const Division_Node &node){
    node.left->accept(*this);
    node.right->accept(*this);
    
    delete this;
}

void Delete_Expression_Tree::Visit_Multiply_Node(const Multiply_Node &node){
    node.left->accept(*this);
    node.right->accept(*this);
    
    delete this;
}
