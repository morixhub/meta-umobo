# Add dependency on qtwebengine because otherwise webengine-related stuff won't be included in SDK
RDEPENDS_${PN} += " \
    qtwebengine \
"

RDEPENDS_${PN}_remove = "qtwebkit"
RDEPENDS_${PN}_remove = "qtwebkit-dev"







