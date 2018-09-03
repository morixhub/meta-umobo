FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI += "file://0001-Enable-OpenSSL-Certificates.patch \
            "
            
# Add explicit dependency on NSS
DEPENDS += " \
    nss \
"








