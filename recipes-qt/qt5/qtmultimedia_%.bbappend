FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

PACKAGECONFIG_append = "gstreamer010"

do_configure_prepend() {    

# disable openal test if it isn't enabled by PACKAGECONFIG    

sed -i 's/^qtCompileTest(openal)/OE_OPENAL_ENABLED:qtCompileTest(openal)/g' ${S}/qtmultimedia.pro    

# disable gstreamer-0.10 test if it isn't enabled by PACKAGECONFIG    

sed -i 's/^\( *\)qtCompileTest(gstreamer) {/\1OE_GSTREAMER010_ENABLED:qtCompileTest(gstreamer) {/g' ${S}/qtmultimedia.pro    

}

SRC_URI += "\
    file://0001-Initial-porting-effort-to-GStreamer-1.0.patch \
    file://0002-qtmultimedia.pro-Respect-OE_GSTREAMER_ENABLED-OE_GST.patch \
"



