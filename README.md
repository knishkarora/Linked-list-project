# Inventory Management System (C++)

## Overview
This Inventory Management System is a simple console-based C++ application that allows users to manage inventory items by adding, updating, removing, and displaying them. The system is built using **linked lists** to efficiently store and manage inventory data.

## Features
- **Add Item**: Allows users to add new inventory items with an ID, name, quantity, and price.
- **Update Item**: Modifies the quantity and price of an existing inventory item.
- **Remove Item**: Deletes an inventory item from the system using its ID.
- **Display Inventory**: Prints the list of all inventory items in the system.
- **Menu-Driven Interface**: Users can interact with the system through a simple command-line menu.

## Data Structures Used
### 1. **Singly Linked List**
- The inventory items are stored as nodes in a **singly linked list**, where each node contains:
  - `itemId` (integer) - Unique identifier for an item.
  - `itemName` (string) - Name of the inventory item.
  - `quantity` (integer) - Available stock of the item.
  - `price` (double) - Cost per unit of the item.
  - `next` (pointer) - Pointer to the next item in the list.

- The linked list provides **efficient dynamic memory management**, as new items can be added or removed without the need for contiguous memory allocation, unlike arrays.

### 2. **Pointers**
- Pointers are used to navigate and modify the linked list.
- Dynamic memory allocation (`new` and `delete`) ensures that memory is allocated only when needed, reducing wastage.

## Code Structure
- `InventoryItem` (struct): Defines the structure of an inventory item.
- `InventoryManagement` (class): Implements the linked list and provides methods for inventory operations.
- `displayMenu()` (function): Displays the menu options to the user.
- `main()` (function): Handles user input and executes corresponding operations.

## Example Usage
```
Inventory Management System Menu:
1. Add Item
2. Update Item
3. Remove Item
4. Display Inventory
5. Exit
Enter your choice: 1
Enter Item ID: 101
Enter Item Name: Laptop
Enter Quantity: 10
Enter Price: 750.99
Item added: Laptop (Quantity: 10, Price: $750.99)
```

## Future Enhancements
- Implement **doubly linked list** for more efficient deletion.
- Use **hashing** for quick item lookups.
- Store inventory data in a **file or database** for persistence.
- Add a **graphical user interface (GUI)** for better user experience.

## License
This project is open-source and available under the MIT License.

