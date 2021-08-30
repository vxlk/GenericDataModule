# CMakeList.txt : CMake project for GenericData, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 20)

# Add source to this project's executable.
add_executable (GenericData "main.cpp" 
"IProperty.hpp"
"Property.hpp" 
"PropertyUtils.hpp"
"PropertyContainer.hpp"
"Properties/StateProperty.hpp"
"Properties/ImmutableProperty.hpp"
"Properties/ConstantProperty.hpp"
"Properties/MutableProperty.hpp"
"Properties/KeyProperty.hpp"
)

target_include_directories(GenericData PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}
${CMAKE_CURRENT_SOURCE_DIR}/Properties
)
# TODO: Add tests and install targets if needed.
