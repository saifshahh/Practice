#include <iostream>
using namespace std;

class Document{
    string *text;
    
    public:
    
    Document(const string &text): text(new string(text)) {}
    ~Document(){ delete text; }
    
    Document(const Document &d){
        text = new string(*d.text);
    }
    
    Document& operator=(const Document &d){
        if(this==&d) return *this;
        delete text;
        text = new string(*d.text);
        return *this;
    }
    
    void display(){
        cout<< *text <<endl;
    }
    void setText(const string &newText){
        *text = newText;
    }
};

int main(){
    
    Document d1("Document 1");
    cout<<"Before Modifying: "<<endl;
    d1.display();
    
    Document d1c1(d1);
    d1c1.display();
    
    Document d1c2("abc");
    d1c2 = d1;
    d1c2.display();
    
    cout<<"After Modifying: "<<endl;
    d1.setText("Document 2");
    d1.display();
    d1c1.display();
    d1c2.display();
    
    
}
