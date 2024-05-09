#include "Schedule.h"
#include <iostream>
#include <fstream>

Task::Task(std::string description, std::string time, std::string meridian)
    : m_description(description), m_time(time), m_meridian(meridian)
{
}

std::string Task::getDescription()
{
    return m_description;
}

std::string Task::getTime()
{
    return m_time;
}

std::string Task::getMeridian()
{
    return m_meridian;
}

void Task::setDescription(std::string description)
{
    m_description = description;
}

void Task::setTime(std::string time)
{
    m_time = time;
}

void Task::setMeridian(std::string meridian)
{
    m_meridian = meridian;
}

std::vector<Task> Schedule::getTasks() {
    return m_tasks;
}

void Schedule::addTask(std::string description, std::string time, std::string meridian)
{
    Task task(description, time, meridian);
    m_tasks.push_back(task);
}

void Schedule::editTask(int index, std::string description, std::string time, std::string meridian)
{
    m_tasks[index].setDescription(description);
    m_tasks[index].setTime(time);
    m_tasks[index].setMeridian(meridian);
}

void Schedule::removeTask(int index)
{
    m_tasks.erase(m_tasks.begin() + index);
}

/*std::int Task::numTime(Task temp)
{
    std::string str = temp->getTime;
    std::int val1 = str.at(0);
    std::int val2 = str.at(2);
    std::int val3 = str.at(3);
    std::int newVal = val1 * 60;
    newVal += (val2 * 10);
    newVal += (val3);

    return newVal;

}*/

/*int Task::numTime()
{
    int newVal = 0;
    if (m_time.at(1) == ':')
    {
        int val1 = m_time.at(0);
        int val2 = m_time.at(2);
        int val3 = m_time.at(3);
        newVal = val1 * 60;
        newVal += (val2 * 10);
        newVal += (val3);
    }
    else if (m_time.at(2) == ':')
    {
        int val1;
        if (m_time.at(0) == 1 && m_time.at(1) == 2) {
            return (m_time.at(3) * 10) + m_time.at(4);
        }
        else {
            val1 = (m_time.at(0) * 10) + m_time.at(1);
            int val2 = m_time.at(3);
            int val3 = m_time.at(4);
            newVal = (val1 * 60);
            newVal += (val2 * 10);
            newVal += (val3);
        }
    }

    return newVal;
}*/

int Task::numTime()
{
    int newVal = 0;
    if (m_time.substr(0, 2) == "12" && m_time.substr(2, 1) == ":")
    {
        newVal = (m_time.at(3) - '0') * 10 + (m_time.at(4) - '0');
    }
    else if (m_time.at(1) == ':')
    {
        int val1 = m_time.at(0) - '0';
        int val2 = m_time.at(2) - '0';
        int val3 = m_time.at(3) - '0';
        newVal = val1 * 60;
        newVal += (val2 * 10);
        newVal += (val3);
    }
    else if (m_time.at(2) == ':')
    {
        int val1 = (m_time.at(0) - '0') * 10 + (m_time.at(1) - '0');
        int val2 = m_time.at(3) - '0';
        int val3 = m_time.at(4) - '0';
        newVal = (val1 * 60);
        newVal += (val2 * 10);
        newVal += (val3);
    }

    return newVal;
}

void Schedule::printSchedule()
{
    if (m_tasks.size() == 0)
    {
        std::cout << "No tasks to output" << std::endl;
    }
    else
    {
        std::cout << "\nSchedule:\n";
        for (int i = 0; i < m_tasks.size(); i++)
        {
            if (m_tasks[i].getMeridian() == "AM" || m_tasks[i].getMeridian() == "am")
            {
                std::cout << "- " << m_tasks[i].getDescription() << " at " << m_tasks[i].getTime() << m_tasks[i].getMeridian() << "\n";
            }
        }
        for (int j = 0; j < m_tasks.size(); j++)
        {
            if (m_tasks[j].getMeridian() == "PM" || m_tasks[j].getMeridian() == "pm")
            {
                std::cout << "- " << m_tasks[j].getDescription() << " at " << m_tasks[j].getTime() << m_tasks[j].getMeridian() << "\n";
            }
        }
    }
}

