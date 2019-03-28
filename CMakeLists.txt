cmake_minimum_required (VERSION 3.0)
project ( GCDandLCM )

include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")

add_executable( GCDandLCM GCDandLCM.cpp GCDandLCM.h GCD.cpp GCD.h LCM.cpp LCM.h)