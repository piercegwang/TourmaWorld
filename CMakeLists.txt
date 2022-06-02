# Declare the minimum required cmake version; somewhat arbitrary unless you're using version-specific features.
# We use 3.1 for CMAKE_CXX_STANDARD
cmake_minimum_required(VERSION 3.1)

# Module path; path for other cmake files.
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")

set(BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(TourmaWorld_VERSION_MAJOR 0)
set(TourmaWorld_VERSION_MINOR 1)

# Create a project. Find and replace TourmaWorld to give the project your own title.
project(TourmaWorld)

# Set the version of C++ being used. Here, C++11.
set (CMAKE_CXX_STANDARD 11)

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
 set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")
 set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g")
 set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
 if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
   string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
 else()
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
 endif()
endif()

# CMAKE_SOURCE_DIR refers to the directory with the top-level CMakeLists.txt
# Here, we're including include/ and lib/SFML-2.5.1/include
include_directories("${CMAKE_SOURCE_DIR}/src")
include_directories("${CMAKE_SOURCE_DIR}/src/Core")
include_directories("${CMAKE_SOURCE_DIR}/src/Graphics")
include_directories("${CMAKE_SOURCE_DIR}/src/Physics")
include_directories("${CMAKE_SOURCE_DIR}/src/Object")
include_directories("${CMAKE_SOURCE_DIR}/src/Characters")
include_directories("${CMAKE_SOURCE_DIR}/src/Animation")
include_directories("${CMAKE_SOURCE_DIR}/src/Inputs")
include_directories("${CMAKE_SOURCE_DIR}/src/Timer")
include_directories("/usr/local/include")

# Sets the directory where the linker will search for libraries. Necessary to find the .a (or .dylib, etc) files for SDL.
link_directories("/usr/local/lib")
# link_directories("${CMAKE_SOURCE_DIR}/lib/SDL2")

# Create the executable. Make sure to list every source file (I generally add the headers as well)
add_executable(TourmaWorld
  src/Main.cpp
  src/Core/Engine.h
  src/Core/Engine.cpp
  src/Graphics/TextureManager.h
  src/Graphics/TextureManager.cpp
  src/Physics/Vector2D.h
  src/Physics/Transform.h
  src/Physics/RigidBody.h
  src/Object/IObject.h
  src/Object/GameObject.h
  src/Characters/Character.h
  src/Characters/Player.h
  src/Characters/Player.cpp
  src/Animation/Animation.h
  src/Animation/Animation.cpp
  src/Inputs/Input.h
  src/Inputs/Input.cpp
  src/Timer/Timer.h
  src/Timer/Timer.cpp
  src/Map/Layer.h
)

# If you've branched out into different parts of SFML, you might need different libraries; they can be added here.
target_link_libraries(TourmaWorld SDL2 SDL2_image)

# Test

# install(TARGETS TourmaWorld RUNTIME DESTINATION ${BIN_DIR})
