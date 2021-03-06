# nodelet_base
---

This is the base of nodelet.

## How to change your nodelet
---

As an example, let's change this node to "camera_driver".

1. folder name

    1. ~/catkin_ws/src/**nodelet_base** -> **camera_driver**
    
    1. ~/catkin_ws/src/camera_driver/include/**nodelet_base** -> **camera_driver**
    
    1. ~/catkin_ws/src/camera_driver/src/**nodelet_base** -> **camera_driver**

1. file name

    1. ~/catkin_ws/src/nodelet_base/include/camera_driver/**nodelet_base.h** -> **camera_driver.h**

    1. ~/catkin_ws/src/nodelet_base/src/camera_driver/**nodelet_base.cpp** -> **camera_driver.cpp**

    1. ~/catkin_ws/src/nodelet_base/launch/**nodelet_base.launch** -> **camera_driver.launch**

1. CMakeLists.txt

    1. line 2: project(**nodelet_base**) -> project(**camera_driver**)
    
    1. line 106: LIBRARIES **nodelet_base** -> LIBRARIES **camera_driver**
    
    1. line 124: include/${PROJECT_NAME}/**nodelet_base.h** -> include/${PROJECT_NAME}/**camera_driver.h**
    
    1. line 125: src/${PROJECT_NAME}/**nodelet_base.cpp** -> src/${PROJECT_NAME}/**camera_driver.cpp**

1. nodelet_plugins.xml

    1. line 2: \<library path="lib/lib**nodelet_base**" -> \<library path="lib/lib**camera_driver**"

    1. line 4: \<class name="**nodelet_base/NodeletBase**" type="**nodelet_base::NodeletBase**" -> \<class name="**camera_driver/CameraDriver**" type="**camera_driver::CameraDriver**"

1. package.xml

    1. line 3: \<name\>**nodelet_base**\</name\> -> \<name\>**camera_driver**\</name\>

1. camera_driver.launch

    1. line 4: name="**nodelet_base_manager**" output="screen" /\> -> name="**camera_driver_manager**" output="screen" />

    1. line 7: \<node pkg="nodelet" type="nodelet" args="load **nodelet_base/NodeletBase nodelet_base_manager**" -> \<node pkg="nodelet" type="nodelet" args="load **camera_driver/CameraDriver camera_driver_manager**"

    1. line 8: name="**NodeletBase**" output="screen"\> -> name="**CameraDriver**" output="screen"\>

1. camera_driver.h, camera_driver.cpp, loader.cpp

    1. replace nodelet_base -> camera_driver

    1. replace NodeletBase -> CameraDriver

# [Nodelet Everything!](http://www.clearpathrobotics.com/assets/guides/ros/Nodelet%20Everything.html)
