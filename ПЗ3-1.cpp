#include <iostream>

class IStrategy {
public:
    virtual void execute() = 0;
    virtual ~IStrategy() {}
};
class Strategy1 : public IStrategy
{
public:
    void execute() override {
        std::cout << "Strategy 1" << std::endl;
    }
};
class Strategy2 : public IStrategy {
public:
    void execute() override {
        std::cout << "Strategy 2" << std::endl;
    }
};
class Context {
private:
    IStrategy* strategy;
public:
    Context(IStrategy* strategy) : strategy(strategy) {}
    void setStrategy(IStrategy* newstrategy) { strategy = newstrategy; }
    void executeStrategy() { strategy->execute(); }
};
int main() {
    Strategy1 strategy1;
    Strategy2 strategy2;
    Context context(&strategy1);
    context.executeStrategy();
    context.setStrategy(&strategy2);
    context.executeStrategy();
    return 0;
}
