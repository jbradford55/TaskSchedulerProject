[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=9934800&assignment_repo_type=AssignmentRepo)

 > Authors: \<[Jace Kang](https://github.com/jckang1)\> \<[James Bradford](https://github.com/jbradford55)\> \<[Simarpal Singh](https://github.com/Simar0108)\> \<[Rahul Cherkuri](https://github.com/rahulcherkuri)\>


## Project Description

 > The Early Bird Schedule Manager is a software program designed to help users manage their daily tasks and schedule in a more organized and efficient manner. The program is written in C++ and consists of two main classes: the Task class and the Schedule class.

The Task class represents an individual task or activity that the user needs to complete. Each task has a name, description, start time (in 12-hour format with AM or PM), and priority level. The Schedule class is responsible for managing a collection of tasks for the day, sorting them based on their start time, and providing various functionalities for adding, editing, removing, and searching for tasks.

The Early Bird Schedule Manager has a simple and intuitive user interface that allows users to easily navigate and interact with the program. Upon launching the program, the user is presented with the main menu, where they can choose to add a new task, edit an existing task, remove a task, search for a task, view the schedule for the day, or generate a to-do list.

When adding a new task, the user is prompted to enter the task name, description, start time (in 12-hour format with AM or PM), and priority level. The program then checks for any scheduling conflicts and ensures that the new task does not overlap with any existing tasks. If there is a conflict, the user is notified and prompted to make changes to the task or choose a different time slot.

The Schedule class uses an algorithm to sort the tasks based on their start times, with the earliest task appearing first in the list. The user can also sort the tasks based on their priority level, with the highest priority tasks appearing first.

Users can edit an existing task by selecting it from the list and making changes to its properties, including the task name, description, start time (in 12-hour format with AM or PM), and priority level. They can also remove a task by selecting it from the list and confirming the removal.

The search functionality allows users to search for a specific task by entering its name or description. The program then displays all matching tasks, along with their properties.

The Early Bird Schedule Manager also generates a text file for the user with their to-do list made by the program, along with a quote of the day at the bottom. The files are Schedule.h, Schedule.cpp, and main.cpp.

Overall, the Early Bird Schedule Manager is a powerful tool that can help users stay organized and manage their daily tasks more effectively. With its user-friendly interface and advanced features, it is an ideal solution for anyone looking to optimize their schedule and boost their productivity.
 
 > ## Phase II
 >The program defines two classes, Task and Schedule. Task represents a single task and has three private member variables (m_description, m_time, m_meridian) that hold a task's description, time, and meridian (AM/PM). It also has several public member functions that allow the user to access and modify these member variables.

Schedule represents the overall schedule and contains a std::vector of Task objects (m_tasks). It has several member functions that allow the user to add, edit, and remove tasks from the schedule, as well as print out the schedule and output it to a file. The Schedule class also has a private member function numTime() that converts a task's time from a string to an integer value, which is used for sorting the schedule.

Overall, the UML diagram provides a clear overview of the program's features and functionality, and includes private variables and public functions for each class and subclass.


- User Epics:
- As a user, I want to be able to schedule appointments, so that I do not miss them/show up late.
-As a user, I want to be able to edit the name/time/description of my task so that I can update them if they change.
-As a user, I want to be able to schedule times for my tasks, so I know what time they will be at.
-As a user, I want to be able to have the program sort my tasks for the day so I can know what my day will look like chronologicallly.
-As a user, I want to be able to have the option to search for a task within my tasks, so I can have an easy way to know if I have something specifically to do that day.
-As a user, I want to be able to receive a personalized file with my to do list, so that I can download/print it and keep it with me for the day.
-As a user, I want to be able to see my tasks if I ask the software to give me a list of them, so I can quickly see what I need to do for the day.

> ## Phase III

1). Schedule class: 


    Single Responsibility Principle (SRP): 
        The Schedule class has only one responsibility, which is managing(scheduling) tasks. This gave us an effective structure and foundation for the rest of the project
    Open-Closed Principle (OCP): 
        The Schedule class is open for extension (i.e. new types of tasks can be added), but closed for modification (i.e. the existing methods don't need to be changed). This helps so that we don’t mess up our code as we continue to work on the project and implement new features
    Dependency Inversion Principle (DIP): 
        The Schedule class depends on the abstraction of Task class rather than the implementation, which makes it easy to switch between different types of tasks. This helps us as it doesn’t rely on abstraction, but the two classes help eachother out in the implementation.

2). Task class:

    Single Responsibility Principle (SRP): 
        The Task class has only one responsibility, which is representing a task with its description and date. This helps by keeping it simple and providing a basis for what the task actually consists of.
    Open-Closed Principle (OCP): 
        The Task class is open for extension (i.e. derived classes can add new functionality), but closed for modification (i.e. the existing methods don't need to be changed). This allows us to work off of the class but not change any code that is already a basis for our project
    Liskov Substitution Principle (LSP):



Overall, by applying SOLID principles to this class diagram, the code is designed to be more maintainable, extensible, and easier to understand. For example, if you want to add a new type of task in the future, you can simply create a new derived class from Task without changing the existing code. In our old program, we didn’t have a basis for what it would look like to add a task, nor how it would work when the program would store what we had. Our classes were jumbled and not structured the way they were supposed to be to have the program work the way we wanted.


 ## Screenshots
 > Screenshots of the input/output after running your application
 > <img width="542" alt="Screen Shot 2023-03-17 at 4 27 03 PM" src="https://user-images.githubusercontent.com/98068297/226070527-655afb68-3e15-4bf4-9d2c-a5a78881eea6.png">
<img width="285" alt="Screen Shot 2023-03-17 at 4 32 03 PM" src="https://user-images.githubusercontent.com/98068297/226070530-56098743-5cdc-43c0-85ac-9335007fa8b7.png">
<img width="412" alt="Screen Shot 2023-03-17 at 4 32 15 PM" src="https://user-images.githubusercontent.com/98068297/226070531-87c42e9c-a8ba-45bb-88c3-1fe0bcc5e458.png">
<img width="316" alt="Screen Shot 2023-03-17 at 4 32 28 PM" src="https://user-images.githubusercontent.com/98068297/226070532-d643dbc1-46a9-4a11-8cce-458ffeac64d8.png">
<img width="502" alt="Screen Shot 2023-03-17 at 4 32 52 PM" src="https://user-images.githubusercontent.com/98068297/226070533-815000ba-2698-4c91-b5ab-c2ec54437129.png">
<img width="1127" alt="Screen Shot 2023-03-17 at 4 33 12 PM" src="https://user-images.githubusercontent.com/98068297/226070534-9e2239a2-d621-439c-ab3d-5e98361a65bd.png">
<img width="372" alt="Screen Shot 2023-03-17 at 4 33 20 PM" src="https://user-images.githubusercontent.com/98068297/226070535-0d0445f7-0a61-4577-8789-e3ce8cfdb248.png">

 ## Installation/Usage
 > Instructions on installing and running your application
 > download files: Schedule.h, Schedule.cpp, main.cpp
 > open terminal (preferrably mac)
 > once there, enter the command "cd Downloads"
 > then, run "g++ Schedule.cpp main.cpp" hit enter and then ./a.out.
 > Then, the program has compiled, and you can start inputting your tasks.
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 > We made unit tests using the googletest submodule/folder to test our functions.
 
