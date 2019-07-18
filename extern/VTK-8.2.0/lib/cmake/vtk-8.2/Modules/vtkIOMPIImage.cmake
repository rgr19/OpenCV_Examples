set(vtkIOMPIImage_LOADED 1)
set(vtkIOMPIImage_DEPENDS "vtkCommonCore;vtkCommonDataModel;vtkCommonTransforms;vtkIOImage;vtkIOImage;vtkParallelCore;vtkParallelMPI;vtksys")
set(vtkIOMPIImage_LIBRARIES "vtkIOMPIImage")
set(vtkIOMPIImage_INCLUDE_DIRS "${VTK_INSTALL_PREFIX}/include/vtk-8.2")
set(vtkIOMPIImage_LIBRARY_DIRS "")
set(vtkIOMPIImage_RUNTIME_LIBRARY_DIRS "${VTK_INSTALL_PREFIX}/lib")
set(vtkIOMPIImage_WRAP_HIERARCHY_FILE "${CMAKE_CURRENT_LIST_DIR}/vtkIOMPIImageHierarchy.txt")
set(vtkIOMPIImage_KIT "vtkParallel")
set(vtkIOMPIImage_TARGETS_FILE "")
set(vtkIOMPIImage_IMPLEMENTS "vtkIOImage")


