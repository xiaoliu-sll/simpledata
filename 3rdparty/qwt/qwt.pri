# QWT 安装路径
QWT_INSTALL_PATH = $$PWD

# QWT 插件相关库所在路径（例如：xx.lib）
QWT_LIB_PATH = $$QWT_INSTALL_PATH/lib

# QWT 插件相关头文件所在路径（例如：xx.h）
QWT_INCLUDE_PATH = $$QWT_INSTALL_PATH/include

INCLUDEPATH += $$QWT_INCLUDE_PATH

LIBS += -L$$QWT_LIB_PATH -lqwt
LIBS += -L$$QWT_LIB_PATH -lQt5Concurrent

## debug
#CONFIG(debug, debug|release) {
#LIBS += -L$$QWT_LIB_PATH/
#        -lqwtd
#}

## release
#CONFIG(release, debug|release) {
#LIBS += -L$$QWT_LIB_PATH/
#        -lqwt
#}