void Schedule::sortSchedule()
{
    if (m_tasks.size() == 0)
    {
        std::cout << "\n"
                  << std::endl;
    }
    else
    {
        unsigned int min;

        for (unsigned int i = 0; i < m_tasks.size() - 1; ++i)
        {
            min = i;
            for (unsigned int j = i + 1; j < m_tasks.size(); ++j)
            {
                if (m_tasks.at(j).numTime() < m_tasks.at(min).numTime())
                {
                    min = j;
                }
            }
            if (min != i)
            {
                Task temp = m_tasks.at(min);
                m_tasks.at(min) = m_tasks.at(i);
                m_tasks.at(i) = temp;
            }
        }
    }
}

void Schedule::searchTask(std::string keyword)
{
    std::vector<Task> matches;
    for (int i = 0; i < m_tasks.size(); i++)
    {
        if (m_tasks[i].getDescription().find(keyword) != std::string::npos)
        {
            matches.push_back(m_tasks[i]);
        }
    }

    if (matches.size() == 0)
    {
        std::cout << "\nNo matching tasks found" << std::endl;
    }
    else
    {
        std::cout << "\nMatching tasks:" << std::endl;
        for (int i = 0; i < matches.size(); i++)
        {
            std::cout << i + 1 << ". " << matches[i].getDescription() << " (" << matches[i].getTime() << " " << matches[i].getMeridian() << ")" << std::endl;
        }
    }
}

void Schedule::outputFile()
{
    std::cout << "\nFirst, Enter your name: ";
    std::string nam;
    std::getline(std::cin, nam);
    std::ofstream output;
    output.open("todolist.txt");
    output << "Good morning, " << nam;
    output << ". Here are your Tasks for Today:\n\n";

    for (unsigned int i = 0; i < m_tasks.size(); i++)
    {
        if (m_tasks.at(i).getMeridian() == "AM" || m_tasks.at(i).getMeridian() == "am")
            output << " - " << m_tasks[i].getDescription() << " at " << m_tasks[i].getTime() << ' ' << m_tasks[i].getMeridian() << std::endl;
    }
    for (unsigned int j = 0; j < m_tasks.size(); j++)
    {
        if (m_tasks.at(j).getMeridian() == "PM" || m_tasks.at(j).getMeridian() == "pm")
            output << " - " << m_tasks[j].getDescription() << " at " << m_tasks[j].getTime() << ' ' << m_tasks[j].getMeridian() << std::endl;
    }

    output << "\n"
           << "Motivational Quote Of The Day: ";

    int val = rand() % 11;
    if (val == 1)
    {
        output << "Believe in yourself and your abilities. You are capable of achieving anything you set your mind to." << std::endl;
    }
    else if (val == 2)
    {
        output << "Embrace failure as a learning opportunity. Every setback is a chance to grow and improve." << std::endl;
    }
    if (val == 3)
    {
        output << "Set achievable goals and work towards them consistently. Progress, no matter how small, is still progress." << std::endl;
    }
    if (val == 4)
    {
        output << "Surround yourself with positive, supportive people who uplift and motivate you." << std::endl;
    }
    if (val == 5)
    {
        output << "Remember that every journey begins with a single step. Take that first step towards your goals today." << std::endl;
    }
    if (val == 6)
    {
        output << "Don't be afraid to take risks and try new things. The greatest growth and success often come from stepping outside of your comfort zone." << std::endl;
    }
    if (val == 7)
    {
        output << "Persevere through difficult times. The road to success is not always easy, but it's always worth it in the end." << std::endl;
    }
    if (val == 8)
    {
        output << "Focus on your strengths and use them to your advantage. You have unique talents and skills that make you valuable and special." << std::endl;
    }
    if (val == 9)
    {
        output << "Practice gratitude and focus on the positives in your life. A positive mindset is key to staying motivated and achieving your goals." << std::endl;
    }
    if (val == 10)
    {
        output << "Remember that every day is a new opportunity to make progress towards your dreams. Seize the day and make the most of every moment." << std::endl;
    }

    output << std::endl
           << "Be productive today!";
    output.close();

    /*#ifdef _WIN32
        system("start todolist.txt");
    #else
        system("open todolist.txt");
    #endif*/
}
