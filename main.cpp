#include "Schedule.h"
#include <iostream>
#include <string>
#include <fstream>

int main()
{
    Schedule schedule;

    while (true)
    {
        std::string input;
        std::cout << "\nOptions:\n";
        std::cout << "1. Add task\n";
        std::cout << "2. Edit task\n";
        std::cout << "3. Remove task\n";
        std::cout << "4. Print schedule\n";
        std::cout << "5. Quit\n";
        std::cout << "6. Download\n";
        std::cout << "7. Search for Task\n";
        std::cout << "Enter option: ";
        std::getline(std::cin, input);

        if (input == "1")
        {
            std::string description, date, meridian, decider;
            std::cout << "Enter task description: ";
            std::getline(std::cin, description);
            std::cout << "Enter task time (in 0:00 format): ";
            std::getline(std::cin, date);
            while (date.at(1) != ':' && date.at(2) != ':')
            {
                std::cout << "Invalid format. Please try again: ";
                std::getline(std::cin, date);
            }
            std::cout << "AM or PM?: ";
            std::getline(std::cin, meridian);
            schedule.addTask(description, date, meridian);
            std::cout << "\nTask added.\n";
        }
        else if (input == "2")
        {
            std::string indexStr, description, time, meridian;
            int index;
            schedule.sortSchedule();
            std::cout << "Enter task index: ";
            std::getline(std::cin, indexStr);
            index = std::stoi(indexStr);
            std::cout << "Enter new task description: ";
            std::getline(std::cin, description);
            std::cout << "Enter new task time: ";
            std::getline(std::cin, time);
            std::cout << "AM or PM?: ";
            std::getline(std::cin, meridian);
            schedule.editTask(index, description, time, meridian);
            std::cout << "\nTask edited.\n";
        }
        else if (input == "3")
        {
            std::cout << "Tasks:\n";
            schedule.sortSchedule();
            schedule.printSchedule();
            std::string indexStr;
            int index;
            std::cout << "Enter task index to remove: ";
            std::getline(std::cin, indexStr);
            index = std::stoi(indexStr);
            schedule.removeTask(index);
            std::cout << "Task removed.\n";
        }
        else if (input == "4")
        {
            std::cout << "Would you like to sort these tasks in order? y or n: ";
            std::string ans;
            std::getline(std::cin, ans);
            if (ans == "y")
            {
                schedule.sortSchedule();
                schedule.printSchedule();
            }
            else if (ans == "n")
            {
                schedule.printSchedule();
            }
        }
        else if (input == "5")
        {
            break;
        }
        else if (input == "6")
        {
            std::string yesNo;
            std::cout << "Would you like to download your scheduled tasks? (type y or n): ";
            std::getline(std::cin, yesNo);
            if (yesNo == "y")
            {
                std::cout << "\nOkay, setting up file now and sorting your tasks" << std::endl;
                schedule.sortSchedule();
                schedule.outputFile();
            }
            else
            {
                std::cout << "\nsorry, we are still working on this feature" << std::endl;
            }
        }
        else if (input == "7")
        {
            std::string key;
            std::cout << "\nEnter task you are looking for: ";
            std::getline(std::cin, key);
            schedule.searchTask(key);
        }
        else
        {
            std::cout << "Invalid option.\n";
        }
    }

    return 0;
}
