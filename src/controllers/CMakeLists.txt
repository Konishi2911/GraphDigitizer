# Source Files
set(SRC_LIST 
	ChartViewController.cpp
)

# Add Executable
add_library(Controllers STATIC
	${SRC_LIST}
)

target_link_libraries(Controllers PRIVATE
	Qt6::Core
	Qt6::Widgets
)

