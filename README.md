# Local-Train-Booking-System
Local Train Ticketing System (C++)
This is a simple Local Train Ticketing System implemented in C++. The system allows users to book and cancel train tickets, as well as view information about available trains and booked tickets. It is designed with a basic menu-driven interface for easy interaction.

Features:
Train Management: The system allows you to add new trains, each with its own details such as train number, name, destination, and available seats.

Ticket Booking: Users can book tickets for available trains. The system checks if there are seats available before booking.

Ticket Cancellation: Users can cancel their booked tickets and free up seats for others.

View Bookings: You can view details of all available trains and tickets that have been booked.

Components:
Train Class: Represents the train details, including train number, train name, destination, and available seats.

Ticket Class: Represents a ticket that is associated with a specific passenger and a booked train.

TicketingSystem Class: The core of the program that handles operations like adding trains, booking tickets, canceling tickets, and displaying information about trains and bookings.

How to Use:
Clone the repository.

Compile the train_ticketing_system.cpp file with any standard C++ compiler (e.g., g++ train_ticketing_system.cpp -o train_ticketing_system).

Run the executable (./train_ticketing_system or train_ticketing_system.exe on Windows).

Follow the on-screen prompts to interact with the system.

Example Usage:
text
Copy
Local Train Ticketing System Menu:
1. View All Trains
2. Book a Ticket
3. Cancel a Ticket
4. View All Tickets
5. Exit
Enter your choice: 1
Example Output:
text
Copy
Train Number: 101
Train Name: Express 101
Destination: New York
Available Seats: 100
Extensions:
User Authentication: Add login functionality for users.

Persistence: Implement file handling to save and load train and ticket data.

Graphical Interface: Develop a GUI for better user interaction.
