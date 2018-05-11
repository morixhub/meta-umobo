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
    strace \
    minicom \
    imx-vpu \
    imx-test \    	
    qtbase \
    qtdeclarative \
    qtquick1 \
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

