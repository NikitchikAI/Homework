#include <iostream>
#include <vector>

class Visitor;
class Element {
public:
    virtual void accept(Visitor& visitor) = 0;
};

class ElementA : public Element {
public:
    void accept(Visitor& visitor) override;
    void operationA() { std::cout << "Operation A\n"; }
};

class ElementB : public Element {
public:
    void accept(Visitor& visitor) override;
    void operationB() { std::cout << "Operation B\n"; }
};

class Visitor {
public:
    virtual void visit(ElementA& element) = 0;
    virtual void visit(ElementB& element) = 0;
};

class SomeVisitor : public Visitor {
public:
    void visit(ElementA& element) override { element.operationA(); }
    void visit(ElementB& element) override { element.operationB(); }
};

void ElementA::accept(Visitor& visitor) { visitor.visit(*this); }
void ElementB::accept(Visitor& visitor) { visitor.visit(*this); }

int main() {
    ElementA elementA;
    ElementB elementB;
    SomeVisitor visitor;
    elementA.accept(visitor);
    elementB.accept(visitor);
    return 0;
}
