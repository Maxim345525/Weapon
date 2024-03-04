#include <iostream>
#include <string>
using namespace std;
class ObjectBuilder {
public:
    virtual void addComponent(const string& type, const string& parameters) = 0;
    virtual ~ObjectBuilder() {}
};
class Component1 : public ObjectBuilder {
public:
    void addComponent(const string& type, const string& parameters) override {
        cout << "������ ��������� 1 � �����������: " << parameters << endl;
    }
};
class Component2 : public ObjectBuilder {
public:
    void addComponent(const string& type, const string& parameters) override {
        cout << "������ ��������� 2 � �����������: " << parameters << endl;
    }
};
class Component3 : public ObjectBuilder {
public:
    void addComponent(const string& type, const string& parameters) override {
        cout << "������ ��������� 3 � �����������: " << parameters << endl;
    }
};
class ObjectDirector {
private:
    ObjectBuilder* builder;
public:
    ObjectDirector(ObjectBuilder* builder) : builder(builder) {}
    void constructObject() {
        builder->addComponent("Component1", "��������� ��� ���������� 1");
        builder->addComponent("Component2", "��������� ��� ���������� 2");
        builder->addComponent("Component3", "��������� ��� ���������� 3");
    }
};
int main() {
    ObjectBuilder* builder = new Component1(); 
    ObjectDirector director(builder);
    director.constructObject();
    delete builder;
    return 0;
}