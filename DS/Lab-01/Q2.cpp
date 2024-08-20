#include <iostream>
using namespace std;

class Exam{
    string name;
    string date;
    int score;
    
    public:
    Exam(string name, string date, int score): name(name), date(date), score(score) {}
    
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Date: "<<date<<endl;
        cout<<"Score: "<<score<<endl<<endl;
    }
    
    void setName(string n){ name=n; }
    void setDate(string d){ date=d; }
    void setScore(int s){ score=s; }
};

int main(){
    
    Exam exam1("saif", "2 june", 77);
    cout<<"Details before modifying: "<<endl;
    exam1.display();
    Exam exam2(exam1);
    exam2.display();
    
    exam2.setName("shah");
    exam2.setDate("2 July");
    exam2.setScore(88);
    
    cout<<"Details after modifying: "<<endl;
    exam1.display();
    exam2.display();
    
}

