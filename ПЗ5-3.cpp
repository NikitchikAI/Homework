#include <iostream>

class Target {
public:
    virtual ~Target() {}
    virtual void request() const = 0;
};
class Adaptee {
public:
    void specificRequest() const {
        std::cout << "Request from Adaptee" << std::endl;
    }
};
class Adapter : public Target {
public:
    Adapter(Adaptee* adaptee) : adaptee_(adaptee) {}
    void request() const override { adaptee_->specificRequest(); }
private:
    Adaptee* adaptee_;
};

int main() {
    Adaptee* adaptee = new Adaptee();
    Target* adapter = new Adapter(adaptee);
    adapter->request();
    delete adapter;
    delete adaptee;
    return 0;
}
