#include "gtest/gtest.h"
#include "Schedule.h"


// Unit tests for Task class
TEST(TaskTest, DescriptionTest) {
    Task task("Do laundry", "10:00", "AM");
    EXPECT_EQ(task.getDescription(), "Do laundry");
}

TEST(TaskTest, DescriptionTest2) {
    Task task("Basketball", "9:00", "AM");
    EXPECT_EQ(task.getDescription(), "Basketball");
}

TEST(TaskTest, TimeTest) {
    Task task("Do laundry", "10:00", "AM");
    EXPECT_EQ(task.getTime(), "10:00");
}

TEST(TaskTest, TimeTest2) {
    Task task("Do laundry", "12:00", "PM");
    EXPECT_EQ(task.getTime(), "12:00");
}

TEST(TaskTest, MeridianTest) {
    Task task("Do laundry", "10:00", "AM");
    EXPECT_EQ(task.getMeridian(), "AM");
}

TEST(TaskTest5, MeridianTest2) {
    Task task("Do laundry", "10:00", "PM");
    EXPECT_EQ(task.getMeridian(), "PM");
}

// Unit tests for Schedule::addTask() function
TEST(ScheduleAddTaskTest, SingleTaskTest) {
    Schedule schedule;
    schedule.addTask("Do laundry", "10:00", "AM");
    EXPECT_EQ(schedule.getTasks().size(), 1);
}

TEST(ScheduleAddTaskTest, SingleTaskTest2) {
    Schedule schedule;
    schedule.addTask("Do laundry", "10:00", "AM");
    schedule.addTask("Basketball", "9:00", "PM");
    EXPECT_EQ(schedule.getTasks().size(), 2);
}

TEST(ScheduleAddTaskTest, MultipleTasksTest) {
    Schedule schedule;
    schedule.addTask("Do laundry", "10:00", "AM");
    schedule.addTask("Buy groceries", "2:00", "PM");
    schedule.addTask("Go to gym", "6:00", "PM");
    EXPECT_EQ(schedule.getTasks().size(), 3);
}

TEST(ScheduleAddTaskTest, TaskDetailsTest) {
    Schedule schedule;
    schedule.addTask("Do laundry", "10:00", "AM");
    Task task = schedule.getTasks()[0];
    EXPECT_EQ(task.getDescription(), "Do laundry");
    EXPECT_EQ(task.getTime(), "10:00");
    EXPECT_EQ(task.getMeridian(), "AM");
}

TEST(ScheduleAddTaskTest, TaskDetailsTest2) {
    Schedule schedule;
    schedule.addTask("Basketball", "8:00", "PM");
    Task task = schedule.getTasks()[0];
    EXPECT_EQ(task.getDescription(), "Basketball");
    EXPECT_EQ(task.getTime(), "8:00");
    EXPECT_EQ(task.getMeridian(), "PM");
}

TEST(ScheduleAddTaskTest, TaskDetailsTest3) {
    Schedule schedule;
    schedule.addTask("Do homework", "5:00", "PM");
    Task task = schedule.getTasks()[0];
    EXPECT_EQ(task.getDescription(), "Do homework");
    EXPECT_EQ(task.getTime(), "5:00");
    EXPECT_EQ(task.getMeridian(), "PM");
}

TEST(ScheduleAddTaskTest, TaskDetailsTest4) {
    Schedule schedule;
    schedule.addTask("Hang out with friends", "8:00", "PM");
    Task task = schedule.getTasks()[0];
    EXPECT_EQ(task.getDescription(), "Hang out with friends");
    EXPECT_EQ(task.getTime(), "8:00");
    EXPECT_EQ(task.getMeridian(), "PM");
}

TEST(ScheduleAddTaskTest, TaskDetailsTest5) {
    Schedule schedule;
    schedule.addTask("Eat vitamins", "8:00", "PM");
    Task task = schedule.getTasks()[0];
    EXPECT_EQ(task.getDescription(), "Eat vitamins");
    EXPECT_EQ(task.getTime(), "8:00");
    EXPECT_EQ(task.getMeridian(), "PM");
}

TEST(ScheduleAddTaskTest, TaskDetailsTest6) {
    Schedule schedule;
    schedule.addTask("Go on a date", "7:00", "PM");
    Task task = schedule.getTasks()[0];
    EXPECT_EQ(task.getDescription(), "Go on a date");
    EXPECT_EQ(task.getTime(), "7:00");
    EXPECT_EQ(task.getMeridian(), "PM");
}


// Unit tests for Schedule::editTask() function
TEST(ScheduleEditTaskTest, DescriptionTest) {
    Schedule schedule;
    schedule.addTask("Do laundry", "10:00", "AM");
    schedule.editTask(0, "Wash dishes", "10:00", "AM");
    Task task = schedule.getTasks()[0];
    EXPECT_EQ(task.getDescription(), "Wash dishes");
}

TEST(ScheduleEditTaskTest, TimeTest) {
    Schedule schedule;
    schedule.addTask("Do laundry", "10:00", "AM");
    schedule.editTask(0, "Do laundry", "2:00", "PM");
    Task task = schedule.getTasks()[0];
    EXPECT_EQ(task.getTime(), "2:00");
}

TEST(ScheduleEditTaskTest, MeridianTest) {
    Schedule schedule;
    schedule.addTask("Do laundry", "10:00", "AM");
    schedule.editTask(0, "Do laundry", "10:00", "PM");
    Task task = schedule.getTasks()[0];
    EXPECT_EQ(task.getMeridian(), "PM");
}

// Unit tests for Schedule::removeTask() function
TEST(ScheduleRemoveTaskTest, SingleTaskTest) {
    Schedule schedule;
    schedule.addTask("Do laundry", "10:00", "AM");
    schedule.removeTask(0);
    EXPECT_EQ(schedule.getTasks().size(), 0);
}

TEST(ScheduleRemoveTaskTest, MultipleTasksTest) {
    Schedule schedule;
    schedule.addTask("Do laundry", "10:00", "AM");
    schedule.addTask("Buy groceries", "2:00", "PM");
    schedule.addTask("Go to gym", "6:00", "PM");
    schedule.removeTask(1);
    EXPECT_EQ(schedule.getTasks().size(), 2);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
