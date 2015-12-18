# SomePhysEngin

## 引言  

这是清华 2015 软件工程 ``某个队'' 课程大作业. 
此项目全部代码如果未特殊声明, 适用于 GPLv2 协议. 

本项目实现了一个简化物理引擎, 引擎中支持运动的球和静止的三角形/平面, 
渲染 XML 格式的输入脚本为视频并显示. 在物理引擎之外设计了一个 Qt 的图形化界面, 
其中包含场景脚本载入, 生成和编辑器以及渲染结果的显示窗口.

## 代码规范

由于本次使用了开源代码框架, 我们以开源框架的规范为主要参考. 
使用的语言是 C++, 编程风格为 OO, 格式细节请先自行参考reference目录下的代码. 
注释语言使用英语. 

## 使用的开源代码
- OpenGL
- tinyXML
- pnglib
- CMU 课程 [CSD 15-462](http://www.cs.cmu.edu/afs/cs/academic/class/15462-f12/www/) 
[Project 5](http://www.cs.cmu.edu/afs/cs/academic/class/15462-f12/www/project/p5.tar.gz)

其中 (for Win) 使用动态链接库 `glew32.dll`, `libpng12-0.dll`, `glew32.dll` 
和静态链接库 `glew32`, `libpng`. 这些二进制文件都有多平台版本. 多平台支持待添加.

## 在 Qt 下运行
请使用 msvc 的 release 模式编译, 需要复制上述 dll 文件到 release 文件夹中.

TO DO
------
- [X] 需求文档
- [X] demo 的面向对象结构分析
- [X] 核心代码的结构分析
- [X] demo 界面设计
- [X] 完成基本功能和框架
- [X] Qt 界面
- [X] 脚本生成器模块
- [X] 帮助文档
- [ ] 展示汇报
