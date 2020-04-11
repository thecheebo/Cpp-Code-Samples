1. Given the following class:
// this would be in the .h file
template <class KeyType, class ElemType>
class Dictionary {
  public:
    Dictionary();  //default constructor
    Dictionary(const Dictionary& origVal);  //copy constructor
    ~Dictionary();  //destructor
  private:
    Array<KeyType> keys;
    Array<ElemType*> elements;
    int size;
};
template <class KeyType, class ElemType>  //Deep copy
Dictionary<KeyType, ElemType>::Dictonary(const Dictionary<KeyType, ElemType>& origVal)
{
  size = origVal.size;
  keys = origVal.keys; // we can assume KeyType has an operator=
  elements.SetBounds(origVal.elements.Lower(), origVal.elements.Upper());
  
  // we can assume ElemType has a copy constructor
  for (int i = elements.Lower(); i <= elements.Upper(); i++)
  {
    if (origVal.elements[i] == NULL)
      elements[i] = NULL;
    else
      elements[i] = new ElemType(*(origVal.elements[i]));
  }
}
