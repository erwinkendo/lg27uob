#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 2.6)

set(CMAKE_BUILD_TYPE Release)
# Enable debug symbols by default
# must be done before project() statement
#if(NOT CMAKE_BUILD_TYPE)
#  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
#endif()
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)

project(lg27uob)

# Set version information in a config.h file
set(lg27uob_VERSION_MAJOR 1)
set(lg27uob_VERSION_MINOR 0)
configure_file(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )
include_directories("${PROJECT_BINARY_DIR}")

# Define sources and executable
set(EXECUTABLE_NAME "lg27uob")
add_executable(${EXECUTABLE_NAME} main.cpp)


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML

#If installed in windows, change this path
set(SFML_ROOT "C:/SFML-2.4.0/")
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

# Install target
#install(TARGETS ${EXECUTABLE_NAME} RUNTIME DESTINATION bin)
install(DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/" DESTINATION bin)
# "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/*.dll" DESTINATION bin)

#install(TARGETS ${SFML_LIBRARIES} ARCHIVE DESTINATION bin)
 
# CPack packaging
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_VERSION_MAJOR "${lg27uob_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${lg27uob_VERSION_MINOR}")
include(CPack)