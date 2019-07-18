set(vtkFiltersParallelMPI_LOADED 1)
set(vtkFiltersParallelMPI_DEPENDS "vtkCommonCore;vtkCommonDataModel;vtkCommonExecutionModel;vtkCommonSystem;vtkFiltersExtraction;vtkFiltersGeneral;vtkFiltersParallel;vtkIOLegacy;vtkImagingCore;vtkParallelCore;vtkParallelMPI")
set(vtkFiltersParallelMPI_LIBRARIES "vtkFiltersParallelMPI")
set(vtkFiltersParallelMPI_INCLUDE_DIRS "${VTK_INSTALL_PREFIX}/include/vtk-8.2")
set(vtkFiltersParallelMPI_LIBRARY_DIRS "")
set(vtkFiltersParallelMPI_RUNTIME_LIBRARY_DIRS "${VTK_INSTALL_PREFIX}/lib")
set(vtkFiltersParallelMPI_WRAP_HIERARCHY_FILE "${CMAKE_CURRENT_LIST_DIR}/vtkFiltersParallelMPIHierarchy.txt")
set(vtkFiltersParallelMPI_KIT "vtkParallel")
set(vtkFiltersParallelMPI_TARGETS_FILE "")


