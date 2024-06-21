#include <iostream>

class AbstractClass {
public:
    virtual ~AbstractClass() {}

    void templateMethod() {
        this->baseOperation1();
        this->requiredOperations1();
        this->baseOperation2();
        this->hook1();
        this->requiredOperation2();
        this->baseOperation3();
        this->hook2();
    }

protected:
    void baseOperation1() {
        std::cout << "AbstractClass: baseOperation1()" << std::endl;
    }

    void baseOperation2() {
        std::cout << "AbstractClass: baseOperation2()" << std::endl;
    }

    void baseOperation3() {
        std::cout << "AbstractClass: baseOperation3()" << std::endl;
    }

    virtual void requiredOperations1() = 0;
    virtual void requiredOperation2() = 0;

    virtual void hook1() {}
    virtual void hook2() {}
};

class ConcreteClassA : public AbstractClass {
protected:
    void requiredOperations1() override {
        std::cout << "ConcreteClassA: requiredOperations1()" << std::endl;
    }

    void requiredOperation2() override {
        std::cout << "ConcreteClassA: requiredOperation2()" << std::endl;
    }

    void hook1() override {
        std::cout << "ConcreteClassA: hook1()" << std::endl;
    }
};

class ConcreteClassB : public AbstractClass {
protected:
    void requiredOperations1() override {
        std::cout << "ConcreteClassB: requiredOperations1()" << std::endl;
    }

    void requiredOperation2() override {
        std::cout << "ConcreteClassB: requiredOperation2()" << std::endl;
    }

    void hook2() override {
        std::cout << "ConcreteClassB: hook2()" << std::endl;
    }
};

int main() {
    AbstractClass* classA = new ConcreteClassA;
    AbstractClass* classB = new ConcreteClassB;


    classA->templateMethod();
    std::cout << std::endl;
    classB->templateMethod();

    delete classA;
    delete classB;

    return 0;
}
