#include <iostream>
#include <string>

using namespace std;

// Base class to represent a product
class Product {
protected:
    string name;
    string description;
    double price;
    int pid;
public:
    Product(string n, string desc, double p, int pd) : name(n), description(desc), price(p), pid(pd) {}
    virtual ~Product() {} // Virtual destructor for polymorphic behavior
    virtual void disp_prod() const {
        cout << "Name: " << name << endl;
        cout << "Description: " << description << endl;
        cout << "Price: $" << price << endl;
        cout << "Product ID: " << pid << endl;
    }
    double getPrice() const { return price; }
    string getName() const { return name; }
    int getPid() const { return pid; }
};

// Derived class representing furniture products
class Furniture : public Product {
protected:
    static const int NUM_FURNITURE = 7;
    Product* furnitureProducts[NUM_FURNITURE];
public:
    Furniture() : Product("", "", 0, 0) {
        furnitureProducts[0] = new Product("Mattresses", "Comfortable mattresses for a good night's sleep", 200.0, 1);
        furnitureProducts[1] = new Product("Office Chair", "Ergonomic chair for office use", 100.0, 2);
        furnitureProducts[2] = new Product("Study Table", "Spacious study table for work or study", 150.0, 3);
        furnitureProducts[3] = new Product("Pooja Cabinet", "Traditional pooja cabinet for home worship", 180.0, 4);
        furnitureProducts[4] = new Product("Gaming Chair", "Specially designed chair for gaming enthusiasts", 250.0, 5);
        furnitureProducts[5] = new Product("Recliners", "Comfortable recliners for relaxation", 300.0, 6);
        furnitureProducts[6] = new Product("Wardrobes", "Spacious wardrobes for storing clothes", 400.0, 7);
    }
    void disp_prod() const override {
        cout << "Furniture Products:" << endl;
        for (int i = 0; i < NUM_FURNITURE; ++i) {
            furnitureProducts[i]->disp_prod();
            cout << endl;
        }
    }
    Product* getFurnitureProduct(int pid) const {
        for (int i = 0; i < NUM_FURNITURE; ++i) {
            if (furnitureProducts[i]->getPid() == pid) {
                return furnitureProducts[i];
            }
        }
        return nullptr;
    }
};

// Derived class representing stationary products
class Stationary : public Product {
protected:
    static const int NUM_STATIONARY = 9;
    Product* stationaryProducts[NUM_STATIONARY];
public:
    Stationary() : Product("", "", 0, 0) {
        stationaryProducts[0] = new Product("Copier Papers", "High-quality copier papers for printing", 5.0, 8);
        stationaryProducts[1] = new Product("Pens", "Smooth-writing pens for everyday use", 1.0, 9);
        stationaryProducts[2] = new Product("Calculators", "Basic calculators for mathematical calculations", 10.0, 10);
        stationaryProducts[3] = new Product("Geometry Sets", "Geometry sets for school students", 3.0, 11);
        stationaryProducts[4] = new Product("Colour Crayons", "Vibrant colour crayons for art projects", 2.0, 12);
        stationaryProducts[5] = new Product("Pencils", "Standard pencils for writing and drawing", 1.0, 13);
        stationaryProducts[6] = new Product("Penstand", "Penstands for organizing pens and pencils", 4.0, 14);
        stationaryProducts[7] = new Product("Notes", "Small notepads for jotting down quick notes", 3.0, 15);
        stationaryProducts[8] = new Product("Sticky Notes", "Colourful sticky notes for reminders and messages", 2.0, 16);
        stationaryProducts[9] = new Product("Personal Diary", "Personal diaries for journaling and planning", 6.0, 17);
    }
    void disp_prod() const override {
        cout << "Stationary Products:" << endl;
        for (int i = 0; i < NUM_STATIONARY; ++i) {
            stationaryProducts[i]->disp_prod();
            cout << endl;
        }
    }
    Product* getStationaryProduct(int pid) const {
        for (int i = 0; i < NUM_STATIONARY; ++i) {
            if (stationaryProducts[i]->getPid() == pid) {
                return stationaryProducts[i];
            }
        }
        return nullptr;
    }
};

// Class to represent the shopping cart
class ShoppingCart {
private:
    static const int MAX_ITEMS = 100;
    Product* items[MAX_ITEMS];
    int itemCount;
public:
    ShoppingCart() : itemCount(0) {}

