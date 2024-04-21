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
        cout << "Name: " << name <<endl;
        cout << "Description: " << description <<endl;
        cout << "Price: ₹ " << price <<endl;
        cout << "Product ID: " << pid << endl;
    }
    double getPrice() const { return price; }
    string getName() const { return name; }
    int getPid() const { return pid; }
};

// Derived class representing furniture products
class Furniture : public Product 
{
protected:
    static const int NUM_FURNITURE = 7;
    Product* furnitureProducts[NUM_FURNITURE];
public:
    Furniture() : Product("", "", 0, 0) {
        furnitureProducts[0] = new Product("Mattresses", "Comfortable mattresses for a good night's sleep", 16000.0, 1);
        furnitureProducts[1] = new Product("Office Chair", "Ergonomic chair for office use", 8000.0, 2);
        furnitureProducts[2] = new Product("Study Table", "Spacious study table for work or study", 12000.0, 3);
        furnitureProducts[3] = new Product("Pooja Cabinet", "Traditional pooja cabinet for home worship", 14400.0, 4);
        furnitureProducts[4] = new Product("Gaming Chair", "Specially designed chair for gaming enthusiasts", 20000.0, 5);
        furnitureProducts[5] = new Product("Recliners", "Comfortable recliners for relaxation", 24000.0, 6);
        furnitureProducts[6] = new Product("Wardrobes", "Spacious wardrobes for storing clothes", 32000.0, 7);
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
class Stationary : public Product 
{
protected:
    static const int NUM_STATIONARY = 9;
    Product* stationaryProducts[NUM_STATIONARY];
public:
    Stationary() : Product("", "", 0, 0) {
        stationaryProducts[0] = new Product("Copier Papers", "High-quality copier papers for printing", 400.0, 8);
        stationaryProducts[1] = new Product("Pens", "Smooth-writing pens for everyday use", 80.0, 9);
        stationaryProducts[2] = new Product("Calculators", "Basic calculators for mathematical calculations", 800.0, 10);
        stationaryProducts[3] = new Product("Geometry Sets", "Geometry sets for school students", 240.0, 11);
        stationaryProducts[4] = new Product("Colour Crayons", "Vibrant colour crayons for art projects", 160.0, 12);
        stationaryProducts[5] = new Product("Pencils", "Standard pencils for writing and drawing", 80.0, 13);
        stationaryProducts[6] = new Product("Penstand", "Penstands for organizing pens and pencils", 320.0, 14);
        stationaryProducts[7] = new Product("Notes", "Small notepads for jotting down quick notes", 240.0, 15);
        stationaryProducts[8] = new Product("Sticky Notes", "Colourful sticky notes for reminders and messages", 160.0, 16);
        stationaryProducts[9] = new Product("Personal Diary", "Personal diaries for journaling and planning", 480.0, 17);
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

// Derived class to represent electronics
class Electronics : public Product
{
protected:
    static const int NUM_ELECTRONICS = 12;
    Product* electronics[NUM_ELECTRONICS];
public:
    Electronics() : Product("","",0,0)
    {
        electronics[0]= new Product("Redmi 13C Mobile Phone","Highest selling 5G smartphone",10499.0, 18);
        electronics[1]= new Product("Samsung Galaxy M14 5G mobile phone","Segment's only 6000 mAh 5G SP",12490.0, 19);
        electronics[2]= new Product("Dell 14 Laptop","13th Gen Intel Core i5", 46990.0, 20);
        electronics[3]= new Product("HP 15s laptop", "12th Gen Intel Core i5", 54990.0, 21);
        electronics[4]= new Product("boAt airpods 141", "42H playtime and ENx tech", 1299.0, 22);
        electronics[5]= new Product("Noise Buds N1 airpods", "40 Hours of playtime and Quad Mic with ENC", 1299.0, 23);
        electronics[6]= new Product("Apple iPad 10th Gen tablet", "A14 Bionic Chip and Liquid retina display", 36900.0, 24);
        electronics[7]= new Product("Samsung S6 Lite tablets", "S-Pen in box and AKG Tuned dolby atmos", 19999.0, 25);
        electronics[8]= new Product("Noise Quad Cell smartwatch", "1.81' Display and AI Voice Assistance", 1299.0, 26);
        electronics[9]= new Product("boAt Wave Call 2 smartwatch", "1.83' HD Display and DIY Watch Face Studio", 1099.0, 27);
        electronics[10]= new Product("Amazon Echo Pop", "Smart Speaker with Alexa and Bluetooth", 3999.0, 28);
        electronics[11]= new Product("Amazon Echo Dot 4th Gen with clock", "Smart Speaker with powerful bass", 5499.0, 29);
    }
     void disp_prod() const override 
    {
        cout << "Electronics:" << endl;
        for (int i = 0; i < NUM_ELECTRONICS; ++i) 
        {
            electronics[i]->disp_prod();
            cout << endl;
        }
    }        
    Product* getElectronic(int pid) const 
    {
        for (int i = 0; i < NUM_ELECTRONICS; ++i) {
            if (electronics[i]->getPid() == pid) {
                return electronics[i];
            }
        }
        return nullptr;
    }
};

//Derived class representing books
class Books: public Product
{
protected:
    static const int NUM_BOOKS = 11;
    Product* books[NUM_BOOKS];
public:
    Books(): Product("","",0,0)
    {
        books[0]= new Product("It ends with us", "By Colleen Hoover", 280.0, 30);
        books[1]= new Product("The temporary roomie", "By Sarah Adams", 180.0,31);
        books[2]= new Product("Don't believe everything you think", "By Joseph Nguyen", 179.0, 32);
        books[3]= new Product("The wealth money can't buy", "By Robin Sharma", 349.0, 33);
        books[4]= new Product("The mountain is you", "By Brianna Wiest", 289.0, 34);
        books[5]= new Product("And then there were none", "By Agatha Christie", 268.0, 35);
        books[6]= new Product("As good as dead", "By Holly Jackson", 381.0, 36);
        books[7]= new Product("The Psychology of money", "By Morgan Housel", 275.0, 37);
        books[8]= new Product("The power of your subconscious mind", "By Joseph Murphy", 149.0, 38);
        books[9]= new Product("The Alchemist", "By Paulo Coelho", 301.0, 39);
        books[10]= new Product("The blue umbrella", "By Ruskin Bond", 145.0, 40);
    }
    void disp_prod() const override 
    {
        cout << "Books:" << endl;
        for (int i = 0; i < NUM_BOOKS; ++i) 
        {
            books[i]->disp_prod();
            cout << endl;
        }
    }        
    Product* getBook(int pid) const 
    {
        for (int i = 0; i < NUM_BOOKS; ++i) {
            if (books[i]->getPid() == pid) {
                return books[i];
            }
        }
        return nullptr;
    }
};

//Derived class representing appliances
class Appliances: public Product
{
protected:
    static const int NUM_APPLIANCES = 10;
    Product* appliances[NUM_APPLIANCES];
public:
    Appliances(): Product("","",0,0)
    {
        appliances[0]= new Product("Samsung 301 L 3 star refigerator", "Convertible 5 in 1 technology", 34990.0, 41);
        appliances[1]= new Product("Godrej 564 L 3 star refrigerator", "Multi air flow system", 56990.0, 42);
        appliances[2]= new Product("Panasonic 1.5 ton 5 star", "7 in 1 convertible smart AC", 44990.0, 43);
        appliances[3]= new Product("LG 1 ton 4 star", "Viraat mode for instant cooling", 35990.0, 44);
        appliances[4]= new Product("OnePlus 65' Q series", "4K QLED Smart google TV", 75999.0, 45);
        appliances[5]= new Product("Xiaomi 43' X series", "4K UHD Smart google TV", 25499.0, 46);
        appliances[6]= new Product("Smasung 8 kg 5 star", "Fully-Automatic front load washing machine", 36990.0, 47);
        appliances[7]= new Product("Haier 8 kg 5 star", "Fully-Automatic top load washing machine", 23850.0, 48);
        appliances[8]= new Product("Samsung 28 L", "Convection microwave oven with curd making", 12490.0, 49);
        appliances[9]= new Product("Faber Instacook20_S", "Digital Standalone 20 L microwave oven", 6790.0, 50);
    }
    void disp_prod() const override 
    {
        cout << "Appliances:" << endl;
        for (int i = 0; i < NUM_APPLIANCES; ++i) 
        {
            appliances[i]->disp_prod();
            cout << endl;
        }
    }        
    Product* getAppliance(int pid) const 
    {
        for (int i = 0; i < NUM_APPLIANCES; ++i) {
            if (appliances[i]->getPid() == pid) {
                return appliances[i];
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
        cout << "\nYour Shopping Cart:" << endl;
        double total = 0.0;
        for (int i = 0; i < itemCount; ++i) {
            items[i]->disp_prod();
            total += items[i]->getPrice();
        }
        cout << "\nTotal: ₹" << total << endl;
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
    Electronics electronic;
    Books book;
    Appliances appliance;
public:
    OnlineStore() {}

    // Function to prompt user for product selection and add it to cart
    void addToCart() {
        char category;
        int pid;

        cout << "Enter the category (F for Furniture, S for Stationary, E for Electronics, B for Books, A for Appliances): ";
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
        } 
        else if (category == 'S' || category == 's') {
            cout << "Enter the Product ID of the stationary product you want to add to cart: ";
            cin >> pid;
            Product* product = stationary.getStationaryProduct(pid);
            if (product) {
                cart.addItem(*product);
            } else {
                cout << "Invalid product ID." << endl;
            }
        } 
        else if (category == 'E' || category == 'e') {
            cout << "Enter the Product ID of the electronic item you want to add to cart: ";
            cin >> pid;
            Product* product = electronic.getElectronic(pid);
            if (product) {
                cart.addItem(*product);
            } else {
                cout << "Invalid product ID." << endl;
            }
        }
         else if (category == 'B' || category == 'b') {
            cout << "Enter the Product ID of the book you want to add to cart: ";
            cin >> pid;
            Product* product = book.getBook(pid);
            if (product) {
                cart.addItem(*product);
            } else {
                cout << "Invalid product ID." << endl;
            }
        }
        else if (category == 'A' || category == 'a') {
            cout << "Enter the Product ID of the appliance you want to add to cart: ";
            cin >> pid;
            Product* product = appliance.getAppliance(pid);
            if (product) {
                cart.addItem(*product);
            } else {
                cout << "Invalid product ID." << endl;
            }
        }      
        else {
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
    Electronics e;
    Books b;
    Appliances a;
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
    cout<<"Available Categories:"<<endl;
    cout<<"1. Furniture"<<endl;
    cout<<"2. Stationaries"<<endl;
    cout<<"3. Electronics"<<endl;
    cout<<"4. Books"<<endl;
    cout<<"5. Appliances"<<endl;
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
    else if(cchoice==3)
    {
        e.disp_prod();
    }
    else if(cchoice==4)
    {
        b.disp_prod();
    }
    else if(cchoice==5)
    {
        a.disp_prod();
    }
    
    // Prompt user for product selection and add it to cart
    cout<<"! ! ! Be careful when adding items to your cart, if you add once, you can't remove them later ! ! !"<<endl;
    store.addToCart();
    store.cart.displayCart();
    cout<<"Want to continue shopping? (y/n):";
    cin>>ch;
    while(ch=='y')
    {
        cout<<"Available Categories:"<<endl;
        cout<<"1. Furniture"<<endl;
        cout<<"2. Stationaries"<<endl;
        cout<<"3. Electronics"<<endl;
        cout<<"4. Books"<<endl;
        cout<<"5. Appliances"<<endl;
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
        else if(cchoice==3)
        {
            e.disp_prod();
        }
        else if(cchoice==4)
        {
            b.disp_prod();
        }
        else if(cchoice==5)
        {
            a.disp_prod();
        }
        
        store.addToCart();
        store.cart.displayCart();
        cout<<"Want to continue shopping? (y/n):";
        cin>>ch;
    }

    // Display items in the cart
    cout<<"Final cart:"<<endl;
    store.cart.displayCart();
    cout<<"Press 1 to confirm your orders , 0 to cancel your orders."<<endl;
    cout<<"Your choice:"<<endl;
    cin>>fchoice;
    if (fchoice==1)
    {
        cout<<"Dear "<<name<<", your order has been confirmed and it will be delivered at the address,"<<address<<"\nPlease be sure to check your orders before you pay :)))"<<endl<<"Have a NICE DAY!!!!!"<<endl;
    }
    else{
        cout<<"Your orders have been cancelled.";
    }

    return 0;
}
