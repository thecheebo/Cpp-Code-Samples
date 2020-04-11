#include <iostream>
#include <queue>
#include <stack>

std::queue<int> q;
//std::queue<int>& param = q;
std::stack<int> s;

void Quads(std::queue<int>& param) {
  int tempVal, i; // hint : i would be a useful loop counter
  
  std::stack<int> s; // not the best variable names, but you have
  std::queue<int> q; // less to write this way


  while(!param.empty()) {
    while(param.size() > 4){
      for (i=0; i<4;i++) {
        s.push(param.front());
        std::cout << "Front of Original Queue " << param.front() << std::endl;
        std::cout << "Last item in stack " << s.top() << std::endl;
        param.pop();
      }
      std::cout << "reverse" << std::endl;
      for (i=0; i<4;i++) {
        q.push(s.top());
        std::cout << "Back of New Queue "<< q.back() << std::endl;
        std::cout << "Last item in stack " << s.top() << std::endl;
        s.pop();
        
      }
    }
    for (i=0; i<param.size();i++) {
      std::cout << "Items remaining in original "<< param.size() << std::endl;
      s.push(param.front());
      param.pop();
    }
    for (i=0; i<s.size();i++) {
      q.push(s.top());
      s.pop();
    }
  }
  
  
  std::cout << q.front() << std::endl;
  q.pop();
  std::cout << q.front() << std::endl;
  q.pop();
    std::cout << q.front() << std::endl;
  q.pop();
  std::cout << q.front() << std::endl;
  q.pop();
    std::cout << q.front() << std::endl;
  q.pop();
  std::cout << q.front() << std::endl;
  q.pop();
  std::cout << q.front() << std::endl;
  q.pop();
  std::cout << q.front() << std::endl;
  q.pop();
  std::cout << q.front() << std::endl;
  q.pop();
  
  
  
}

int main() {
  std::queue<int> basil;
  basil.push(15);
  basil.push(25);
  basil.push(35);
  basil.push(45);  
  basil.push(55);
  basil.push(65);  
  basil.push(75);
  basil.push(85);  
  basil.push(95);
  
  //for (int i = 0; i < basil.size(); i++) {

  Quads(basil);


  
  
  
  /*std::cout << basil.front() << std::endl;
  basil.pop();
  std::cout << basil.front() << std::endl;
  basil.pop();
  std::cout << basil.front() << std::endl;

  std::cout << basil.back() << std::endl;

  std::cout << basil.front() << std::endl;
  std::cout << basil.back() << std::endl;
  */
  return 0;
}
