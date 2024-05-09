CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
project(jimmyneutron)

ADD_SUBDIRECTORY(googletest)
SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(run
    Schedule.cpp
    main.cpp
)

ADD_EXECUTABLE(test
	test.cpp
    Schedule.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
