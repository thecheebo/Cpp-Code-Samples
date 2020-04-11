1. Given the following class:
// this would be in the .h file
template <class KeyType, class ElemType>
class Dictionary {
  public:
    //default constructor
    Dictionary();
    //copy constructor
    Dictionary(const Dictionary& origVal);
    //destructor
    ~Dictionary();
    // ... plus other functions we don’t care about here
  private:
    Array<KeyType> keys;
    Array<ElemType*> elements;
    int size;
};
