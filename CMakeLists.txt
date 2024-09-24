cmake_minimum_required(VERSION 3.10)

project(vacation_calendar)

include(./cmake/common.cmake)

set(proto_include_grpc "${CMAKE_CURRENT_BINARY_DIR}/vacations.grpc.pb.h")
set(proto_src_grpc "${CMAKE_CURRENT_BINARY_DIR}/vacations.grpc.pb.cc")
set(proto_include "${CMAKE_CURRENT_BINARY_DIR}/vacations.pb.h")
set(proto_src "${CMAKE_CURRENT_BINARY_DIR}/vacations.pb.cc")
set(proto "./proto/vacation_protocols.proto")

add_custom_command(
    OUTPUT "${proto_src}" "${proto_include}" "${proto_src_grpc}" "${proto_include_grpc}"
      COMMAND ${_PROTOBUF_PROTOC}
      ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
        -I "./proto"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${proto}"
      DEPENDS "${proto}")

include_directories("${CMAKE_CURRENT_BINARY_DIR}")

add_library(proto_grpc
  ${proto_include_grpc}
  ${proto_src_grpc}
  ${proto_include}
  ${proto_src}
)
target_link_libraries(proto_grpc
  absl::absl_log
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF})
add_subdirectory(src)



