CMAKE_MINIMUM_REQUIRED(VERSION 2.8) 

PROJECT(libQingStor)

SET(CMAKE_VERBOSE_MAKEFILE ON CACHE STRING "Verbose build." FORCE)

SET(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake" ${CMAKE_MODULE_PATH})

INCLUDE(Functions)
INCLUDE(Options)

FIND_PACKAGE(OpenSSL REQUIRED)
FIND_PACKAGE(Curl REQUIRED)

IF (WIN32) 
	ADD_DEFINITIONS(-DWIN32)
ENDIF(WIN32)

# add preprocesser macro
ADD_DEFINITIONS(-DCURL_STATICLIB)
ADD_DEFINITIONS(-DYAML_DECLARE_STATIC)


ADD_SUBDIRECTORY(src lib)



