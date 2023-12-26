/* Your task is to implement the above classes and relationships, create instances of users, 
shopping carts, and products, and demonstrate the relationships. Provide a simple 
demonstration of how the Shopping Cart System works.
You can use simple print statements to simulate the behavior of the program. The goal is 
to demonstrate an understanding of class design, association, aggregation, and 
composition.*/

// You are tasked with designing a simplified shopping cart system in C++.
// Consider the following requirements:

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Product Class:
// Create a class called Product with attributes such as productId, productName, and price.
// Implement a function to display product details
class Product 
{
private:
    int productId;
    string productName;
    double price;

public:
    // Constructor to initialize product details
    Product(int id, const string& name, double p) : productId(id), productName(name), price(p) {}
    
    // Display Fucntion
    void displayProductDetails() const { cout << "Product ID: " << productId << ", Name: " << productName << ", Price: $" << price << endl; }
    
    // Getter for the product price
    double getPrice() const { return price; }
};

// ShoppingCart Class:
// Design a class called ShoppingCart to manage a user's shopping cart.
// Use a dynamic array to store products in the shopping cart.
// Implement functions for adding a product to the cart, displaying all products, and calculating the total cost.
class ShoppingCart 
{
private:
    vector<Product*> products;

public:
    // Destructor to clean up dynamically allocated products
    ~ShoppingCart() 
    {
        for (Product* product : products)
            delete product;
    }

    // Add a product to the shopping cart
    void addProduct(Product* product) 
    {
        products.push_back(product);
        cout << "Product added to the cart." << endl;
    }

    // Display all products in the shopping cart
    void displayAllProducts() const 
    {
        cout << "Products in the cart:" << endl;
        for (const Product* product : products)
            product->displayProductDetails();
    }

    // Calculate the total cost of all products in the shopping cart
    double calculateTotalCost() const 
    {
        double total = 0.0;
        for (const Product* product : products)
            total += product->getPrice();
        return total;
    }
};

// User Class:
// Create a class called User to represent a user of the shopping cart system.
// Each user has a unique userId and may have a shopping cart associated with them.
// Implement a function to display user details
class User 
{
private:
    int userId;
    ShoppingCart* shoppingCart;

public:
    // Constructor to initialize user details
    User(int id) : userId(id), shoppingCart(nullptr) {}

    // Display user details
    void displayUserDetails() const 
    {
        cout << "User ID: " << userId << endl;
        if (shoppingCart != nullptr)
            cout << "User has a shopping cart." << endl;
        else 
            cout << "User does not have a shopping cart." << endl;
     }

    // Associate a shopping cart with the user
    void associateShoppingCart(ShoppingCart* cart) { shoppingCart = cart; }
};

int main() 
{
    // Create products
    Product* product1 = new Product(1, "Laptop", 999.99);
    Product* product2 = new Product(2, "Smartphone", 499.99);
    Product* product3 = new Product(3, "Headphones", 79.99);

    // Create a shopping cart and add products
    ShoppingCart cart;
    cart.addProduct(product1);
    cart.addProduct(product2);

    // Create a user and associate the shopping cart
    User user(123);
    user.associateShoppingCart(&cart);

    // Display user details and shopping cart contents
    user.displayUserDetails();
    cart.displayAllProducts();

    // Calculate and display the total cost
    cout << "Total cost: $" << cart.calculateTotalCost() << endl;

    // Clean up dynamically allocated products
    delete product1;
    delete product2;
    delete product3;

    return 0;
}
