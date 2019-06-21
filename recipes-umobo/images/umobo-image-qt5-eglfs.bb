require recipes-fsl/images/fsl-image-multimedia.bb

IMAGE_FEATURES = "debug-tweaks ssh-server-openssh"

IMAGE_INSTALL_append = " \
    gdb \
    gdbserver \
    tslib \
    tslib-conf \
    tslib-tests \
    tslib-calibrate \
    nano \
    alsa-equal \
    alsa-tools \
    alsa-state \
    alsa-utils \
    alsa-plugins \
    imx-alsa-plugins \
    i2c-tools \ 
    nss \
    strace \
    minicom \
    imx-vpu \
    imx-test \
    wget \
    curl \
    cairo \
    pango \
    fontconfig \
    freetype \
    liberation-fonts \
    ca-certificates \
    qtbase \
    qtdeclarative \
    qtquickcontrols \
    qtquickcontrols2 \
    qtmultimedia \
    qtsvg \
    qtimageformats \
    qtscript \
    qtwebengine \
    qtwebview \
    qtgraphicaleffects \
    qtserialport \
    qtvirtualkeyboard \
    cinematicexperience \
    "

inherit populate_sdk_qt5

