cmake_minimum_required(VERSION 3.8)
project(TinySQL)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Common.h ConditionParser.h DatabaseManager.h Parser.h StorageManager/Config.h StorageManager/Block.h StorageManager/Disk.h StorageManager/Field.h StorageManager/MainMemory.h StorageManager/Relation.h StorageManager/Schema.h StorageManager/Tuple.h StorageManager/SchemaManager.h StorageManager/StorageManager.cpp)
add_executable(TinySQL ${SOURCE_FILES})