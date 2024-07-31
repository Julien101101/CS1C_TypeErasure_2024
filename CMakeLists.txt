cmake_minimum_required(VERSION 3.28)
project(TypeReasure4)

set(CMAKE_CXX_STANDARD 17)

add_executable(TypeReasure4 main.cpp
        certificate_of_deposit.cpp
        certificate_of_deposit.h
        high_interest_savings_with_min_balance.cpp
        high_interest_savings_with_min_balance.h
        high_interest_savings.cpp
        high_interest_savings.h
        high_interest_checking.cpp
        high_interest_checking.h
        no_service_charge_checking.cpp
        no_service_charge_checking.h
        service_charge_checking.cpp
        service_charge_checking.h
        account_impl.h
        accounts.h)
