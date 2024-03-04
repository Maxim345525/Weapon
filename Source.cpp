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
        cout << "Додано компонент 1 з параметрами: " << parameters << endl;
    }
};
class Component2 : public ObjectBuilder {
public:
    void addComponent(const string& type, const string& parameters) override {
        cout << "Додано компонент 2 з параметрами: " << parameters << endl;
    }
};
class Component3 : public ObjectBuilder {
public:
    void addComponent(const string& type, const string& parameters) override {
        cout << "Додано компонент 3 з параметрами: " << parameters << endl;
    }
};
class ObjectDirector {
private:
    ObjectBuilder* builder;
public:
    ObjectDirector(ObjectBuilder* builder) : builder(builder) {}
    void constructObject() {
        builder->addComponent("Component1", "Параметри для компонента 1");
        builder->addComponent("Component2", "Параметри для компонента 2");
        builder->addComponent("Component3", "Параметри для компонента 3");
    }
};
int main() {
    ObjectBuilder* builder = new Component1(); 
    ObjectDirector director(builder);
    director.constructObject();
    delete builder;
    return 0;
}