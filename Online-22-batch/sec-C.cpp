#include<iostream>
using namespace std;

class Product{
private:
    string name;
    double price;
public:
    Product(string n, double p) : name(n), price(p) {}
    void display() const {
        cout << "\tProduct: " << name << " - " << "Price: $" << price << endl;
    }
    string getName() const {
        return name;
    }
    double getPrice() const {
        return price;
    }
    Product() : name(""), price(0.0) {}
    Product(string n) : name(n), price(0.0) {}
    ~Product() {
        // Destructor
    }
};

class OnlineStore
{
private:
    Product products[100];
    int productCount = 0;
public:
    void addProduct(const Product& product){
        products[productCount] = product;
        productCount++;
    }

    ~OnlineStore() {
        // Destructor
        // cout << "Destructor called for OnlineStore" << endl;
    }
    void displayProducts(){
        cout << "Available Products in the Store:" << endl;
        for(int i = 0; i < productCount; i++){
            products[i].display();
        }
        cout << "\n";
    }
};

class ShoppingCart{
private:
    Product products[100];
    int productCount = 0;
public:
    void addProduct(const Product& product){
        products[productCount] = product;
        productCount++;
    }

    void removeProduct(const string& productName){
        for(int i = 0; i < productCount; i++){
            if(products[i].getName() == productName){
                cout << "Product '" << products[i].getName() << "' removed successfully.\n" << endl;
                for(int j = i; j < productCount - 1; j++){
                    products[j] = products[j + 1];
                }
                productCount--;
                break;
            }
        }
    }
    void displayCart(){
        cout << "Products in the Shopping Cart:" << endl;
        for(int i = 0; i < productCount; i++){
            products[i].display();
        }
        cout << "\tTotal Cost: $";
        double totalPrice = 0.0;
        for(int i = 0; i < productCount; i++){
            totalPrice += products[i].getPrice();
        }
        cout << totalPrice << endl;
        cout << "\n";
    }

    ~ShoppingCart() {
        // Destructor
        // cout << "Destructor called for ShoppingCart" << endl;
    }
};


int main() {
    OnlineStore store;
    // Add products to the online store
    Product product1("Laptop", 999.99);
    Product product2("Smartphone", 699.99);
    Product product3("Headphones", 99.99);
    store.addProduct(product1);
    store.addProduct(product2);
    store.addProduct(product3);
    // Display available products
    store.displayProducts();
    // Create a new shopping cart
    ShoppingCart cart;
    // Add products to the shopping cart
    cart.addProduct(product1);
    cart.addProduct(product2);
    // Display the shopping cart
    cart.displayCart();
    // Add another product to the cart
    cart.addProduct(product3);
    // Display the updated shopping cart
    cart.displayCart();
    // Remove a product from the cart
    cart.removeProduct("Laptop");
    // Display the updated shopping cart
    cart.displayCart();
    return 0;
}