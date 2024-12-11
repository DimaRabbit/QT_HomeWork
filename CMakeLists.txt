cmake_minimum_required(VERSION 3.16)

project(QtModulesExample LANGUAGES CXX)

# Включение автогенерации для UIC, MOC и RCC
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Поиск Qt6 (или Qt5, если необходимо)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Network Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Network Sql)

# Добавление исполняемого файла
add_executable(QtModulesExample
  main.cpp
)

# Связывание с модулями Qt
target_link_libraries(QtModulesExample 
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Network
    Qt${QT_VERSION_MAJOR}::Sql
)

# Установка путей для сборки
include(GNUInstallDirs)
install(TARGETS QtModulesExample
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)