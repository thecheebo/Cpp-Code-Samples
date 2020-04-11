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
  
List<int> theList;
  for (int i = 1; i <= n; i++) // <--- this is the n referred to above
    theList.InsertAfter(i);
  theList.Head();
  int len = theList.Length();
  for (int i = 1; i < len; i++) {
    cout << theList.Retrieve() << endl;
    theList.Remove();
    theList.Head();
}
