cmake_minimum_required (VERSION 3.8)
project ("Tic_tac_toe"  VERSION 0.1 LANGUAGES CXX)
	
	# Устанавливаем стандарт С++
	set(CMAKE_CXX_STANDARD 20)
	set(CMAKE_CXX_STANDARD_REQUIRED ON)
	set(CMAKE_EXPORT_COMPILE_COMMANDS ON) 


# Включите подпроекты.
add_subdirectory ("src/")
