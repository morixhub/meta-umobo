COMPATIBLE_MACHINE_imx6dl-umobo = "(.)"
BBFOLDER := "${THISDIR}/${PN}"

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"
SRC_URI += " file://0001-Add-Apollo-to-KConfig.patch "

do_configure_prepend() {
  cp -r ${BBFOLDER}/include/* ${S}/include
  cp -r ${BBFOLDER}/board/* ${S}/board
  cp ${BBFOLDER}/apollo_defconfig ${S}/configs
}

