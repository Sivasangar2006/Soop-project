#include <iostream>
#include <string>

using namespace std;

// Class to represent a product
class Product {
private:
    string name;
    double price;
public:
    Product(string n, double p) : name(n), price(p) {}
    string getName() const { return name; }
    double getPrice() const { return price; }
};

// Class to represent a shopping cart
class ShoppingCart {
private:
    static const int MAX_ITEMS = 100;
    Product items[MAX_ITEMS];
    int itemCount;
public:
    ShoppingCart() : itemCount(0) {}

    void addItem(const Product& product) {
        if (itemCount < MAX_ITEMS) {
            items[itemCount++] = product;
            cout << product.getName() << " has been added to your cart." << endl;
        } else {
            cout << "Cart is full. Cannot add more items." << endl;
        }
    }

    void displayCart() const {
        cout << "Your Shopping Cart:" << endl;
        double total = 0.0;
        for (int i = 0; i < itemCount; ++i) {
            cout << items[i].getName() << " - $" << items[i].getPrice() << endl;
            total += items[i].getPrice();
        }
        cout << "Total: $" << total << endl;
    }

    void placeOrder() {
        cout << "Your order has been placed. Thank you for shopping with us!" << endl;
        itemCount = 0; // Reset itemCount to empty the cart after placing the order
    }
};

// Class to represent the online store
class OnlineStore {
private:
    static const int MAX_PRODUCTS = 100;
    Product products[MAX_PRODUCTS];
    int productCount;
    ShoppingCart cart;
public:
    OnlineStore() : productCount(0) {}

    void addProduct(const Product& product) {
        if (productCount < MAX_PRODUCTS) {
            products[productCount++] = product;
        } else {
            cout << "Maximum products reached. Cannot add more." << endl;
        }
    }

    void displayProducts() const {
        cout << "Available Products:" << endl;
        for (int i = 0; i < productCount; ++i) {
            cout << products[i].getName() << " - $" << products[i].getPrice() << endl;
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
    store.addProduct(Product("T-shirt", 20.0));
    store.addProduct(Product("Jeans", 40.0));
    store.addProduct(Product("Shoes", 50.0));

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
