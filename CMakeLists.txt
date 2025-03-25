cmake_minimum_required(VERSION 3.10)
project(OpenCVText)

# Đường dẫn đến vcpkg
set(CMAKE_TOOLCHAIN_FILE "C:/tools/vcpkg/scripts/buildsystems/vcpkg.cmake")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(main main.cpp)
target_link_libraries(main ${OpenCV_LIBS})

# # Yêu cầu phiên bản tối thiểu của CMake
# cmake_minimum_required(VERSION 3.16)

# # Tên dự án (dùng để phân biệt nhiều dự án)
# project(image_text)

# # Thiết lập chuẩn C++ (17 hoặc mới hơn)
# set(CMAKE_CXX_STANDARD 17)

# # Tìm thư viện OpenCV đã cài đặt
# find_package(OpenCV REQUIRED)

# # Chỉ định file đầu vào (main.cpp) để build
# add_executable(main main.cpp)

# # Liên kết chương trình với thư viện OpenCV
# target_link_libraries(main ${OpenCV_LIBS})
