#include <iostream>
#include <string>

using namespace std;

// Base class to represent a product
class Product {
protected:
    string name;
    double price;
    int pid;
public:
    Product(string n, double p, int pd) : name(n), price(p), pid(pd) {}
    virtual ~Product() {} // Virtual destructor for polymorphic behavior
    virtual string getName() const { return name; }
    virtual double getPrice() const { return price; }
    virtual int getPid() const { return pid; }
};

// Derived class representing a clothing product
class Electronics : public Product {
public:
    Electronics(string n, double p, int pd) : Product(n, p, pd) {}
};

// Derived class representing a footwear product
class Footwear : public Product {
public:
    Footwear(string n, double p, int pd) : Product(n, p, pd) {}
};

// Class to represent a shopping cart
class ShoppingCart {
private:
    static const int MAX_ITEMS = 100;
    Product* items[MAX_ITEMS]; // Pointer array to handle polymorphism
    int itemCount;
public:
    ShoppingCart() : itemCount(0) {}

    void addItem(Product* product) {
        if (itemCount < MAX_ITEMS) {
            items[itemCount++] = product;
            cout << product->getName() << " has been added to your cart." << endl;
        } else {
            cout << "Cart is full. Cannot add more items." << endl;
        }
    }

    void displayCart() const {
        cout << "Your Shopping Cart:" << endl;
        double total = 0.0;
        for (int i = 0; i < itemCount; ++i) {
            cout << items[i]->getName() << " - $" << items[i]->getPrice() << endl;
            total += items[i]->getPrice();
        }
        cout << "Total: $" << total << endl;
    }

    void placeOrder() {
        cout << "Your order has been placed. Thank you for shopping with us!" << endl;
        // Clean up memory (delete allocated products)
        for (int i = 0; i < itemCount; ++i) {
            delete items[i];
        }
        itemCount = 0; // Reset itemCount to empty the cart after placing the order
    }
};

// Class to represent the online store
class OnlineStore {
private:
    static const int MAX_PRODUCTS = 100;
    Product* products[MAX_PRODUCTS]; // Pointer array to handle polymorphism
    int productCount;
    ShoppingCart cart;
public:
    OnlineStore() : productCount(0) {}

    void addProduct(Product* product) {
        if (productCount < MAX_PRODUCTS) {
            products[productCount++] = product;
        } else {
            cout << "Maximum products reached. Cannot add more." << endl;
        }
    }

    void displayProducts() const {
        cout << "Available Products:" << endl;
        for (int i = 0; i < productCount; ++i) {
            cout << products[i]->getName() << " - $" << products[i]->getPrice() << endl;
        }
    }

    void addToCart(int index) {
        if (index >= 0 && index < productCount) {
            cart.addItem(products[index]);
        } else {
            cout << "Invalid product index." << endl;
        }
    }

    void viewCart() const {
        cart.displayCart();
    }

    void checkout() {
        cart.displayCart();
        cart.placeOrder();
    }
};

int main() {
    OnlineStore store;

    // Adding some products to the store
    store.addProduct(new Clothing("T-shirt", 20.0, 1));
    store.addProduct(new Clothing("Jeans", 40.0, 2));
    store.addProduct(new Footwear("Shoes", 50.0, 3));

    // Display available products
    store.displayProducts();

    // Add products to cart
    store.addToCart(0); // Add T-shirt
    store.addToCart(2); // Add Shoes

    // View cart
    store.viewCart();

    // Checkout and place order
    store.checkout();

    return 0;
}