    void addItem(const Product& product) {
        if (itemCount < MAX_ITEMS) {
            items[itemCount++] = new Product(product);
            cout << product.getName() << " has been added to your cart." << endl;
        } else {
            cout << "Cart is full. Cannot add more items." << endl;
        }
    }

    void displayCart() const {
        cout << "Your Shopping Cart:" << endl;
        double total = 0.0;
        for (int i = 0; i < itemCount; ++i) {
            items[i]->disp_prod();
            total += items[i]->getPrice();
        }
        cout << "Total: $" << total << endl;
    }

    ~ShoppingCart() {
        for (int i = 0; i < itemCount; ++i) {
            delete items[i];
        }
    }
};

// Class to represent the online store
class OnlineStore {
private:
    Furniture furniture;
    Stationary stationary;
public:
    OnlineStore() {}

    // Function to display available products
    void displayProducts() const {
        cout << "Available Products:" << endl;
        furniture.disp_prod();
        stationary.disp_prod();
    }

    // Function to prompt user for product selection and add it to cart
    void addToCart() {
        char category;
        int pid;

        cout << "Enter the category (F for Furniture, S for Stationary): ";
        cin >> category;

        if (category == 'F' || category == 'f') {
            cout << "Enter the Product ID of the furniture product you want to add to cart: ";
            cin >> pid;
            Product* product = furniture.getFurnitureProduct(pid);
            if (product) {
                cart.addItem(*product);
            } else {
                cout << "Invalid product ID." << endl;
            }
        } else if (category == 'S' || category == 's') {
            cout << "Enter the Product ID of the stationary product you want to add to cart: ";
            cin >> pid;
            Product* product = stationary.getStationaryProduct(pid);
            if (product) {
                cart.addItem(*product);
            } else {
                cout << "Invalid product ID." << endl;
            }
        } else {
            cout << "Invalid category." << endl;
        }
    }

    // Shopping cart object
    ShoppingCart cart;
};

int main() {
    // Create an online store
    OnlineStore store;
    Furniture f;
    Stationary s;
    int cchoice;
    string name;
    string address;
    int fchoice;
    long phone;
    char ch;
    cout<<"Welcome to the online store"<<endl;
    // Prompt user for name, address, and phone number
    cout<<"Enter your name: ";
    cin>>name;
    cout<<"Enter your address: ";
    cin>>address;
    cout<<"Enter your phone number: ";
    cin>>phone;


    // Display available products in the store
    cout<<"Available Categories;"<<endl;
    cout<<"1. Furniture"<<endl;
    cout<<"2. Stationaries"<<endl;
    cout<<"Enter the category you want to buy from: ";
    cin>>cchoice;
    if(cchoice==1)
    {
        f.disp_prod();
    }
    else if(cchoice==2)
    {
        s.disp_prod();
    }



    // Prompt user for product selection and add it to cart
    cout<<"Be careful when adding items to your cart, if u addd once, u cant remove them later"<<endl;
    store.addToCart();
    store.cart.displayCart();
    cout<<"Want to continue shopping? (y/n):";
    cin>>ch;
    while(ch=='y')
    {
        cout<<"Available Categories;"<<endl;
        cout<<"1. Furniture"<<endl;
        cout<<"2. Stationaries"<<endl;
        cout<<"Enter the category you want to buy from: ";
        cin>>cchoice;
        if(cchoice==1)
        {
            f.disp_prod();
        }
        else if(cchoice==2)
        {
            s.disp_prod();
        }
        store.addToCart();
        store.cart.displayCart();
        cout<<"Want to continue shopping? (y/n):";
        cin>>ch;
    }

    

    // Display items in the cart
    cout<<"Final cart:"<<endl;
    store.cart.displayCart();
    cout<<"Press 1 to confirm your orders , 0 to abort the cancel your orders.";
    cin>>fchoice;
    if (fchoice==1)
    {
        cout<<"Dear "<<name<<", your order has been confirmed and it will be delivered at the address,"<<address<<"Please be sure to check your orders before you pay :)))"<<endl<<"Have a NICE DAY!!!!!"<<endl;
    }
    else{
        cout<<"Your orders have been cancelled.";
    }

    return 0;
}
