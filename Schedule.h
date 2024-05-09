#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
#include <vector>
#include <fstream>

class Task
{
public:
    Task(std::string description, std::string time, std::string meridian);
    std::string getDescription();
    std::string getTime();
    std::string getMeridian();
    void setDescription(std::string description);
    void setTime(std::string time);
    void setMeridian(std::string meridian);
    int numTime();

private:
    std::string m_description;
    std::string m_time;
    std::string m_meridian;
};

class Schedule
{
public:
    std::vector<Task> getTasks();
    void addTask(std::string description, std::string time, std::string meridian);
    void editTask(int index, std::string description, std::string time, std::string meridian);
    void removeTask(int index);
    void printSchedule();
    void sortSchedule();
    void outputFile();
    void searchTask(std::string keyword);

private:
    std::vector<Task> m_tasks;
};

#endif
