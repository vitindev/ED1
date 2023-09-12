cmake_minimum_required(VERSION 3.25)
project(ED1 C)

set(CMAKE_C_STANDARD 11)

add_executable(ED1 main.c BankSimple.h Pointer.h Stack.h Avaliacao1.h Queue.h StackDynamic.h
        List.h
        ChainedList.h
        ChainedListTwice.h
        Avaliacao2.h)
