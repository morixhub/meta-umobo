BBFOLDER := "${THISDIR}/${PN}"

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:${THISDIR}/${PN}/arch/arm/configs:"

SRC_URI += "file://apollo_defconfig.cfg \
            file://0001-Add-Ampire-LCD.patch \
            "

do_configure_prepend() {
  cp -r ${BBFOLDER}/arch/* ${S}/arch
}

