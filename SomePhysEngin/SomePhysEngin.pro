#-------------------------------------------------
#
# Project created by QtCreator 2015-12-05T00:10:20
#
#-------------------------------------------------

QT       += core \
	gui \
	xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SomePhysEngin
TEMPLATE = app

SOURCES += main.cpp \
	someenginmainwindow.cpp \
	math/camera.cpp \
	math/color.cpp \
	math/math.cpp \
	math/matrix.cpp \
	math/quaternion.cpp \
	math/vector.cpp \
	trackball/trackball.cpp \
	tinyxml/tinyxml.cpp \
	tinyxml/tinyxmlerror.cpp \
	tinyxml/tinyxmlparser.cpp \
	enginviewer.cpp \
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
	scenegeneratortest.cpp \
	essentialparaedit.cpp \
	essentialpara.cpp \
	aboutdialog.cpp \
	materialparaedit.cpp \
	basicobjects.cpp \
	vertexparaedit.cpp \
	sphereparaedit.cpp \
	triparaedit.cpp \
	planeparaedit.cpp \
	springparaedit.cpp \
    kdtree/kdtree.cpp

HEADERS  += someenginmainwindow.h \
	math/camera.hpp \
	math/color.hpp \
	math/math.hpp \
	math/matrix.hpp \
	math/quaternion.hpp \
	math/vector.hpp \
	trackball/trackball.h \
	tinyxml/tinyxml.h \
	enginviewer.h \
	include/GL/glew.h \
	include/png.h \
	include/pngconf.h \
	include/zconf.h \
	include/zlib.h \
	include/GL/wglew.h \
	application/imageio.hpp \
	application/scene_loader.hpp \
	application/opengl.hpp \
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
	scene/triangle.hpp \
	scenegeneratortest.h \
	essentialparaedit.h \
	essentialpara.h \
	basicobjects.h \
	aboutdialog.h \
	materialparaedit.h \
	vertexparaedit.h \
	sphereparaedit.h \
	triparaedit.h \
	planeparaedit.h \
	springparaedit.h \
    kdtree/kdtree.h

FORMS	+= someenginmainwindow.ui \
	essentialparaedit.ui \
	aboutdialog.ui \
	materialparaedit.ui \
	vertexparaedit.ui \
	sphereparaedit.ui \
	triparaedit.ui \
	planeparaedit.ui \
	springparaedit.ui

LIBS += -L$$PWD/lib/ -lglew32 \
	-L$$PWD/lib/ -llibpng
