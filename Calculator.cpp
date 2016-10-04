//
//  Calculator.cpp
//  490calculator
//
//  Created by Armen Nahapetian on 3/5/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "Calculator.h"

// COMMENT: First your first submission, you are to implement a
// complete solution.

// COMMENT: Your design approach is requiring to many unnecessary
// transformations of the expression. For example, you are going
// from a tokenized array to a string to implement your design. This
// is a LOT of unwarranted overhead. Please fix this problem.

//SOLUTION: Thank you. I realize now what a mess that was. I've condensed all the validation steps into 1.
//Calculator class no longer has a tokenized array as a member variable and
//the validator method doesn't create an instance of a tokenized array either
//Everything is done with strings and streams
//All operators are functional and the subexpression parser now works
//removed a couple dozen lines of unneccesary code and as many commented out methods

//handles the flow of the program
//will continue until all caps Quit is entered
Calculator::Calculator()
{
    std::cout<<"Please enter an expression with spaces between all operators and operands."<<std::endl;
    std::cout<<"+ / - * % and () are currently supported."<<std::endl;
    std::cout<<"Expressions that are ubalanced will not be evaluated"<<std::endl;
    std::cout<<"Enter 'QUIT' in ALL Caps to exit."<<std::endl;
    
    
    getExpression();
    
    while (input!="QUIT"){
        //catches both unbalanced expressions and invalid arguments
        if(validator(input)==false){
            std::cout<<"Invalid input!"<<std::endl;
        }
        else{
            //prints final answer to console
            //moved the exception handling to this level and inserted a catch so dividing by 0 won't stop the calculator
            //improves on the original design
            try{
            std::cout<<evaluate_expression(input)<<std::endl;
            }
            catch(Evaluate_Expression_Tree::divide_by_zero_exception){
                std::cout<<"Your expression attempts to divide by 0 please try again"<<std::endl;
            }
        }
        
        //gets another expression unless QUIT is entered
        getExpression();
    
   }
   
    
}


Calculator::~Calculator(){
    
}


void Calculator::getExpression(){
    
    getline(std::cin,input);
    
}



//checks the input to make sure that for every ( there is a matching )
//also checks for invalid characters in the expression
bool Calculator::validator(std::string expression){
    
    Stack <std::string> balanceCheck;
    std::stringstream ss(expression);
    std::string token;
    
    
    while(!ss.eof()){
        ss>>token;
        if(token < "%" ||token > "9" || token == "&" ||token == "."||token == "'"||token == "`"){
            return false;
        }
        if (token == "(" ){
            balanceCheck.push(token);
        }
        if (token == ")"){
            if(balanceCheck.is_empty()==true || balanceCheck.top() != "(")
                return false;
            else
                balanceCheck.pop();
        }
    }
    
    if(balanceCheck.is_empty()==true)
        return true;
    balanceCheck.clear();
    return false;
}


//handles the flow of evaluation
//creates a concrete builder and passes that into parse expression
//creates a concrete visitor and executes the visitor pattern on the root of the tree
//returns the result of the expression as an int
int Calculator::evaluate_expression(const std::string & infix){
    

    Expression_Tree_Builder builder;
  
    builder.start_expression();
    
    parse_expression(infix,builder);
    
    Expression_Tree * expr;
    
    expr = builder.get_expression ();
   
    Evaluate_Expression_Tree eval;
   
    expr->root->accept(eval);
    
    int result = eval.result();
   
    return result;
    
}
    


//parses the input and tells the builder which part to make
//if a left parenthesis is encountered the parser creates a subexpression and passes that into a nested evaluator
// the returned result is then stored into a number node and inserted back into the original expression
bool Calculator::parse_expression(const std::string & infix, Expression_Builder &b){

    std::istringstream input(infix); // create an input stream parser
    std::string token;
    
    while (!input.eof ()) {
        
        input >> token;

        if (token == "+"){
            b.build_add_operand();
        }
        else if (token == "-"){
            b.build_subtract_operand();
        }
        else if (token =="%"){
            b.build_mod_operand();
        }
        else if (token == "*"){
            b.build_multiply_operand();
        }
        else if (token == "/"){
            b.build_division_operand();
        }
        else if (token == "("){
             std::string subexpression;
             input>>token;
             while(token != ")"){
                 subexpression+=token;
                 subexpression+=" ";
                 input>>token;
             }
             subexpression.pop_back();
             int subTotal = evaluate_expression(subexpression);
             b.build_number(subTotal);
         }
         else{
             int operand = std::stoi(token);
             b.build_number(operand);
         }

    }
    
    return true;
}




