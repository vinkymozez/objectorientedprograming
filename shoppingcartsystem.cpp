#include <iostream>
#include <vector>
#include <map>

class Product {
private:
    std::string name;
    double price;
    int quantity;

public:
    Product(const std::string& name, double price, int quantity) : name(name), price(price), quantity(quantity) {}

    double getPrice() const {
        return price;
    }

    void updateQuantity(int quantity) {
        this->quantity += quantity;
    }

    std::string toString() const {
        return name + " - $" + std::to_string(price) + " - Quantity: " + std::to_string(quantity);
    }

    // Comparison operator for the map key
    bool operator<(const Product& other) const {
        return name < other.name;
    }
};

class ShoppingCart {
private:
    std::map<Product, int> items;

public:
    void addItem(const Product& product, int quantity) {
        if (items.count(product) > 0) {
            int currentQuantity = items[product];
            items[product] = currentQuantity + quantity;
        } else {
            items[product] = quantity;
        }
    }

    void removeItem(const Product& product) {
        items.erase(product);
    }

    void updateItemQuantity(const Product& product, int quantity) {
        if (items.count(product) > 0) {
            items[product] = quantity;
        }
    }

    void displayCartItems() const {
        for (const auto& entry : items) {
            const Product& product = entry.first;
            int quantity = entry.second;
            std::cout << product.toString() << " - Quantity in Cart: " << quantity << std::endl;
        }
    }

    double calculateTotalCost() const {
        double totalCost = 0;
        for (const auto& entry : items) {
            const Product& product = entry.first;
            int quantity = entry.second;
            totalCost += product.getPrice() * quantity;
        }
        return totalCost;
    }
};

int main() {
    // Product management
    std::vector<Product> products;
    int numProducts;
    std::cout << "Enter the number of products: ";
    std::cin >> numProducts;

    for (int i = 0; i < numProducts; ++i) {
        std::string name;
        double price;
        int quantity;

        std::cout << "Enter product name: ";
        std::cin.ignore(); // Ignore the newline character left by previous input
        std::getline(std::cin, name);

        std::cout << "Enter product price: ";
        std::cin >> price;

        std::cout << "Enter product quantity: ";
        std::cin >> quantity;

        products.push_back(Product(name, price, quantity));
    }

    // Display available products
    std::cout << "\nAvailable Products:" << std::endl;
    for (const Product& product : products) {
        std::cout << product.toString() << std::endl;
    }

    // Shopping cart operations
    ShoppingCart cart;

    int choice;
    do {
        std::cout << "\nShopping Cart Operations:"
                  << "\n1. Add item to cart"
                  << "\n2. Remove item from cart"
                  << "\n3. Update item quantity in cart"
                  << "\n4. Display cart items"
                  << "\n5. Calculate total cost"
                  << "\n6. Exit"
                  << "\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int productIndex, quantity;
                std::cout << "Enter the product index to add to cart: ";
                std::cin >> productIndex;

                if (productIndex >= 0 && productIndex < numProducts) {
                    std::cout << "Enter the quantity to add: ";
                    std::cin >> quantity;

                    cart.addItem(products[productIndex], quantity);
                } else {
                    std::cout << "Invalid product index!" << std::endl;
                }
                break;
            }
            case 2: {
                int productIndex;
                std::cout << "Enter the product index to remove from cart: ";
                std::cin >> productIndex;

                if (productIndex >= 0 && productIndex < numProducts) {
                    cart.removeItem(products[productIndex]);
                } else {
                    std::cout << "Invalid product index!" << std::endl;
                }
                break;
            }
            case 3: {
                int productIndex, quantity;
                std::cout << "Enter the product index to update quantity in cart: ";
                std::cin >> productIndex;

                if (productIndex >= 0 && productIndex < numProducts) {
                    std::cout << "Enter the new quantity: ";
                    std::cin >> quantity;

                    cart.updateItemQuantity(products[productIndex], quantity);
                } else {
                    std::cout << "Invalid product index!" << std::endl;
                }
                break;
            }
            case 4:
                std::cout << "\nCart Items:" << std::endl;
                cart.displayCartItems();
                break;
            case 5: {
                double totalCost = cart.calculateTotalCost();
                std::cout << "\nTotal Cost: $" << totalCost << std::endl;
                break;
            }
            case 6:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
        }
    } while (choice != 6);

    return 0;
}
