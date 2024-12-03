#include <iostream>
#include <vector>
#include <algorithm>

class Product {
public:
    std::string name;
    std::string category;
    double price;

    Product(std::string n, std::string c, double p) : name(n), category(c), price(p) {}
};

void addProduct(std::vector<Product>& products, const Product& product) {
    products.push_back(product);
}

void printProducts(const std::vector<Product>& products) {
    for (const auto& product : products) {
        std::cout << "Name: " << product.name << ", Category: " << product.category << ", Price: " << product.price << std::endl;
    }
}

void filterByCategory(const std::vector<Product>& products, const std::string& category) {
    for (const auto& product : products) {
        if (product.category == category) {
            std::cout << "Name: " << product.name << ", Category: " << product.category << ", Price: " << product.price << std::endl;
        }
    }
}

void sortByPrice(std::vector<Product>& products) {
    std::sort(products.begin(), products.end(), [](const Product& a, const Product& b) {
        return a.price < b.price;
    });
}

int main() {
    std::vector<Product> products;

    addProduct(products, Product("Laptop", "Electronics", 999.99));
    addProduct(products, Product("Phone", "Electronics", 499.99));
    addProduct(products, Product("Shirt", "Clothing", 29.99));

    std::cout << "All products:" << std::endl;
    printProducts(products);

    std::cout << "\nFiltered by category 'Electronics':" << std::endl;
    filterByCategory(products, "Electronics");

    std::cout << "\nProducts sorted by price:" << std::endl;
    sortByPrice(products);
    printProducts(products);

    return 0;
}
