cmake_minimum_required(VERSION 4.0)
project(DSA_Final_Project C)

set(CMAKE_C_STANDARD 11)

add_executable(DSA_Final_Project main.c
        src/transactions.c
        include/transactions.h
        src/blockchain.c
        include/blockchain.h
        src/transactions_utils.c
        include/transactions_utils.h
        src/interface_utils.c
        include/interface_utils.h
        src/input_output.c
        include/input_output.h
)
