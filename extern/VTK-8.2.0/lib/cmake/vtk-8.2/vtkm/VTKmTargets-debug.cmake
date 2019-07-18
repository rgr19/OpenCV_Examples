#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "vtkm_cont" for configuration "Debug"
set_property(TARGET vtkm_cont APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkm_cont PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libvtkm_cont-vtk8.2.so.1"
  IMPORTED_SONAME_DEBUG "libvtkm_cont-vtk8.2.so.1"
  )

list(APPEND _IMPORT_CHECK_TARGETS vtkm_cont )
list(APPEND _IMPORT_CHECK_FILES_FOR_vtkm_cont "${_IMPORT_PREFIX}/lib/libvtkm_cont-vtk8.2.so.1" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
