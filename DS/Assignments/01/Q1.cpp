#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

struct Ticket {
    int ticketID;
    string customerName;
    int priority;  
    string description;
    time_t creationTime;
    string status; 
    time_t closeTime;
    Ticket* next;

    Ticket(int id, string name, int pri, string desc)
        : ticketID(id), customerName(name), priority(pri), description(desc),
          creationTime(time(nullptr)), status("open"), next(nullptr) {}
};

class TicketManager {
    Ticket* head;

public:
    TicketManager() : head(nullptr) {}

    void addTicket(int id, string name, int pri, string desc) {
        Ticket* newTicket = new Ticket(id, name, pri, desc);
        newTicket->next = head;
        head = newTicket;
    }

    void removeTicket(int id) {
        Ticket* temp = head;
        Ticket* prev = nullptr;

        while (temp != nullptr && temp->ticketID != id) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Ticket not found\n";
            return;
        }

        if (prev == nullptr) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
        cout << "Ticket " << id << " removed successfully.\n";
    }

    Ticket* searchTicketByID(int id) {
        Ticket* temp = head;
        while (temp != nullptr) {
            if (temp->ticketID == id) return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    void sortTickets(int criterion) {
        if (!head || !head->next) return; 

        bool swapped;
        Ticket* current;
        Ticket* nextNode = nullptr; 

        do {
            swapped = false;
            current = head;

            while (current->next != nextNode) {
                Ticket* next = current->next;

                bool shouldSwap = false;
                if (criterion == 1 && current->priority > next->priority) {
                    shouldSwap = true;
                } else if (criterion == 2 && current->creationTime > next->creationTime) {
                    shouldSwap = true;
                } else if (criterion == 3 && current->customerName > next->customerName) {
                    shouldSwap = true;
                }

                if (shouldSwap) {
                    std::swap(current->ticketID, next->ticketID);
                    std::swap(current->customerName, next->customerName);
                    std::swap(current->priority, next->priority);
                    std::swap(current->description, next->description);
                    std::swap(current->creationTime, next->creationTime);
                    std::swap(current->status, next->status);
                    std::swap(current->closeTime, next->closeTime);
                    swapped = true;
                }
                current = current->next;
            }
            nextNode = current;
        } while (swapped);
    }

    void displayTickets() {
        Ticket* temp = head;
        while (temp != nullptr) {
            cout << "Ticket ID: " << temp->ticketID
                      << ", Customer Name: " << temp->customerName
                      << ", Priority: " << temp->priority
                      << ", Status: " << temp->status
                      << ", Creation Time: " << temp->creationTime
                      << "\n";
            temp = temp->next;
        }
    }
};

struct Agent {
    int agentID;
    string name;
    vector<int> assignedTickets;
    bool available;

    Agent(int id, string n) : agentID(id), name(n), available(true) {}
};

class AgentManager {
    vector<Agent> agents;
    int maxTicketsPerAgent = 5; 

public:
    void addAgent(int id, string name) {
        agents.push_back(Agent(id, name));
    }

    void assignTicket(Ticket& ticket) {
        for (Agent& agent : agents) {
            if (agent.available && agent.assignedTickets.size() < maxTicketsPerAgent) {
                agent.assignedTickets.push_back(ticket.ticketID);
                ticket.status = "assigned";
                if (agent.assignedTickets.size() >= maxTicketsPerAgent) {
                    agent.available = false;
                }
                cout << "Ticket " << ticket.ticketID << " assigned to Agent " << agent.name << "\n";
                return;
            }
        }
        cout << "No available agents for Ticket " << ticket.ticketID << "\n";
    }

    void displayAgentStatus() {
        for (const Agent& agent : agents) {
            cout << "Agent ID: " << agent.agentID << ", Name: " << agent.name
                      << ", Assigned Tickets: " << agent.assignedTickets.size()
                      << ", Available: " << (agent.available ? "Yes" : "No") << "\n";
        }
    }
};

class TicketLogManager {
    stack<int> resolutionLog;  
    queue<Ticket*> pendingQueue; 

public:
    void logResolvedTicket(int ticketID) {
        resolutionLog.push(ticketID);
    }

    void addPendingTicket(Ticket* ticket) {
        pendingQueue.push(ticket);
    }

    void viewResolutionLog() {
        stack<int> temp = resolutionLog;
        while (!temp.empty()) {
            cout << "Resolved Ticket ID: " << temp.top() << "\n";
            temp.pop();
        }
    }
};

void TicketManager::sortTicketsByPriority() {
    if (!head) return;

    Ticket* current;
    Ticket* next;
    bool swapped;

    do {
        swapped = false;
        current = head;
        while (current->next != nullptr) {
            next = current->next;
            if (current->priority > next->priority) {
                swap(current->priority, next->priority);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

int main() {
    TicketManager ticketManager;
    AgentManager agentManager;
    TicketLogManager logManager;

    ticketManager.addTicket(1, "Alice", 1, "Password reset issue");
    ticketManager.addTicket(2, "Bob", 2, "Network connectivity issue");
    
    agentManager.addAgent(1, "Agent IT");
    agentManager.addAgent(2, "Agent Admin");

    Ticket* ticket = ticketManager.searchTicketByID(1);
    if (ticket) {
        agentManager.assignTicket(*ticket);
        logManager.logResolvedTicket(ticket->ticketID);
    }

    logManager.viewResolutionLog();
    agentManager.displayAgentStatus();

    return 0;
}

