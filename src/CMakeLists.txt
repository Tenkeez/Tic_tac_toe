# Ищем Qt 
#find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(${PROJECT_NAME}
"main.cpp"
)

# Указываем подключенные директории
target_include_directories(${PROJECT_NAME} PUBLIC 
"${CMAKE_SOURCE_DIR}/src"
)

# Подключаем другие CMakeLists

