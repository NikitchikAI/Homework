#include <iostream>
#include <string>

class Product {
public:
    void setPartA(const std::string& partA) { partA_ = partA; }
    void setPartB(const std::string& partB) { partB_ = partB; }
    void setPartC(const std::string& partC) { partC_ = partC; }
    void show() {
        std::cout << "Parts product " << partA_ << ", " << partB_ << ", " << partC_ << std::endl;
    }
private:
    std::string partA_;
    std::string partB_;
    std::string partC_;
};
class Builder {
public:
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;
    virtual Product* getProduct() = 0;
};
class SomeBuilder : public Builder {
public:
    SomeBuilder() { product_ = new Product(); }
    void buildPartA() override { product_->setPartA("part A"); }
    void buildPartB() override { product_->setPartB("part B"); }
    void buildPartC() override { product_->setPartC("part C"); }
    Product* getProduct() override { return product_; }
private:
    Product* product_;
};
class Director {
public:
    void setBuilder(Builder* builder) { builder_ = builder; }
    void construct() {
        builder_->buildPartA();
        builder_->buildPartB();
        builder_->buildPartC();
    }
private:
    Builder* builder_;
};

int main() {
    SomeBuilder* builder = new SomeBuilder();
    Director director;
    director.setBuilder(builder);
    director.construct();
    Product* product = builder->getProduct();
    product->show();
    delete builder;
    delete product;
    return 0;
}
