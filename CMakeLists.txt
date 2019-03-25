cmake_minimum_required(VERSION 3.11)
project(misaxx-ome-visualizer VERSION 1.0.0 DESCRIPTION "OME TIFF Visualization")

find_package(misaxx-core REQUIRED)
find_package(misaxx-imaging-ome REQUIRED)
find_package(opencv-toolbox REQUIRED)
# Add additional packages if necessary

add_library(misaxx-ome-visualizer include/misaxx-ome-visualizer/module_interface.h
        include/misaxx-ome-visualizer/module.h
        src/misaxx-ome-visualizer/module_interface.cpp
        src/misaxx-ome-visualizer/module.cpp
        src/misaxx-ome-visualizer/algorithms/visualize_task.cpp
        src/misaxx-ome-visualizer/algorithms/visualize_task.h
        src/misaxx-ome-visualizer/attachments/colormap.cpp
        include/misaxx-ome-visualizer/attachments/colormap.h
        src/misaxx-ome-visualizer/algorithms/find_colormap_task.cpp
        src/misaxx-ome-visualizer/algorithms/find_colormap_task.h
        include/misaxx-ome-visualizer/module_info.h
        src/misaxx-ome-visualizer/module_info.cpp)

# Add additional link targets if necessary
target_link_libraries(misaxx-ome-visualizer misaxx::misaxx-core misaxx::misaxx-imaging-ome opencv-toolbox::opencv-toolbox)

# MISA++ helper script (automatically included by Core Library)
set(MISAXX_LIBRARY misaxx-ome-visualizer)
set(MISAXX_LIBRARY_NAMESPACE misaxx::)
set(MISAXX_API_NAME misaxx-ome-visualizer)
set(MISAXX_API_INCLUDE_PATH misaxx-ome-visualizer)
set(MISAXX_API_NAMESPACE misaxx_ome_visualizer)
misaxx_with_default_module_info()
misaxx_with_default_api()

# Only if it's a worker module:
misaxx_with_default_executable()
