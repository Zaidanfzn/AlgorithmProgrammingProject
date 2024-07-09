# D'WASH Project

## Program Description

**D'Wash** is a C-based program designed to facilitate customers in using vehicle washing services. The program features two main roles:

- **Admin**: The provider and manager of the vehicle washing services.
- **User**: The customer who uses the vehicle washing services.

## Program Features

#### Admin Features
- **Admin Login**: Access admin features with a username and password.
- **View Customer Data**: Display registered customer data.
- **Add Vehicle Categories**: Add vehicle types (at least 3 types, e.g., car, motorcycle, rickshaw, public minivan).
- **Add Prices and Service Types**: Add prices and types of services based on vehicle categories (at least 3 services).
- **View and Update Wash Progress**: Monitor and update the status of customer washes.
- **Return to Main Menu**: Navigate back to the main menu.
- **Log Out**: Log out from the admin account.

#### User Features
- **View HELPDESK**: Application usage guide.
- **User Registration**: Create an account with email, full name, phone number, address, username, and password.
- **User Login**: Access user account (maximum of 2 login attempts, with a 3-second delay between attempts).
- **Forgot Password**: Reset password using a specific keyword.
- **View Services by Lowest Price**: Display services sorted by the lowest price.
- **Place an Order**: Order a vehicle wash service.
- **View Wash Progress**: Check the status of the vehicle wash.
- **Pay for Service**: Pay for the service after the wash is completed. If the payment amount matches the order data, the payment is successful.
- **Delete Order Data After Payment**: Automatically delete order data after successful payment.
- **Return to Main Menu**: Navigate back to the main menu.
- **Log Out**: Log out from the user account.

## How to Use the Program

1. **Compile the Program**
   ```
   gcc -o dwash dwash.c
   ```

2. **Run the Program**
   ```
   ./dwash
   ```

3. **Navigate the Menu**
   - Follow on-screen instructions to choose between admin and user menus.

4. **Login and Registration**
   - Admin and user must log in to access features. New users must register first.

## Directory Structure

```
D'WASH/
└── dwash.c        
README.md      
```

Enjoy using D'Wash!
