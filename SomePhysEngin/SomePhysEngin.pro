#-------------------------------------------------
#
# Project created by QtCreator 2015-12-05T00:10:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SomePhysEngin
TEMPLATE = app


SOURCES += main.cpp\
        someenginmainwindow.cpp \
    math/camera.cpp \
    math/color.cpp \
    math/math.cpp \
    math/matrix.cpp \
    math/quaternion.cpp \
    math/vector.cpp \
    tinyxml/tinyxml.cpp \
    tinyxml/tinyxmlerror.cpp \
    tinyxml/tinyxmlparser.cpp \
    enginviewer.cpp \
    application/camera_roam.cpp \
    application/imageio.cpp \
    application/scene_loader.cpp \
    physics/collisions.cpp \
    physics/lenthsquarespring.cpp \
    physics/physics.cpp \
    physics/planebody.cpp \
    physics/spherebody.cpp \
    physics/spring.cpp \
    physics/trianglebody.cpp \
    scene/geometry.cpp \
    scene/material.cpp \
    scene/mesh.cpp \
    scene/model.cpp \
    scene/scene.cpp \
    scene/sphere.cpp \
    scene/triangle.cpp \
    application/application.cpp

HEADERS  += someenginmainwindow.h \
    math/camera.hpp \
    math/color.hpp \
    math/math.hpp \
    math/matrix.hpp \
    math/quaternion.hpp \
    math/vector.hpp \
    tinyxml/tinyxml.h \
    enginviewer.h \
    include/GL/glew.h \
    include/png.h \
    include/pngconf.h \
    include/zconf.h \
    include/zlib.h \
	include/GL/wglew.h \
    application/camera_roam.hpp \
    application/application.hpp \
    application/imageio.hpp \
    application/scene_loader.hpp \
    physics/body.hpp \
    physics/collisions.hpp \
    physics/lenthsquarespring.hpp \
    physics/physics.hpp \
    physics/planebody.hpp \
    physics/spherebody.hpp \
    physics/spring.hpp \
    physics/trianglebody.hpp \
    scene/geometry.hpp \
    scene/material.hpp \
    scene/mesh.hpp \
    scene/model.hpp \
    scene/scene.hpp \
    scene/sphere.hpp \
    scene/triangle.hpp

FORMS    += someenginmainwindow.ui

LIBS += -L$$PWD/lib/ -lglew32 \
		-L$$PWD/lib/ -llibpng
