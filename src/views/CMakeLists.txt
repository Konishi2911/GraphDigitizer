# Source Files
set(SRC_LIST 
	MainWindow.cpp
	ChartScene.cpp
	GraphicsAxisLineItem.cpp
)

# Add Views Library
add_library(Views STATIC
	${SRC_LIST}
)

target_include_directories(Views PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/../controllers/
)
target_link_libraries(Views PRIVATE
	Controllers
	Qt6::Core 
	Qt6::Widgets
)
