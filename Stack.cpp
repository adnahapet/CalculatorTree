// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack
// Void constructor creates array based stack of type T with default size of 100
template <typename T>
Stack <T>::Stack (void):
top_(-1),
is_empty_(true),
size_of_stack_(100)
{
    
}

//
// Stack
// Copy constructor creates new array based stack of type T to match queue stack
template <typename T>
Stack <T>::Stack (const Stack & stack):
top_(-1),
is_empty_(true),
size_of_stack_(stack.size_of_stack_)
{
	this->myStack = Array <T> (stack.myStack);
	this->top_ = stack.top_;
	this->is_empty_ = stack.is_empty_;
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
    //nothing to delete
}

//
// push
// iterates top_  and inserts element in the first empty index of array and 
// automatically doubles size of stack if size_of_stack is reached
template <typename T>
void Stack <T>::push (T element)
{
	if(this->top_+1 < this->size_of_stack_ )
	{
		this->top_++;
		this->myStack.set(top_,element);
		is_empty_ = false;
	}
	else
		{
            int new_size_ = this->size_of_stack_* 2;
			this->myStack.resize(new_size_);
			top_++;
			this->myStack.set(top_,element);
			is_empty_ = false;
		}
}

//
// pop
// deletes the topmost element from the stack 
// decrements top_ and size_of_stack
template <typename T>
T Stack <T>::pop (void)
{
    T temp;
	if (this->is_empty_==true){
        throw empty_exception();
	}
	else{
        temp = this->top();
		--top_;
		if(top_==-1){
			is_empty_=true;
		}
	}
    
    return temp;
}


//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	if(this != &rhs){
		this->myStack.resize(rhs.size_of_stack_);
		for(int i=0;i<rhs.size_of_stack_;i++){
			this->myStack.set(i,rhs.myStack[i]);
		}
    	this->top_ = rhs.top_;
	}
    return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    size_of_stack_ = 0;
    top_= -1;
    is_empty_= true;
}
