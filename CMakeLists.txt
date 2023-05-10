cmake_minimum_required(VERSION 3.22.1)
project(raytracer)

set(CMAKE_CXX_STANDARD 20)

include_directories(src)

set(CMAKE_CXX_FLAGS "-O3")

###### PLUGINS ######

### CYLINDER #####
set(OBJ_CYLINDER_SRC
       src/objects/Cylinder.cpp
       src/objects/CylinderEntryPoint.cpp
       src/maths/Vector3D.cpp
       src/maths/Ray.cpp
       src/maths/Utils.cpp
       src/texture/ATexture.cpp
       src/materials/AMaterial.cpp
)

add_library(cylinder SHARED ${OBJ_CYLINDER_SRC})
set_target_properties(cylinder PROPERTIES PREFIX raytracer_)
set_target_properties(cylinder PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/plugins/)

###### SPHERE ######
set(OBJ_SPHERE_SRC
        src/objects/Sphere.cpp
        src/objects/SphereEntryPoint.cpp
        src/maths/Vector3D.cpp
        src/maths/Ray.cpp
        src/maths/Utils.cpp
        src/texture/ATexture.cpp
        src/materials/AMaterial.cpp
)

add_library(sphere SHARED ${OBJ_SPHERE_SRC})
set_target_properties(sphere PROPERTIES PREFIX raytracer_)
set_target_properties(sphere PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/plugins/)

###### PLANE ######
set(OBJ_PLANE_SRC
        src/objects/Plane.cpp
        src/objects/PlaneEntryPoint.cpp
        src/maths/Vector3D.cpp
        src/maths/Ray.cpp
        src/maths/Utils.cpp
        src/texture/ATexture.cpp
        src/materials/AMaterial.cpp
)

add_library(plane SHARED ${OBJ_PLANE_SRC})
set_target_properties(plane PROPERTIES PREFIX raytracer_)
set_target_properties(plane PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/plugins/)

###################################################

###### CHROME ######
set(OBJ_CHROME_SRC
        src/materials/ChromeEntryPoint.cpp
        src/materials/AMaterial.cpp
        src/maths/Vector3D.cpp
        src/maths/Ray.cpp
        src/maths/Utils.cpp
        )

add_library(chrome SHARED ${OBJ_CHROME_SRC})
set_target_properties(chrome PROPERTIES PREFIX raytracer_)
set_target_properties(chrome PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/plugins/materials)

###### PLASTIC ######
set(OBJ_PLASTIC_SRC
        src/materials/PlasticEntryPoint.cpp
        src/materials/AMaterial.cpp
        src/maths/Vector3D.cpp
        src/maths/Ray.cpp
        src/maths/Utils.cpp
        )

add_library(plastic SHARED ${OBJ_PLASTIC_SRC})
set_target_properties(plastic PROPERTIES PREFIX raytracer_)
set_target_properties(plastic PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/plugins/materials)

###################################################

###### CHESSBOARD ######
set(OBJ_CHESSBOARD_SRC
        src/texture/ChessBoardEntryPoint.cpp
        src/texture/ChessBoard.cpp
        src/materials/AMaterial.cpp
        src/texture/ATexture.cpp
        src/maths/Vector3D.cpp
        src/maths/Ray.cpp
        src/maths/Utils.cpp
        )

add_library(chessboard SHARED ${OBJ_CHESSBOARD_SRC})
set_target_properties(chessboard PROPERTIES PREFIX raytracer_)
set_target_properties(chessboard PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/plugins/textures)


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
        src/objects/Cone.cpp
        src/objects/Cone.hpp
        src/objects/IObject.hpp
        src/objects/AObject.hpp
        src/objects/PipeLine.hpp
        src/objects/Cylinder.cpp

        src/lights/ILight.hpp
        src/lights/ALight.hpp
        src/lights/Spot.cpp
        src/lights/Spot.hpp

        src/materials/IMaterial.hpp
        src/materials/Plastic.hpp
        src/materials/AMaterial.cpp
        src/materials/AMaterial.hpp

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
        src/scenes/Scene.cpp
        src/objects/Cylinder.cpp
        src/lights/Ambient.cpp
        src/lights/Ambient.hpp
      
        src/utils/factory/ObjectFactory.hpp
        src/utils/factory/ObjectFactory.cpp
        src/utils/builder/IBuilder.hpp
        src/utils/builder/ABuilder.hpp
        src/objects/SphereBuilder.hpp
        src/objects/PlaneBuilder.hpp
        src/utils/config/data/IData.hpp
        src/utils/config/data/AData.hpp
        src/utils/factory/IObjectFactory.hpp
        src/utils/string/StringUtils.hpp
        src/objects/PlaneData.hpp
        src/objects/SphereData.hpp
        src/utils/loader/PluginsManager.hpp
        src/utils/loader/IPluginsManager.hpp src/materials/Chrome.hpp src/texture/ITexture.hpp src/texture/ATexture.cpp src/texture/ATexture.hpp src/texture/ChessBoard.cpp src/texture/ChessBoard.hpp src/texture/ITextureBuilder.hpp)



target_link_libraries(raytracer config++ -g)
set_target_properties(raytracer PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
