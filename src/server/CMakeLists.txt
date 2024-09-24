cmake_minimum_required(VERSION 3.10)
project(server)

set(CMAKE_CXX_STANDARD 20)

include_directories("../../include")

#add_executable(${PROJECT} main.cpp
#    employee.cpp
#    vacation.cpp
#    ${CMAKE_CURRENT_BINARY_DIR}/vacation_protocols.pb.h
#    ${CMAKE_CURRENT_BINARY_DIR}/vacation_protocols.pb.cc
#    ${CMAKE_CURRENT_BINARY_DIR}/vacation_protocols.grpc.pb.h
#    ${CMAKE_CURRENT_BINARY_DIR}/vacation_protocols.grpc.pb.cc
#    grpcserver.cpp
#    iemployeerepository.h
#    ivacationrepository.h
#    employeerepository.cpp
#    vacationrepository.cpp
#)
