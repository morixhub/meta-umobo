# Customize the package config definitions
PACKAGECONFIG[gles2] = "-opengl es2 -eglfs,,virtual/libgles2 virtual/egl"

# Customize package config content
PACKAGECONFIG_remove = "dbus"
PACKAGECONFIG_remove = "examples"

# Try to remove the following line and see if it works...
# PACKAGECONFIG_append = "sql-sqlite"





