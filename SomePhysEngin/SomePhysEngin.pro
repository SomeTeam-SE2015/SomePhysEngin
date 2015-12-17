#-------------------------------------------------
#
# Project created by QtCreator 2015-12-05T00:10:20
#
#-------------------------------------------------

QT       += core gui widgets

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
    scenegeneratortest.cpp \
    essentialparaedit.cpp \
    essentialpara.cpp \
    materialparaedit.cpp \
    basicobjects.cpp \
    vertexparaedit.cpp \
    sphereparaedit.cpp \
    triparaedit.cpp \
    planeparaedit.cpp \
    springparaedit.cpp

#SOURCES += application/camera_roam.cpp \
#    application/imageio.cpp \
#    application/scene_loader.cpp \
#    physics/collisions.cpp \
#    physics/lenthsquarespring.cpp \
#    physics/physics.cpp \
#    physics/planebody.cpp \
#    physics/spherebody.cpp \
#    physics/spring.cpp \
#    physics/trianglebody.cpp \
#    scene/geometry.cpp \
#    scene/material.cpp \
#    scene/mesh.cpp \
#    scene/model.cpp \
#    scene/scene.cpp \
#    scene/sphere.cpp \
#    scene/triangle.cpp \
#    application/application.cpp

HEADERS  += someenginmainwindow.h \
    math/camera.hpp \
    math/color.hpp \
    math/math.hpp \
    math/matrix.hpp \
    math/quaternion.hpp \
    math/vector.hpp \
	tinyxml/tinyxml.h \
	enginviewer.h \
    scenegeneratortest.h \
    essentialparaedit.h \
    essentialpara.h \
    basicobjects.h \
    materialparaedit.h \
    vertexparaedit.h \
    sphereparaedit.h \
    triparaedit.h \
    planeparaedit.h \
    springparaedit.h

#HEADERS  += include/GL/glew.h \
#    include/png.h \
#    include/pngconf.h \
#    include/zconf.h \
#    include/zlib.h \
#    include/GL/wglew.h \
#    include/SDL/begin_code.h \
#    include/SDL/close_code.h \
#    include/SDL/SDL.h \
#    include/SDL/SDL_active.h \
#    include/SDL/SDL_audio.h \
#    include/SDL/SDL_byteorder.h \
#    include/SDL/SDL_cdrom.h \
#    include/SDL/SDL_config.h \
#    include/SDL/SDL_config_amiga.h \
#    include/SDL/SDL_config_dreamcast.h \
#    include/SDL/SDL_config_macos.h \
#    include/SDL/SDL_config_macosx.h \
#    include/SDL/SDL_config_minimal.h \
#    include/SDL/SDL_config_nds.h \
#    include/SDL/SDL_config_os2.h \
#    include/SDL/SDL_config_symbian.h \
#    include/SDL/SDL_config_win32.h \
#    include/SDL/SDL_copying.h \
#    include/SDL/SDL_cpuinfo.h \
#    include/SDL/SDL_endian.h \
#    include/SDL/SDL_error.h \
#    include/SDL/SDL_events.h \
#    include/SDL/SDL_getenv.h \
#    include/SDL/SDL_image.h \
#    include/SDL/SDL_joystick.h \
#    include/SDL/SDL_keyboard.h \
#    include/SDL/SDL_keysym.h \
#    include/SDL/SDL_loadso.h \
#    include/SDL/SDL_main.h \
#    include/SDL/SDL_mouse.h \
#    include/SDL/SDL_mutex.h \
#    include/SDL/SDL_name.h \
#    include/SDL/SDL_opengl.h \
#    include/SDL/SDL_platform.h \
#    include/SDL/SDL_quit.h \
#    include/SDL/SDL_rwops.h \
#    include/SDL/SDL_stdinc.h \
#    include/SDL/SDL_syswm.h \
#    include/SDL/SDL_thread.h \
#    include/SDL/SDL_timer.h \
#    include/SDL/SDL_ttf.h \
#    include/SDL/SDL_types.h \
#    include/SDL/SDL_version.h \
#    include/SDL/SDL_video.h \
#    application/camera_roam.hpp \
#    application/application.hpp \
#    application/imageio.hpp \
#    application/scene_loader.hpp \
#    physics/body.hpp \
#    physics/collisions.hpp \
#    physics/lenthsquarespring.hpp \
#    physics/physics.hpp \
#    physics/planebody.hpp \
#    physics/spherebody.hpp \
#    physics/spring.hpp \
#    physics/trianglebody.hpp \
#    scene/geometry.hpp \
#    scene/material.hpp \
#    scene/mesh.hpp \
#    scene/model.hpp \
#    scene/scene.hpp \
#    scene/sphere.hpp \
#    scene/triangle.hpp

FORMS    += someenginmainwindow.ui \
    essentialparaedit.ui \
    materialparaedit.ui \
    vertexparaedit.ui \
    sphereparaedit.ui \
    triparaedit.ui \
    planeparaedit.ui \
    springparaedit.ui

#LIBS += -L$$PWD/lib/ -lglew32 \
#        -L$$PWD/lib/ -llibpng
#LIBS += -L$$PWD/lib/ -lSDL \
#        -L$$PWD/lib/ -lSDLmain
