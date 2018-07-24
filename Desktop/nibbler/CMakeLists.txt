cmake_minimum_required (VERSION 3.0.2)
project(nibbler)

include(ExternalProject)

if(UNIX AND APPLE)
	set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++11 -fPIC")
	message(STATUS "Compiling for unix osx system")
	set(EXTERNAL_INSTALL_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/lib/mac)

	add_executable(nibbler src/main.cpp)

	ExternalProject_Add(
		sfml 
		PREFIX ${EXTERNAL_INSTALL_LOCATION}
		URL https://www.sfml-dev.org/files/SFML-2.5.0-sources.zip
		CMAKE_ARGS 
		-DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION} 
		-DSFML_DEPENDENCIES_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}/Frameworks 
		-DSFML_MISC_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
	)

	include_directories(${EXTERNAL_INSTALL_LOCATION})
	include_directories(${EXTERNAL_INSTALL_LOCATION}/include)

	add_dependencies(nibbler sfml)


	target_link_libraries(nibbler ${EXTERNAL_INSTALL_LOCATION}/lib/libsfml-graphics.dylib 
	${EXTERNAL_INSTALL_LOCATION}/lib/libsfml-system.dylib 
	${EXTERNAL_INSTALL_LOCATION}/lib/libsfml-window.dylib)


else ()
#LINUX
	set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -fPIC")

	message(STATUS "Compiling for linux")
	set(EXTERNAL_INSTALL_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/lib/linux)
	# set(CMAKE_INSTALL_PREFIX ${EXTERNAL_INSTALL_LOCATION})
	set(SFML_DIR "${EXTERNAL_INSTALL_LOCATION}/src/sfml/lib/cmake/SFML")

	add_executable(nibbler src/main.cpp)

	# ExternalProject_Add(
	# 	sfml 
	# 	PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/lib/linux
	# 	URL  https://www.sfml-dev.org/files/SFML-2.5.0-linux-gcc-64-bit.tar.gz
	# 	CMAKE_COMMAND ""
	# 	CONFIGURE_COMMAND ""
	# 	# BUILD_COMMAND ""
	# )

	include_directories(${EXTERNAL_INSTALL_LOCATION})
	include_directories(${EXTERNAL_INSTALL_LOCATION}/include)

	#add_dependencies(nibbler sfml)

	find_package(SFML 2.5.0 COMPONENTS graphics audio REQUIRED)

	target_link_libraries(nibbler sfml-graphics sfml-audio)


endif()