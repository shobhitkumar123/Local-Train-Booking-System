#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Train {
public:
    int trainNumber;
    string trainName;
    string destination;
    int availableSeats;

    Train(int num, string name, string dest, int seats) {
        trainNumber = num;
        trainName = name;
        destination = dest;
        availableSeats = seats;
    }

    void displayTrainInfo() {
        cout << "Train Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Destination: " << destination << endl;
        cout << "Available Seats: " << availableSeats << endl;
    }
};
class Ticket {
public:
    int ticketID;
    string passengerName;
    Train* bookedTrain;

    Ticket(int id, string name, Train* train) {
        ticketID = id;
        passengerName = name;
        bookedTrain = train;
    }

    void displayTicketInfo() {
        cout << "Ticket ID: " << ticketID << endl;
        cout << "Passenger Name: " << passengerName << endl;
        bookedTrain->displayTrainInfo();
    }
};
class TicketingSystem {
private:
    vector<Train> trains;
    vector<Ticket> tickets;
    int ticketIDCounter = 1;

public:
    void addTrain(int trainNumber, string trainName, string destination, int seats) {
        Train newTrain(trainNumber, trainName, destination, seats);
        trains.push_back(newTrain);
    }

    void bookTicket(string passengerName, int trainNumber) {
        bool found = false;
        for (auto &train : trains) {
            if (train.trainNumber == trainNumber && train.availableSeats > 0) {
                Ticket newTicket(ticketIDCounter++, passengerName, &train);
                tickets.push_back(newTicket);
                train.availableSeats--;
                cout << "Ticket booked successfully for " << passengerName << " on Train " << trainNumber << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "No available seats on the train or train number not found." << endl;
        }
    }
    void cancelTicket(int ticketID) {
        bool found = false;
        for (auto it = tickets.begin(); it != tickets.end(); ++it) {
            if (it->ticketID == ticketID) {
                it->bookedTrain->availableSeats++;
                tickets.erase(it);
                cout << "Ticket with ID " << ticketID << " has been canceled successfully." << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Ticket with ID " << ticketID << " not found." << endl;
        }
    }
    void viewTickets() {
        if (tickets.empty()) {
            cout << "No tickets booked." << endl;
        } else {
            for (auto &ticket : tickets) {
                ticket.displayTicketInfo();
                cout << endl;
            }
        }
    }

    void viewTrains() {
        if (trains.empty()) {
            cout << "No trains available." << endl;
        } else {
            for (auto &train : trains) {
                train.displayTrainInfo();
                cout << endl;
            }
        }
    }
};

int main() {
    TicketingSystem system;

    system.addTrain(101, "Express 101", "Kanpur", 100);
    system.addTrain(102, "SuperFast 102", "Dehli", 50);
    system.addTrain(103, "Local 103", "Kannauj", 200);

    int choice;
    do {
        cout << "\nLocal Train Ticketing System Menu:\n";
        cout << "1. View All Trains\n";
        cout << "2. Book a Ticket\n";
        cout << "3. Cancel a Ticket\n";
        cout << "4. View All Tickets\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                system.viewTrains();
                break;
            }
            case 2: {
                string passengerName;
                int trainNumber;
                cout << "Enter Passenger Name: ";
                cin.ignore();
                getline(cin, passengerName);
                cout << "Enter Train Number to Book: ";
                cin >> trainNumber;
                system.bookTicket(passengerName, trainNumber);
                break;
            }
            case 3: {
                int ticketID;
                cout << "Enter Ticket ID to Cancel: ";
                cin >> ticketID;
                system.cancelTicket(ticketID);
                break;
            }
            case 4: {
                system.viewTickets();
                break;
            }
            case 5: {
                cout << "Exiting the system...\n";
                break;
            }
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
