class List:
  List(); // creates empty list
  List(const List& origVal); // copy constructor
  ~List(); // destructor
  const List& operator=(const List& origVal); // assignment operator
  void Clear(); // empties an existing list
  void InsertAfter(const Etype& newElem); // inserts after current value
  void InsertBefore(const Etype& newElem); // inserts before current value
  void Remove(); // removes current value
  void Update(const Etype& updateElem); // changes current value to parameter value
  void Head(); // changes current marker to indicate first value
  void Tail(); // changes current marker to indicate last value
  List& operator++(int); // moves current marker one position forward
  List& operator--(int); // moves current marker one position backward
  const Etype& Retrieve() const; // returns the current value
  int Find(const Etype& queryElem); // returns 1 if parameter is in list, else 0
  int Length() const; // returns number of elements in list
  void Print() const; // prints list to screen

(a) You are given the following generic function:
// assumes that the type which iterators point to, supports operator!=
template <class Iter>
int isPalindrome(Iter first, Iter last) {
  if (first == last) // empty range
    return 1;
  else {
    last--;
    while (first != last) {
      if (*first != *last)
        return 0;
      else {
        first++;
        if (first == last)
          return 1;
        else
          last--;
      }
    }
    return 1;
  }
}

Furthermore, you have a class list as seen on the MPs (i.e. with a nested iterator
class, and you have made the declaration:
list<int> theList;

and then inserted values such that the list looks as follows (where the asterisk indicates
the null position at the end of the list):

2 8 3 9 4 0 3 5 7 1 6 *

Write some code that uses iterators for the list theList that we declared above, and
the template function above, to print a 1 if the above list is a palindrome and 0 if it is
not. (It is not, but let the template function decide that.) Note that no iterators are
declared yet; you will need to do that yourself, if you decide you need iterator variables.
(6 points)
                                                       
list<int>iterator it1, it2;
it1 = theList.begin();
it2 = theList.end();
count <<isPalindrome(it1,it2) <<endl;
