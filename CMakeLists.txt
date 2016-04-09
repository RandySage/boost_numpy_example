cmake_minimum_required(VERSION 2.8.9)
project(numpy_boost_python)

add_library(nbp SHARED boost_numpy_example.cpp)

execute_process(
  COMMAND python -c "import numpy; print numpy.get_include()"
  OUTPUT_VARIABLE NUMPY_INCLUDE_PATH
  ERROR_QUIET
)
find_package(Boost COMPONENTS python REQUIRED)
find_package( PythonLibs 2.7 REQUIRED )

include_directories(
  ${PYTHON_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
  ${NUMPY_INCLUDE_PATH}
)
target_link_libraries(nbp ${Boost_LIBRARIES})
