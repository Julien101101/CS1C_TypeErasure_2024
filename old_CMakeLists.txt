cmake_minimum_required(VERSION 3.14)

project(BankRoll)

add_executable(bankroll main.cpp)

install(TARGETS bankroll DESTINATION bin)
