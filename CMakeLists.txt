cmake_minimum_required(VERSION 3.25)
project(raytracer)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(raytracer
        src/Camera.cpp
        src/Camera.hpp
        src/main.cpp
        src/MathUtils.cpp
        src/MathUtils.hpp
        src/Point3D.cpp
        src/Point3D.hpp
        src/Ray.cpp
        src/Ray.hpp
        src/Rectangle3D.cpp
        src/Rectangle3D.hpp
        src/Sphere.cpp
        src/Sphere.hpp
        src/Vector3D.cpp
        src/Vector3D.hpp)
