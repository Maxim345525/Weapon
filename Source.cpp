#include <iostream>
#include <string>
using namespace std;
class Weapon {
public:
    virtual void displayInfo() const = 0;
    virtual ~Weapon() {}
};
class Sword : public Weapon {
private:
    int attackRange;
    string damageType;

public:
    Sword(int range, const string& type) : attackRange(range), damageType(type) {}

    void displayInfo() const override {
        cout << "Меч - Дальність атаки: " << attackRange << ", Тип урону: " << damageType << endl;
    }
};
class Bow : public Weapon {
private:
    int attackRange;
    string damageType;

public:
    Bow(int range, const string& type) : attackRange(range), damageType(type) {}

    void displayInfo() const override {
        cout << "Лук - Дальність атаки: " << attackRange << ", Тип урону: " << damageType << endl;
    }
};
class Dagger : public Weapon {
private:
    int attackRange;
    string damageType;

public:
    Dagger(int range, const std::string& type) : attackRange(range), damageType(type) {}

    void displayInfo() const override {
        cout << "Кинджал - Дальність атаки: " << attackRange << ", Тип урону: " << damageType << endl;
    }
};
class WeaponFactory {
public:
    static Weapon* createWeapon(const std::string& type, int range, const std::string& damageType) {
        if (type == "Меч") {
            return new Sword(range, damageType);
        }
        else if (type == "Лук") {
            return new Bow(range, damageType);
        }
        else if (type == "Кинджал") {
            return new Dagger(range, damageType);
        }
        else {
            cerr << "Невідомий тип зброї!" << endl;
            return nullptr;
        }
    }
};
int main() {
    Weapon* sword = WeaponFactory::createWeapon("Меч", 2, "Фізичний");
    Weapon* bow = WeaponFactory::createWeapon("Лук", 10, "Вогнепальний");
    Weapon* dagger = WeaponFactory::createWeapon("Кинджал", 1, "Колючий");
    sword->displayInfo();
    bow->displayInfo();
    dagger->displayInfo();
    delete sword;
    delete bow;
    delete dagger;
    return 0;
}
