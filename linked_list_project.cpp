#include <iostream>
#include <string>
using namespace std;

struct InventoryItem {
    int itemId;
    string itemName;
    int quantity;
    double price;
    InventoryItem* next;
};

class InventoryManagement {
private:
    InventoryItem* head;

public:
    InventoryManagement() : head(NULL) {}

    void addItem(int id, const string& name, int quantity, double price) {
        InventoryItem* newItem = new InventoryItem{id, name, quantity, price, NULL};
        
        if (head == NULL) {
            head = newItem;
        } else {
            InventoryItem* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newItem;
        }
        cout << "Item added: " << name << " (Quantity: " << quantity << ", Price: $" << price << ")" << endl;
    }

    void updateItem(int id, int newQuantity, double newPrice) {
        InventoryItem* temp = head;
        
        while (temp) {
            if (temp->itemId == id) {
                temp->quantity = newQuantity;
                temp->price = newPrice;
                cout << "Item updated: " << temp->itemName << " (New Quantity: " << newQuantity << ", New Price: $" << newPrice << ")" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Item with ID " << id << " not found in inventory." << endl;
    }

    void removeItem(int id) {
        if (head == NULL) {
            cout << "Inventory is empty. No item to remove." << endl;
            return;
        }

        if (head->itemId == id) {
            InventoryItem* temp = head;
            head = head->next;
            delete temp;
            cout << "Item with ID " << id << " removed from inventory." << endl;
            return;
        }

        InventoryItem* current = head;
        InventoryItem* previous = NULL;

        while (current && current->itemId != id) {
            previous = current;
            current = current->next;
        }

        if (current == NULL) {
            cout << "Item with ID " << id << " not found in inventory." << endl;
            return;
        }

        previous->next = current->next;
        delete current;
        cout << "Item with ID " << id << " removed from inventory." << endl;
    }

    void displayInventory() const {
        if (head == NULL) {
            cout << "Inventory is empty." << endl;
            return;
        }

        InventoryItem* temp = head;
        cout << "\nCurrent Inventory:" << endl;
        while (temp) {
            cout << "ID: " << temp->itemId << ", Name: " << temp->itemName
                 << ", Quantity: " << temp->quantity << ", Price: $" << temp->price << endl;
            temp = temp->next;
        }
    }
};

void displayMenu() {
    cout << "\nInventory Management System Menu:" << endl;
    cout << "1. Add Item" << endl;
    cout << "2. Update Item" << endl;
    cout << "3. Remove Item" << endl;
    cout << "4. Display Inventory" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    InventoryManagement inventory;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                int id, quantity;
                double price;
                string name;

                cout << "Enter Item ID: ";
                cin >> id;
                cout << "Enter Item Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Quantity: ";
                cin >> quantity;
                cout << "Enter Price: ";
                cin >> price;

                inventory.addItem(id, name, quantity, price);
                break;
            }

            case 2: {
                int id, newQuantity;
                double newPrice;

                cout << "Enter Item ID to update: ";
                cin >> id;
                cout << "Enter New Quantity: ";
                cin >> newQuantity;
                cout << "Enter New Price: ";
                cin >> newPrice;

                inventory.updateItem(id, newQuantity, newPrice);
                break;
            }

            case 3: {
                int id;
                cout << "Enter Item ID to remove: ";
                cin >> id;

                inventory.removeItem(id);
                break;
            }

            case 4:
                inventory.displayInventory();
                break;

            case 5:
                cout << "Exiting Inventory Management System. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

