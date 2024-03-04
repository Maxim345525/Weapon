#include <iostream>
#include <string>
using namespace std;
class ProductFactory {
public:
    virtual void createClothing(const string& type) const = 0;
    virtual void createElectronics(const string& type) const = 0;
    virtual ~ProductFactory() {}
};
class ClothingFactory : public ProductFactory {
public:
    void createClothing(const std::string& type) const override {
        cout << "Створено одяг типу: " << type << endl;
    }
    void createElectronics(const std::string& type) const override {
        cerr << "Помилка: Не можливо створити електроніку через фабрику одягу" << endl;
    }
};
class ElectronicsFactory : public ProductFactory {
public:
    void createClothing(const std::string& type) const override {
        cerr << "Помилка: Не можливо створити одяг через фабрику електроніки" << endl;
    }
    void createElectronics(const string& type) const override {
        cout << "Створено електроніку типу: " << type << endl;
    }
};
class Clothing {
public:
    virtual ~Clothing() {}
};
class TShirt : public Clothing {};
class Pants : public Clothing {};
class Jacket : public Clothing {};
class Electronics {
public:
    virtual ~Electronics() {}
};
class Smartphone : public Electronics {};
class Laptop : public Electronics {};
class Television : public Electronics {};
int main() {
    ProductFactory* clothingFactory = new ClothingFactory();
    ProductFactory* electronicsFactory = new ElectronicsFactory();
    clothingFactory->createClothing("Футболка");
    electronicsFactory->createElectronics("Смартфон");
    delete clothingFactory;
    delete electronicsFactory;
    return 0;
}