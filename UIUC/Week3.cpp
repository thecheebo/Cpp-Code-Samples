#include <iostream>

class Pair {
public:
int *pa,*pb;
Pair(int A, int B);
Pair(const Pair &);
~Pair();
};

 Pair::Pair (int a,int b) {
      pa = new int(a);
      pb = new int(b);
      std::cout << "pa points to value : " << *pa <<std::endl;
      std::cout << "pb points to value : " << *pb <<std::endl;
      std::cout << "custom constructor resolved "<<std::endl;
    }
    
Pair::Pair(const Pair &obj) {
    int a = *obj.pa;
    int b = *obj.pb;
    pa = new int(a);
    pb = new int(b);

}

   Pair::~Pair() {
      delete pa; pa = nullptr;
      std::cout << "pa deleted " << std::endl;

      delete pb; pb = nullptr;
      std::cout << "pb deleted " << std::endl;
    }

  
int main() {
  Pair p(15,16);
  Pair q(p);
  Pair *hp = new Pair(23,42);
  delete hp;
  
  std::cout << "If this message is printed,"
    << " at least the program hasn't crashed yet!\n"
    << "But you may want to print other diagnostic messages too." << std::endl;
  return 0;
}
