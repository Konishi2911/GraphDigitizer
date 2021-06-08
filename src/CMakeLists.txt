# Source Files
set(SRC_LIST 
	main.cpp
)

# Add Executable
add_executable(test 
	${SRC_LIST}
)

target_include_directories(test PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/views
	${CMAKE_CURRENT_SOURCE_DIR}/controllers
)
target_link_libraries(test PRIVATE
	Views
	Controllers
	Qt6::Core
	Qt6::Widgets
)


# Add subdirectories
add_subdirectory(views)
add_subdirectory(controllers)
