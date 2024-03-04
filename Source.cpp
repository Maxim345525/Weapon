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
        cout << "��� - �������� �����: " << attackRange << ", ��� �����: " << damageType << endl;
    }
};
class Bow : public Weapon {
private:
    int attackRange;
    string damageType;

public:
    Bow(int range, const string& type) : attackRange(range), damageType(type) {}

    void displayInfo() const override {
        cout << "��� - �������� �����: " << attackRange << ", ��� �����: " << damageType << endl;
    }
};
class Dagger : public Weapon {
private:
    int attackRange;
    string damageType;

public:
    Dagger(int range, const std::string& type) : attackRange(range), damageType(type) {}

    void displayInfo() const override {
        cout << "������� - �������� �����: " << attackRange << ", ��� �����: " << damageType << endl;
    }
};
class WeaponFactory {
public:
    static Weapon* createWeapon(const std::string& type, int range, const std::string& damageType) {
        if (type == "���") {
            return new Sword(range, damageType);
        }
        else if (type == "���") {
            return new Bow(range, damageType);
        }
        else if (type == "�������") {
            return new Dagger(range, damageType);
        }
        else {
            cerr << "�������� ��� ����!" << endl;
            return nullptr;
        }
    }
};
int main() {
    Weapon* sword = WeaponFactory::createWeapon("���", 2, "Գ������");
    Weapon* bow = WeaponFactory::createWeapon("���", 10, "������������");
    Weapon* dagger = WeaponFactory::createWeapon("�������", 1, "�������");
    sword->displayInfo();
    bow->displayInfo();
    dagger->displayInfo();
    delete sword;
    delete bow;
    delete dagger;
    return 0;
}
