
Pointers
Memory Leaks
Constructors
Deconstructors

Inheritance
Template



Quiz2
True Facts

1)

T: The address of any memory location in the stack is larger than the address of any memory location in the heap.
R: The stack begins at a high memory address and works its way down, whereas the heap begins at a low memory address and works its way up.
The "new" operator allocates memory on the heap that gets removed from the heap by the "delete"operator.
The C++ statement “int i;” allocates memory for one integer on the stack.
You should avoid using the memory address 0x0 for pointers whose value is not yet set, because memory location 0x0 is not a valid location for the system to allocate to hold the contents of a variable.

2)
Suppose we declare a variable as “int i;” Which of the following expressions returns the address of the memory location containing the contents of variable i?

&i
The & operator returns the address of its operand.

3)
class Pair {
    public: double a,b;
};

int main() {
    Pair *p = new Pair;
    p->a = 0.0;
    return 0;
}
The expression p->a is equivalent to which one of the following? (*p.).a
The arrow operator -> accesses the right operand member in the class at the memory address of its left operand.

Quiz 3
Which one of these is the only true statement about a class constructor.

T: When declaring a constructor for a class, the name of the constructor must be the name of the class.
A class does not need at least one constructor declared for it.
A class can have many constructors.

2)
Which of the following examples does NOT call a copy constructor at least once?
Cube a,b(10);
a = b;

Correct: The copy constructor will not be called.

In this case, the assignment operator is called (either the default assignment operator or one that has been explicitly declared). Since the operand of the assignment operator is passed by reference and not by value, the copy constructor is not called because no new object needs to be constructed.

CC is called:

Cube b(10);
Cube a = b;

CC is called:

// Function prototype for "contains":
int contains(Cube outer, Cube inner);

CC is called:

// Function prototype for "intersect":
Cube intersect(Cube &left, Cube &right);
// ...
Cube a(10),b(5);
Cube c;
c = intersect(a,b);
// ...
Cube a(10),b(5);
int a_bounds_b = contains(a,b);

3)
Recall that a custom assignment operator can be declared such that line 2 of the code below executes a user-defined function to perform the assignment.

The custom assignment operator is a public member function of the class.

Correct
Indeed, the assignment operator is a member function of the class of the target object, and this member function must be public in order for the assignment operator to be used in contexts outside of the class's own implementation as shown in the example in this question..

4)
class Orange {
  public:
    Orange(double weight);
    ~Orange();
    double getWeight();
  
  private:
    double weight_;
};


Select all functions that are present in this class (including any automatic/implicit functions added by the compiler):


Default constructor
Copy constructor
//You didn’t select all the correct answers


At least one custom, non-default constructor
Assignment operator
Destructor

5)
class Blue {
  public:
    double getValue();
    void setValue(double value);

  private:
    double value_;
};


Default constructor

Correct

At least one custom, non-default constructor


Copy constructor


Assignment operator

Correct

Destructor

Correct
You didn’t select all the correct answers

6)
When you use the new operator to create a class object instance in heap memory, the new operator makes sure that memory is allocated in the heap for the object, and then it initializes the object instance by automatically calling the class constructor.

Q: After a class object instance has been created in heap memory with new, when is the destructor usually called?


A: The destructor is called automatically when the delete operator is used with a pointer to the instance of the class.

7)

We have looked at examples where the assignment operator returned the value "*this". The variable "this" is available by default in most class member functions. What is the value of this built-in class variable "this"?


A pointer to the current object instance.

Example:

This is correst. In fact, members of the current object can be accessed as "this->membername" . For example, if you define a member function whose argument is the same name as a member variable, any use of that name in the local scope of the function refers to the argument and not the member variable, but you can still access the member variable as "this->membername" . Hence the following example works.

class Just_a_double {
    double val;
public:
    void setValue(double val) {
        this->val = val;
    }
    
    8)
    
    Consider the code below that includes a class that has a custom constructor and destructor and both utilize a global variable (which has global scope and can be accessed anywhere and initialized before the function main is executed).


Which one of the following procedures (void functions) properly ensures the deallocation of all the memory allocated for objects of type Track so the memory can be re-used for something else after the procedure returns?

For the correct answer, the variable reference_count should be zero after all calls to track_stuff() and all of the memory should be deallocated properly. This will dependably occur after only one of the following procedures.




void track_stuff() {
    Track t;
    Track *p = new Track;
    // ...
    delete p;
    return;
}
Correct
This procedure declares t as an object of class Track with its memory allocated on the stack at local scope. The object t will automatically be destroyed and the memory will be deallocated when the function returns. This example also allocates memory for another Track on the heap using new and stores that address in the pointer to Track, p. The object p is destroyed and its memory is deallocated when the delete operator is used.
}



Quiz 4

1) 
Which one of the following is NOT true?


True: C++ allows a variable to be declared in a user-defined function with an unknown type that can be defined when the function is called.


 False: C++ allows a local variable to be declared in main() with an unknown type that can be defined when the program is executed.


True:C++ allows a member variable to be declared in a user-defined class with an unknown type that can by defined when an object of that class is created.


True: C++ allows a variable to be declared in a user-defined member function of a user-defined class that can be defined when the function is called.

Correct
Even though C++ allows functions and classes to use templated types that are defined when the function is called or an object of that class is created, every variable must have a type known at compile time

3)

Which of the following will generate an error at compile time?


std::vector v; ERROR


std::vector<double> v;


std::vector<char[256]> v;


std::vector<std::vector<int>> v;

Correct
This will generate a compile-time error because the compiler does not know what type should be used for the elements of the std::vector, and every variable (including v) has to have a type at compile time. You have to supply a type as the template parameter for the elements of the std::vector.

4.

template <typename Type>
Type max(Type a, Type b) {
    return (a > b) ? a : b;
}

Which one of the following exampled is a proper way to call the max function declared above in template form?


max(5.0,10.0)

Correct
Whereas a class needs to explicitly identify the type, a templated function does not need to explicitly identify the type(s) used if the type of its arguments can be sufficiently matched to the templated types used in the function declaration.

6)

Which one of the following properly declares the class RubikCube derived from the base class Cube?



class Cube(RubikCube) {...}; INCORRECT


class RubikCube : public Cube {...};  CORRECT


class Cube : public RubikCube {...}; INCORRECT


class RubikCube(Cube) {...}; INCORRECT

Correct
This correctly derives RubikCube as a specialization of base class Cube
This correctly derives RubikCube as a specialization of base class Cube

8)

class Pair {
private:
    double a,b;
};

class equalPair : public Pair {
private:
    bool isequal;
public:
    int status();
}

When the function status() is implemented, which variables will it have access to?


Both the member variables a,b or Pair and isequal of equalPair.


No member variables of either equalPair or Pair.


Just the member variable isequal of equalPair.


Just the member variables a,b of Pair.

Correct
Even though Pair is indicated as a public base class, the derived class equalPair does not have access to the private members of Pair.


9)

class Just_a_double {
public:
    double a;

    Just_a_double(double x) : a(x) { }
    Just_a_double() : Just_a_double(0) { }
}

Which constructors, if any, compile properly?



Both constructors on lines 5 and 6 compile properly



Correct
The initializer lists allow both member variable constructors as well as other declarations of the class constructor.
