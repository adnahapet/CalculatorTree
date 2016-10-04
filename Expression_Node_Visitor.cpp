//
//  Expression_Node_Visitor.cpp
//  TreeCalculator
//
//  Created by Armen Nahapetian on 4/2/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "Expression_Node_Visitor.h"
#include "Add_Node.h"
#include "Number_Node.h"
#include "Mod_Node.h"
#include "Multiply_Node.h"
#include "Division_Node.h"
#include "Sub_Node.h"

Expression_Node_Visitor::~Expression_Node_Visitor(){
}

void Expression_Node_Visitor::Visit_Addition_Node (const Add_Node & node){
}

void Expression_Node_Visitor::Visit_Number_Node (const Number_Node & node){
}

void Expression_Node_Visitor::Visit_Mod_Node(const Mod_Node &node){
}

void Expression_Node_Visitor::Visit_Sub_Node(const Sub_Node &node){
}

void Expression_Node_Visitor::Visit_Division_Node(const Division_Node &node){
}

void Expression_Node_Visitor::Visit_Multiply_Node(const Multiply_Node &node){
}