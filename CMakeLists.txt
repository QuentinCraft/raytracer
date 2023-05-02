cmake_minimum_required(VERSION 3.25)
project(raytracer)

set(CMAKE_CXX_STANDARD 20)

include_directories(src)

set(CMAKE_CXX_FLAGS "-O3")

add_executable(raytracer
        src/main.cpp

        src/maths/Utils.cpp
        src/maths/Utils.hpp
        src/maths/Ray.cpp
        src/maths/Ray.hpp
        src/maths/Vector3D.cpp
        src/maths/Vector3D.hpp

        src/objects/Sphere.cpp
        src/objects/Sphere.hpp
        src/objects/Plane.cpp
        src/objects/Plane.hpp
        src/objects/IObject.hpp
        src/objects/AObject.hpp
        src/objects/PipeLine.hpp

        src/lights/ILight.hpp
        src/lights/ALight.hpp
        src/lights/Spot.cpp
        src/lights/Spot.hpp

        src/materials/IMaterial.hpp

        src/utils/config/Config.hpp
        src/utils/Error.hpp

        src/cameras/ICamera.hpp
        src/cameras/Camera.hpp
        src/cameras/Camera.cpp

        src/renderer/IRenderer.hpp

        src/utils/config/ConfigManager.hpp
        src/utils/config/ConfigManager.cpp
        src/utils/loader/LibraryLoader.hpp
        src/utils/loader/Loader.hpp
        src/utils/loader/ILoader.hpp
        src/utils/loader/LibraryLoader.cpp

        src/scenes/IScene.hpp
        src/scenes/Scene.cpp src/utils/factory/ObjectFactory.hpp src/utils/factory/ObjectFactory.cpp src/utils/builder/IBuilder.hpp src/utils/builder/ABuilder.hpp src/objects/SphereBuilder.hpp src/objects/PlaneBuilder.hpp src/utils/data/IData.hpp src/utils/data/AData.hpp)


target_link_libraries(raytracer config++ -g)
