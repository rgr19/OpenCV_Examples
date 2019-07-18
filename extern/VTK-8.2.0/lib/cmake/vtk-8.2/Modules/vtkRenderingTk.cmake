set(vtkRenderingTk_LOADED 1)
set(vtkRenderingTk_DEPENDS "vtkCommonCore;vtkCommonDataModel;vtkCommonExecutionModel;vtkInteractionImage;vtkRenderingCore;vtkRenderingOpenGL2;vtkTclTk")
set(vtkRenderingTk_LIBRARIES "vtkCommonCore;vtkInteractionImage;vtkRenderingCore;vtkRenderingOpenGL2")
set(vtkRenderingTk_INCLUDE_DIRS "${VTK_INSTALL_PREFIX}/include/vtk-8.2")
set(vtkRenderingTk_LIBRARY_DIRS "")
set(vtkRenderingTk_RUNTIME_LIBRARY_DIRS "${VTK_INSTALL_PREFIX}/lib")
set(vtkRenderingTk_WRAP_HIERARCHY_FILE "${CMAKE_CURRENT_LIST_DIR}/vtkRenderingTkHierarchy.txt")
set(vtkRenderingTk_KIT "")
set(vtkRenderingTk_TARGETS_FILE "")
set(vtkRenderingTk_EXCLUDE_FROM_WRAPPING 1)


