find_package(Qt6 REQUIRED COMPONENTS Core Qml Quick  Concurrent ) 

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(LIB_SOURCES
	"src/qffuture.h"
	"src/qffuture.cpp"
	"src/quickfuture.h"
	"src/qfvariantwrapper.h"
	)
QT_ADD_LIBRARY(quickfuture SHARED)
qt_add_qml_module(quickfuture 
    URI QuickFuture
	NO_GENERATE_PLUGIN_SOURCE
    SOURCES ${LIB_SOURCES}
)
target_compile_definitions(quickfuture PRIVATE QUICK_FUTURE_BUILD_PLUGIN QUICK_FUTURE_LIB)
target_include_directories(quickfuture PUBLIC 
	${CMAKE_CURRENT_SOURCE_DIR}/src
)
include(GNUInstallDirs)
install(TARGETS quickfuture
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)   
target_link_libraries(quickfuture  PRIVATE 
	Qt6::Core 
	Qt6::Qml 
	Qt6::Quick 
	Qt6::Concurrent
)
