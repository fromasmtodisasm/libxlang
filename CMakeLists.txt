cmake_minimum_required (VERSION 2.8)
project(xlang C)
#add_subdirectory(src .)

file(
  GLOB SRCS src/*.c
  )
file(
  GLOB HDRS include/*.h
  )
add_library(${PROJECT_NAME} SHARED ${SRCS} ${HDRS})
target_include_directories(${PROJECT_NAME} PUBLIC include)
install (TARGETS xlang DESTINATION bin)
install(FILES HDRS  DESTINATION ${PROJECT_NAME}/include)

