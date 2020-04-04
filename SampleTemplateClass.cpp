

#include<iostream>

//The class accepts strings, 
//so we need to use namespace
using namespace std;


int main()
{
    //StudentRecord is the generic class
    //The constructor sets the grade value
    StudentRecord<int> srInt(3);
    srInt.setId(111111);
    srInt.printGrades();
 
    StudentRecord<char> srChar('B');
    srChar.setId(222222);
    srChar.printGrades();

    StudentRecord<float> srFloat(3.333);
    srFloat.setId(333333);
    srFloat.printGrades();
    
    StudentRecord<string> srString("B-");
    srString.setId(4444);
    srString.printGrades();
    
    return 0;
}



//tell compiler this class uses a generic value
template <class T>
class StudentRecord
{
    private:
        const int size = 5;
        T grade;
        int studentId;
    public:
        StudentRecord(T input);
        void setId(int idIn);
        void printGrades();
};

template<class T>
StudentRecord<T>::StudentRecord(T input)
{
    grade=input;
}

template<class T>
void StudentRecord<T>::setId(int idIn)
{
    studentId = idIn;
}

template<class T>
void StudentRecord<T>::printGrades()
{
    cout<<"ID# "<<studentId<<": ";
    cout<<grade<<"\n ";
    cout<<"\n";
}
