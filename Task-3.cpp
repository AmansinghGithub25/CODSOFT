#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class TaskManager {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        tasks.emplace_back(description);
        std::cout << "Task added: " << description << std::endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks available." << std::endl;
            return;
        }

        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].description 
                      << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]" << std::endl;
        }
    }

    void markTaskCompleted(size_t index) {
        if (index < 1 || index > tasks.size()) {
            std::cout << "Invalid task number." << std::endl;
            return;
        }

        tasks[index - 1].completed = true;
        std::cout << "Task marked as completed: " << tasks[index - 1].description << std::endl;
    }

    void removeTask(size_t index) {
        if (index < 1 || index > tasks.size()) {
            std::cout << "Invalid task number." << std::endl;
            return;
        }

        std::cout << "Task removed: " << tasks[index - 1].description << std::endl;
        tasks.erase(tasks.begin() + index - 1);
    }
};

void displayMenu() {
    std::cout << "\nTask Manager Menu:\n"
              << "1. Add Task\n"
              << "2. View Tasks\n"
              << "3. Mark Task as Completed\n"
              << "4. Remove Task\n"
              << "5. Exit\n"
              << "Choose an option: ";
}

int main() {
    TaskManager taskManager;
    int choice;
    std::string description;
    size_t taskNumber;

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter task description: ";
                std::cin.ignore(); // To ignore the newline left in the buffer
                std::getline(std::cin, description);
                taskManager.addTask(description);
                break;
            case 2:
                taskManager.viewTasks();
                break;
            case 3:
                std::cout << "Enter task number to mark as completed: ";
                std::cin >> taskNumber;
                taskManager.markTaskCompleted(taskNumber);
                break;
            case 4:
                std::cout << "Enter task number to remove: ";
                std::cin >> taskNumber;
                taskManager.removeTask(taskNumber);
                break;
            case 5:
                std::cout << "Exiting the Task Manager. Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
        }
    }

    return 0;
}

