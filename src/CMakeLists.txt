# Ищем Qt 
#find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(${PROJECT_NAME}
"main.cpp"
"model/field.cpp"
"model/cell.cpp"
"model/logic.cpp"
"model/status.cpp")

# Указываем подключенные директории
target_include_directories(${PROJECT_NAME} PUBLIC 
"${CMAKE_SOURCE_DIR}/src"
)

