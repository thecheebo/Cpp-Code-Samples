Consider the following statements:
int *p;
int i;
int k;
i = 37;
k = i;
p = &i;

After these statements, which of the following will change the value of i to 75?

(d) *p = 75;

Consider the following statements:
int i = 1;
int k = 2;
int * p1;
int * p2;
p1 = &i;
p2 = &k;
p1 = p2;
*p1 = 3;
*p2 = 4;
cout << i << endl;
Which of the following is printed by the output statement (assume cout works)?
(a) 1

Consider the following C++ statements:
#include <iostream>
using namespace std;
void increment1(int x) { x = x + 1; }
void increment2(int * x) { *(x) = *x + 1; }
void increment3(int & x) { x = x + 1; }
int main() {
int x = 1;
increment1(x);
increment2(&x);
increment3(x);
cout << x << endl;
return 0;
}
What is the printed out when this code is compiled and run?

(c) 3

Which of the following is a correct way to declare and initialize a dynamic array of length
max, each element of which is a List whose parameterized type is a sphere?
(a) List<sphere> * myList = new List<sphere>[max];
(c) List<sphere> myList[max];


Find the errors in the following code. Select all that apply, if any.
#include <iostream>
using namespace std;
int * myFun(const int & a) {
int * c = new int(a);
int b = *c;
return &b;
}
int main() {
int n = 8;
cout << *(myFun(n)) << endl;
return 0;
}
(b) memory leak
(c) invalid return value

Which of the following functions are typically implemented in an iterator class? Check all
that apply, if any.
(a) operator*
(c) operator++


[Miscellaneous C++ – 17 points].
Solution:
(a) (8 points) We have seen 4 different uses for the symbol “:”. For each, give a short
example and explain using appropriate C++ vocabulary.
i. (::) Accessing a global variable in a class or name-space.
std::cout
Defining a function - scope resolution operator
<return-value> <class>::<member-function>(<args>) { /* ... */ }
ii. (:) inheritance
class A : public B {
}
iii. (:) determining the access level
class A {
public:
// ...
private:
//...
}
iv. (:) initializing a variable by a parameter - initializer list
void


We have seen two different uses of the keyword const. For each, give a short
(one line) code example and briefly explain the behavior.
Solution: One point for example, one point for explanation.
i. example 1:
const var_type variable
This would create a variable of type var type, whose value can not be changed.
ii. example 2: Const functions. Call to const functions won’t change the object.
<return-value> <class>::<member-function>(<args>) const
{
// ...
}


) There are 3 characterizing components of object oriented programming among
the list of concepts below. Circle them.
inheritance
polymorphism
encapsulation

4. [Inheritance – 10 points].
In each part of this problem we will be presenting you with a pair of classes and some code
snippets and asking you about the result of compiling and running the code. Your task will
be to tell us explicitly what happens, and why. If there is an error, you should reason about
whether the error occurs at compile time, or run time. If there is output, you should tell us
what the output is. If the result depends on some other factors, explain them. Assume that
the standard iostream is available (cout and cin work).
(a) (3 points) Class definitions:
class Rect{ class Sq: public Rect {
public: public:
Rect(int w,int h):wid(w),ht(h){} Sq(int side):Rect(side,side){}
private: int area(){return wid * wid;}
int wid, ht;
}; };
Code snippet:
Sq d(5);
cout << d.area << endl;
Result: Solution: Compiler error: class Sq cannot access Rect’s private members. (1
point for an answer of 25)

Which of the following is a correct way to declare an instance of a stack whose parameterized
type is an integer?
(b) stack<int> s;

***
int* x, y; y is an INT not an int pointer
***

C++ syntax
Suppose myVar is declared as follows: int ** myVar;. Which of the following could describe
the variable myVar once it has been initialized?
I. myVar is a dynamic array of integer pointers.
II. myVar is a pointer to a dynamic array of integers.
III. myVar is a dynamic array of dynamic arrays of integers.


 We need to write our own destructor (instead of using the default one) when...Answer:c

(c) we have allocated dynamic memory in our constructors

NOT :
(a) we have private members that are pointers.
(b) we have private members that are arrays.
 
 
 question
 Consider this prototype for a template function:
template <class Item>
void foo(Item x);
What is the right way to call the foo function with an integer argument i?Answer: a or b
(a) foo( i );
(b) foo<int>( i );


reference and address practice:
#include <iostream>
using namespace std;
void myFun(int * x) {
int *y = new int;
cout << "y: " << y << endl;

cout << "&y: " << &y << endl;

cout << "x: " << x << endl;
cout << "*x: " << *x << endl;
cout << "y: " << y << endl;

*y = 16;
cout << "y: " << y << endl;
cout << "*y: " << *y << endl;
cout << "&y: " << &y << endl;

cout << "x: " << x << endl;
cout << "*x: " << *x << endl;
cout << "&x: " << &x << endl;

x=y;

cout << "x: " << x << endl;
cout << "*x: " << *x << endl;
cout << "&x: " << &x << endl;

delete y;


}
int main(){
int i = 9;
cout << "i: " << i << endl;
cout << "&i: " << &i << endl;
cout << "*&i: " << *&i << endl;

myFun(&i);
cout << i << endl;
return 0;
}


another

#include <iostream>
using namespace std;
void myFun(int * x) {
  cout << "*x is " << *x << endl;
    cout << "x is " << x << endl;
x = new int;
*x = 12;
}
int main(){
int v = 10;
cout << "&v is " << &v << endl;

myFun(&v);
cout << v << endl;
return 0;
}

 &v is 0xfff000bdc
*x is 10
x is 0xfff000bdc
10
  
  #include <iostream>
using namespace std;
void myFun(int & x) {
  cout << "*x is " << &x << endl;
    cout << "x is " << x << endl;

x = 12;
}
int main(){
int v = 10;
cout << "v is " << v << endl;
cout << "&v is " << &v << endl;

myFun(v);
cout << v << endl;
return 0;
}
v is 12
 
 
 QUESTION
 MC3 (2.5pts)
Which situation does not use the copy constructor?
(a) Calling a function that has only a reference parameter.
(b) Calling a function that has only a value parameter.
(c) Declaring a variable to be a copy of another existing object.
(d) Returning a value from a function.
(e) All of these situations use the copy constructor.
 
 a maybe d.
 
 
