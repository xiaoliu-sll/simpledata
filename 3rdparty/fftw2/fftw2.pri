# FFTW 安装路径
FFTW_INSTALL_PATH = $$PWD

# FFTW 插件相关库所在路径（例如：xx.lib）
FFTW_LIB_PATH = $$FFTW_INSTALL_PATH/lib

# FFTW 插件相关头文件所在路径（例如：xx.h）
FFTW_INCLUDE_PATH = $$FFTW_INSTALL_PATH/include

INCLUDEPATH += $$FFTW_INCLUDE_PATH

LIBS += -L$$FFTW_LIB_PATH -lfftw3
#        -llibfftw/
#        -llibrfftw
