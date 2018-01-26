
project(test_cpp)

cmake_minimum_required(VERSION 2.8)

ADD_DEFINITIONS( -g -W -Wall -D_REENTRANT -D_FILE_OFFSET_BITS=64 -DAC_HAS_INFO
-DAC_HAS_WARNING -DAC_HAS_ERROR -DAC_HAS_CRITICAL -DTIXML_USE_STL
-Wno-literal-suffix -Wno-unused-variable -Wno-unused-function
-std=c++11
-Wno-sign-compare -Wno-deprecated -Wno-unused-parameter -Wno-missing-field-initializers
-DAC_HAS_DEBUG -DLINUX_DAEMON)

aux_source_directory(./ list)

add_executable(test_cpp ${list})