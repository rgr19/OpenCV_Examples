#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "opencv_world" for configuration "Release"
set_property(TARGET opencv_world APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opencv_world PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libopencv_world.so.4.0.1"
  IMPORTED_SONAME_RELEASE "libopencv_world.so.4.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS opencv_world )
list(APPEND _IMPORT_CHECK_FILES_FOR_opencv_world "${_IMPORT_PREFIX}/lib/libopencv_world.so.4.0.1" )

# Import target "opencv_img_hash" for configuration "Release"
set_property(TARGET opencv_img_hash APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opencv_img_hash PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libopencv_img_hash.so.4.0.1"
  IMPORTED_SONAME_RELEASE "libopencv_img_hash.so.4.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS opencv_img_hash )
list(APPEND _IMPORT_CHECK_FILES_FOR_opencv_img_hash "${_IMPORT_PREFIX}/lib/libopencv_img_hash.so.4.0.1" )

# Import target "opencv_sfm" for configuration "Release"
set_property(TARGET opencv_sfm APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opencv_sfm PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libopencv_sfm.so.4.0.1"
  IMPORTED_SONAME_RELEASE "libopencv_sfm.so.4.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS opencv_sfm )
list(APPEND _IMPORT_CHECK_FILES_FOR_opencv_sfm "${_IMPORT_PREFIX}/lib/libopencv_sfm.so.4.0.1" )

# Import target "correspondence" for configuration "Release"
set_property(TARGET correspondence APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(correspondence PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/opencv4/3rdparty/libcorrespondence.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS correspondence )
list(APPEND _IMPORT_CHECK_FILES_FOR_correspondence "${_IMPORT_PREFIX}/lib/opencv4/3rdparty/libcorrespondence.a" )

# Import target "multiview" for configuration "Release"
set_property(TARGET multiview APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(multiview PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/opencv4/3rdparty/libmultiview.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS multiview )
list(APPEND _IMPORT_CHECK_FILES_FOR_multiview "${_IMPORT_PREFIX}/lib/opencv4/3rdparty/libmultiview.a" )

# Import target "numeric" for configuration "Release"
set_property(TARGET numeric APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(numeric PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/opencv4/3rdparty/libnumeric.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS numeric )
list(APPEND _IMPORT_CHECK_FILES_FOR_numeric "${_IMPORT_PREFIX}/lib/opencv4/3rdparty/libnumeric.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
