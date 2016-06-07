#-------------------------------------------------
#
# Project created by QtCreator 2016-04-21T17:17:31
#
#-------------------------------------------------

QT       += core gui printsupport
CONFIG   += c++11

QMAKE_CXXFLAGS += -std=c++11
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OptimalFiltering
TEMPLATE = app




RESOURCES += \
    Gui/resources.qrc

DISTFILES += \
    Gui/formula_style.css \
    Libs/QCustomPlot/changelog.txt \
    Libs/QCustomPlot/GPL.txt \
    Libs/Eigen/src/Cholesky/CMakeLists.txt \
    Libs/Eigen/src/CholmodSupport/CMakeLists.txt \
    Libs/Eigen/src/Core/arch/AltiVec/CMakeLists.txt \
    Libs/Eigen/src/Core/arch/Default/CMakeLists.txt \
    Libs/Eigen/src/Core/arch/NEON/CMakeLists.txt \
    Libs/Eigen/src/Core/arch/SSE/CMakeLists.txt \
    Libs/Eigen/src/Core/arch/CMakeLists.txt \
    Libs/Eigen/src/Core/products/CMakeLists.txt \
    Libs/Eigen/src/Core/util/CMakeLists.txt \
    Libs/Eigen/src/Core/CMakeLists.txt \
    Libs/Eigen/src/Eigen2Support/Geometry/CMakeLists.txt \
    Libs/Eigen/src/Eigen2Support/CMakeLists.txt \
    Libs/Eigen/src/Eigenvalues/CMakeLists.txt \
    Libs/Eigen/src/Geometry/arch/CMakeLists.txt \
    Libs/Eigen/src/Geometry/CMakeLists.txt \
    Libs/Eigen/src/Householder/CMakeLists.txt \
    Libs/Eigen/src/IterativeLinearSolvers/CMakeLists.txt \
    Libs/Eigen/src/Jacobi/CMakeLists.txt \
    Libs/Eigen/src/LU/arch/CMakeLists.txt \
    Libs/Eigen/src/LU/CMakeLists.txt \
    Libs/Eigen/src/MetisSupport/CMakeLists.txt \
    Libs/Eigen/src/misc/CMakeLists.txt \
    Libs/Eigen/src/OrderingMethods/CMakeLists.txt \
    Libs/Eigen/src/PardisoSupport/CMakeLists.txt \
    Libs/Eigen/src/PaStiXSupport/CMakeLists.txt \
    Libs/Eigen/src/plugins/CMakeLists.txt \
    Libs/Eigen/src/QR/CMakeLists.txt \
    Libs/Eigen/src/SparseCholesky/CMakeLists.txt \
    Libs/Eigen/src/SparseCore/CMakeLists.txt \
    Libs/Eigen/src/SparseLU/CMakeLists.txt \
    Libs/Eigen/src/SparseQR/CMakeLists.txt \
    Libs/Eigen/src/SPQRSupport/CMakeLists.txt \
    Libs/Eigen/src/StlSupport/CMakeLists.txt \
    Libs/Eigen/src/SuperLUSupport/CMakeLists.txt \
    Libs/Eigen/src/SVD/CMakeLists.txt \
    Libs/Eigen/src/UmfPackSupport/CMakeLists.txt \
    Libs/Eigen/src/CMakeLists.txt \
    Libs/Eigen/CMakeLists.txt \
    README.md

HEADERS += \
    Core/array.h \
    Core/bvp.h \
    Core/core_base.h \
    Core/linear_algebra.h \
    Core/matrix.h \
    Core/ode.h \
    Core/prng.h \
    Core/stochastic.h \
    Filters/Continuous/c_aof.h \
    Filters/Continuous/c_fos.h \
    Filters/Continuous/continuous_filter.h \
    Filters/ContinuousDiscrete/cd_aof.h \
    Filters/ContinuousDiscrete/cd_dfos.h \
    Filters/ContinuousDiscrete/cd_dfosbo.h \
    Filters/ContinuousDiscrete/cd_fos.h \
    Filters/ContinuousDiscrete/continuous_discrete_filter.h \
    Filters/Discrete/discrete_filter.h \
    Filters/filter.h \
    Filters/filter_factory.h \
    Filters/filter_output.h \
    Filters/filter_parameters.h \
    Filters/filters.h \
    Gui/filter_parameters_widget.h \
    Gui/filter_start_buttons_box.h \
    Gui/font_manager.h \
    Gui/graph_sheet.h \
    Gui/graph_window.h \
    Gui/main_window.h \
    Gui/ranges_dialog.h \
    Gui/specific_parameters_window.h \
    Gui/task_widget.h \
    Libs/Eigen/src/Cholesky/LDLT.h \
    Libs/Eigen/src/Cholesky/LLT.h \
    Libs/Eigen/src/Cholesky/LLT_MKL.h \
    Libs/Eigen/src/CholmodSupport/CholmodSupport.h \
    Libs/Eigen/src/Core/arch/AltiVec/Complex.h \
    Libs/Eigen/src/Core/arch/AltiVec/PacketMath.h \
    Libs/Eigen/src/Core/arch/Default/Settings.h \
    Libs/Eigen/src/Core/arch/NEON/Complex.h \
    Libs/Eigen/src/Core/arch/NEON/PacketMath.h \
    Libs/Eigen/src/Core/arch/SSE/Complex.h \
    Libs/Eigen/src/Core/arch/SSE/MathFunctions.h \
    Libs/Eigen/src/Core/arch/SSE/PacketMath.h \
    Libs/Eigen/src/Core/products/CoeffBasedProduct.h \
    Libs/Eigen/src/Core/products/GeneralBlockPanelKernel.h \
    Libs/Eigen/src/Core/products/GeneralMatrixMatrix.h \
    Libs/Eigen/src/Core/products/GeneralMatrixMatrix_MKL.h \
    Libs/Eigen/src/Core/products/GeneralMatrixMatrixTriangular.h \
    Libs/Eigen/src/Core/products/GeneralMatrixMatrixTriangular_MKL.h \
    Libs/Eigen/src/Core/products/GeneralMatrixVector.h \
    Libs/Eigen/src/Core/products/GeneralMatrixVector_MKL.h \
    Libs/Eigen/src/Core/products/Parallelizer.h \
    Libs/Eigen/src/Core/products/SelfadjointMatrixMatrix.h \
    Libs/Eigen/src/Core/products/SelfadjointMatrixMatrix_MKL.h \
    Libs/Eigen/src/Core/products/SelfadjointMatrixVector.h \
    Libs/Eigen/src/Core/products/SelfadjointMatrixVector_MKL.h \
    Libs/Eigen/src/Core/products/SelfadjointProduct.h \
    Libs/Eigen/src/Core/products/SelfadjointRank2Update.h \
    Libs/Eigen/src/Core/products/TriangularMatrixMatrix.h \
    Libs/Eigen/src/Core/products/TriangularMatrixMatrix_MKL.h \
    Libs/Eigen/src/Core/products/TriangularMatrixVector.h \
    Libs/Eigen/src/Core/products/TriangularMatrixVector_MKL.h \
    Libs/Eigen/src/Core/products/TriangularSolverMatrix.h \
    Libs/Eigen/src/Core/products/TriangularSolverMatrix_MKL.h \
    Libs/Eigen/src/Core/products/TriangularSolverVector.h \
    Libs/Eigen/src/Core/util/BlasUtil.h \
    Libs/Eigen/src/Core/util/Constants.h \
    Libs/Eigen/src/Core/util/DisableStupidWarnings.h \
    Libs/Eigen/src/Core/util/ForwardDeclarations.h \
    Libs/Eigen/src/Core/util/Macros.h \
    Libs/Eigen/src/Core/util/Memory.h \
    Libs/Eigen/src/Core/util/Meta.h \
    Libs/Eigen/src/Core/util/MKL_support.h \
    Libs/Eigen/src/Core/util/NonMPL2.h \
    Libs/Eigen/src/Core/util/ReenableStupidWarnings.h \
    Libs/Eigen/src/Core/util/StaticAssert.h \
    Libs/Eigen/src/Core/util/XprHelper.h \
    Libs/Eigen/src/Core/Array.h \
    Libs/Eigen/src/Core/ArrayBase.h \
    Libs/Eigen/src/Core/ArrayWrapper.h \
    Libs/Eigen/src/Core/Assign.h \
    Libs/Eigen/src/Core/Assign_MKL.h \
    Libs/Eigen/src/Core/BandMatrix.h \
    Libs/Eigen/src/Core/Block.h \
    Libs/Eigen/src/Core/BooleanRedux.h \
    Libs/Eigen/src/Core/CommaInitializer.h \
    Libs/Eigen/src/Core/CoreIterators.h \
    Libs/Eigen/src/Core/CwiseBinaryOp.h \
    Libs/Eigen/src/Core/CwiseNullaryOp.h \
    Libs/Eigen/src/Core/CwiseUnaryOp.h \
    Libs/Eigen/src/Core/CwiseUnaryView.h \
    Libs/Eigen/src/Core/DenseBase.h \
    Libs/Eigen/src/Core/DenseCoeffsBase.h \
    Libs/Eigen/src/Core/DenseStorage.h \
    Libs/Eigen/src/Core/Diagonal.h \
    Libs/Eigen/src/Core/DiagonalMatrix.h \
    Libs/Eigen/src/Core/DiagonalProduct.h \
    Libs/Eigen/src/Core/Dot.h \
    Libs/Eigen/src/Core/EigenBase.h \
    Libs/Eigen/src/Core/Flagged.h \
    Libs/Eigen/src/Core/ForceAlignedAccess.h \
    Libs/Eigen/src/Core/Functors.h \
    Libs/Eigen/src/Core/Fuzzy.h \
    Libs/Eigen/src/Core/GeneralProduct.h \
    Libs/Eigen/src/Core/GenericPacketMath.h \
    Libs/Eigen/src/Core/GlobalFunctions.h \
    Libs/Eigen/src/Core/IO.h \
    Libs/Eigen/src/Core/Map.h \
    Libs/Eigen/src/Core/MapBase.h \
    Libs/Eigen/src/Core/MathFunctions.h \
    Libs/Eigen/src/Core/Matrix.h \
    Libs/Eigen/src/Core/MatrixBase.h \
    Libs/Eigen/src/Core/NestByValue.h \
    Libs/Eigen/src/Core/NoAlias.h \
    Libs/Eigen/src/Core/NumTraits.h \
    Libs/Eigen/src/Core/PermutationMatrix.h \
    Libs/Eigen/src/Core/PlainObjectBase.h \
    Libs/Eigen/src/Core/ProductBase.h \
    Libs/Eigen/src/Core/Random.h \
    Libs/Eigen/src/Core/Redux.h \
    Libs/Eigen/src/Core/Ref.h \
    Libs/Eigen/src/Core/Replicate.h \
    Libs/Eigen/src/Core/ReturnByValue.h \
    Libs/Eigen/src/Core/Reverse.h \
    Libs/Eigen/src/Core/Select.h \
    Libs/Eigen/src/Core/SelfAdjointView.h \
    Libs/Eigen/src/Core/SelfCwiseBinaryOp.h \
    Libs/Eigen/src/Core/SolveTriangular.h \
    Libs/Eigen/src/Core/StableNorm.h \
    Libs/Eigen/src/Core/Stride.h \
    Libs/Eigen/src/Core/Swap.h \
    Libs/Eigen/src/Core/Transpose.h \
    Libs/Eigen/src/Core/Transpositions.h \
    Libs/Eigen/src/Core/TriangularMatrix.h \
    Libs/Eigen/src/Core/VectorBlock.h \
    Libs/Eigen/src/Core/VectorwiseOp.h \
    Libs/Eigen/src/Core/Visitor.h \
    Libs/Eigen/src/Eigen2Support/Geometry/AlignedBox.h \
    Libs/Eigen/src/Eigen2Support/Geometry/All.h \
    Libs/Eigen/src/Eigen2Support/Geometry/AngleAxis.h \
    Libs/Eigen/src/Eigen2Support/Geometry/Hyperplane.h \
    Libs/Eigen/src/Eigen2Support/Geometry/ParametrizedLine.h \
    Libs/Eigen/src/Eigen2Support/Geometry/Quaternion.h \
    Libs/Eigen/src/Eigen2Support/Geometry/Rotation2D.h \
    Libs/Eigen/src/Eigen2Support/Geometry/RotationBase.h \
    Libs/Eigen/src/Eigen2Support/Geometry/Scaling.h \
    Libs/Eigen/src/Eigen2Support/Geometry/Transform.h \
    Libs/Eigen/src/Eigen2Support/Geometry/Translation.h \
    Libs/Eigen/src/Eigen2Support/Block.h \
    Libs/Eigen/src/Eigen2Support/Cwise.h \
    Libs/Eigen/src/Eigen2Support/CwiseOperators.h \
    Libs/Eigen/src/Eigen2Support/Lazy.h \
    Libs/Eigen/src/Eigen2Support/LeastSquares.h \
    Libs/Eigen/src/Eigen2Support/LU.h \
    Libs/Eigen/src/Eigen2Support/Macros.h \
    Libs/Eigen/src/Eigen2Support/MathFunctions.h \
    Libs/Eigen/src/Eigen2Support/Memory.h \
    Libs/Eigen/src/Eigen2Support/Meta.h \
    Libs/Eigen/src/Eigen2Support/Minor.h \
    Libs/Eigen/src/Eigen2Support/QR.h \
    Libs/Eigen/src/Eigen2Support/SVD.h \
    Libs/Eigen/src/Eigen2Support/TriangularSolver.h \
    Libs/Eigen/src/Eigen2Support/VectorBlock.h \
    Libs/Eigen/src/Eigenvalues/ComplexEigenSolver.h \
    Libs/Eigen/src/Eigenvalues/ComplexSchur.h \
    Libs/Eigen/src/Eigenvalues/ComplexSchur_MKL.h \
    Libs/Eigen/src/Eigenvalues/EigenSolver.h \
    Libs/Eigen/src/Eigenvalues/GeneralizedEigenSolver.h \
    Libs/Eigen/src/Eigenvalues/GeneralizedSelfAdjointEigenSolver.h \
    Libs/Eigen/src/Eigenvalues/HessenbergDecomposition.h \
    Libs/Eigen/src/Eigenvalues/MatrixBaseEigenvalues.h \
    Libs/Eigen/src/Eigenvalues/RealQZ.h \
    Libs/Eigen/src/Eigenvalues/RealSchur.h \
    Libs/Eigen/src/Eigenvalues/RealSchur_MKL.h \
    Libs/Eigen/src/Eigenvalues/SelfAdjointEigenSolver.h \
    Libs/Eigen/src/Eigenvalues/SelfAdjointEigenSolver_MKL.h \
    Libs/Eigen/src/Eigenvalues/Tridiagonalization.h \
    Libs/Eigen/src/Geometry/arch/Geometry_SSE.h \
    Libs/Eigen/src/Geometry/AlignedBox.h \
    Libs/Eigen/src/Geometry/AngleAxis.h \
    Libs/Eigen/src/Geometry/EulerAngles.h \
    Libs/Eigen/src/Geometry/Homogeneous.h \
    Libs/Eigen/src/Geometry/Hyperplane.h \
    Libs/Eigen/src/Geometry/OrthoMethods.h \
    Libs/Eigen/src/Geometry/ParametrizedLine.h \
    Libs/Eigen/src/Geometry/Quaternion.h \
    Libs/Eigen/src/Geometry/Rotation2D.h \
    Libs/Eigen/src/Geometry/RotationBase.h \
    Libs/Eigen/src/Geometry/Scaling.h \
    Libs/Eigen/src/Geometry/Transform.h \
    Libs/Eigen/src/Geometry/Translation.h \
    Libs/Eigen/src/Geometry/Umeyama.h \
    Libs/Eigen/src/Householder/BlockHouseholder.h \
    Libs/Eigen/src/Householder/Householder.h \
    Libs/Eigen/src/Householder/HouseholderSequence.h \
    Libs/Eigen/src/IterativeLinearSolvers/BasicPreconditioners.h \
    Libs/Eigen/src/IterativeLinearSolvers/BiCGSTAB.h \
    Libs/Eigen/src/IterativeLinearSolvers/ConjugateGradient.h \
    Libs/Eigen/src/IterativeLinearSolvers/IncompleteLUT.h \
    Libs/Eigen/src/IterativeLinearSolvers/IterativeSolverBase.h \
    Libs/Eigen/src/Jacobi/Jacobi.h \
    Libs/Eigen/src/LU/arch/Inverse_SSE.h \
    Libs/Eigen/src/LU/Determinant.h \
    Libs/Eigen/src/LU/FullPivLU.h \
    Libs/Eigen/src/LU/Inverse.h \
    Libs/Eigen/src/LU/PartialPivLU.h \
    Libs/Eigen/src/LU/PartialPivLU_MKL.h \
    Libs/Eigen/src/MetisSupport/MetisSupport.h \
    Libs/Eigen/src/misc/blas.h \
    Libs/Eigen/src/misc/Image.h \
    Libs/Eigen/src/misc/Kernel.h \
    Libs/Eigen/src/misc/Solve.h \
    Libs/Eigen/src/misc/SparseSolve.h \
    Libs/Eigen/src/OrderingMethods/Amd.h \
    Libs/Eigen/src/OrderingMethods/Eigen_Colamd.h \
    Libs/Eigen/src/OrderingMethods/Ordering.h \
    Libs/Eigen/src/PardisoSupport/PardisoSupport.h \
    Libs/Eigen/src/PaStiXSupport/PaStiXSupport.h \
    Libs/Eigen/src/plugins/ArrayCwiseBinaryOps.h \
    Libs/Eigen/src/plugins/ArrayCwiseUnaryOps.h \
    Libs/Eigen/src/plugins/BlockMethods.h \
    Libs/Eigen/src/plugins/CommonCwiseBinaryOps.h \
    Libs/Eigen/src/plugins/CommonCwiseUnaryOps.h \
    Libs/Eigen/src/plugins/MatrixCwiseBinaryOps.h \
    Libs/Eigen/src/plugins/MatrixCwiseUnaryOps.h \
    Libs/Eigen/src/QR/ColPivHouseholderQR.h \
    Libs/Eigen/src/QR/ColPivHouseholderQR_MKL.h \
    Libs/Eigen/src/QR/FullPivHouseholderQR.h \
    Libs/Eigen/src/QR/HouseholderQR.h \
    Libs/Eigen/src/QR/HouseholderQR_MKL.h \
    Libs/Eigen/src/SparseCholesky/SimplicialCholesky.h \
    Libs/Eigen/src/SparseCholesky/SimplicialCholesky_impl.h \
    Libs/Eigen/src/SparseCore/AmbiVector.h \
    Libs/Eigen/src/SparseCore/CompressedStorage.h \
    Libs/Eigen/src/SparseCore/ConservativeSparseSparseProduct.h \
    Libs/Eigen/src/SparseCore/MappedSparseMatrix.h \
    Libs/Eigen/src/SparseCore/SparseBlock.h \
    Libs/Eigen/src/SparseCore/SparseColEtree.h \
    Libs/Eigen/src/SparseCore/SparseCwiseBinaryOp.h \
    Libs/Eigen/src/SparseCore/SparseCwiseUnaryOp.h \
    Libs/Eigen/src/SparseCore/SparseDenseProduct.h \
    Libs/Eigen/src/SparseCore/SparseDiagonalProduct.h \
    Libs/Eigen/src/SparseCore/SparseDot.h \
    Libs/Eigen/src/SparseCore/SparseFuzzy.h \
    Libs/Eigen/src/SparseCore/SparseMatrix.h \
    Libs/Eigen/src/SparseCore/SparseMatrixBase.h \
    Libs/Eigen/src/SparseCore/SparsePermutation.h \
    Libs/Eigen/src/SparseCore/SparseProduct.h \
    Libs/Eigen/src/SparseCore/SparseRedux.h \
    Libs/Eigen/src/SparseCore/SparseSelfAdjointView.h \
    Libs/Eigen/src/SparseCore/SparseSparseProductWithPruning.h \
    Libs/Eigen/src/SparseCore/SparseTranspose.h \
    Libs/Eigen/src/SparseCore/SparseTriangularView.h \
    Libs/Eigen/src/SparseCore/SparseUtil.h \
    Libs/Eigen/src/SparseCore/SparseVector.h \
    Libs/Eigen/src/SparseCore/SparseView.h \
    Libs/Eigen/src/SparseCore/TriangularSolver.h \
    Libs/Eigen/src/SparseLU/SparseLU.h \
    Libs/Eigen/src/SparseLU/SparseLU_column_bmod.h \
    Libs/Eigen/src/SparseLU/SparseLU_column_dfs.h \
    Libs/Eigen/src/SparseLU/SparseLU_copy_to_ucol.h \
    Libs/Eigen/src/SparseLU/SparseLU_gemm_kernel.h \
    Libs/Eigen/src/SparseLU/SparseLU_heap_relax_snode.h \
    Libs/Eigen/src/SparseLU/SparseLU_kernel_bmod.h \
    Libs/Eigen/src/SparseLU/SparseLU_Memory.h \
    Libs/Eigen/src/SparseLU/SparseLU_panel_bmod.h \
    Libs/Eigen/src/SparseLU/SparseLU_panel_dfs.h \
    Libs/Eigen/src/SparseLU/SparseLU_pivotL.h \
    Libs/Eigen/src/SparseLU/SparseLU_pruneL.h \
    Libs/Eigen/src/SparseLU/SparseLU_relax_snode.h \
    Libs/Eigen/src/SparseLU/SparseLU_Structs.h \
    Libs/Eigen/src/SparseLU/SparseLU_SupernodalMatrix.h \
    Libs/Eigen/src/SparseLU/SparseLU_Utils.h \
    Libs/Eigen/src/SparseLU/SparseLUImpl.h \
    Libs/Eigen/src/SparseQR/SparseQR.h \
    Libs/Eigen/src/SPQRSupport/SuiteSparseQRSupport.h \
    Libs/Eigen/src/StlSupport/details.h \
    Libs/Eigen/src/StlSupport/StdDeque.h \
    Libs/Eigen/src/StlSupport/StdList.h \
    Libs/Eigen/src/StlSupport/StdVector.h \
    Libs/Eigen/src/SuperLUSupport/SuperLUSupport.h \
    Libs/Eigen/src/SVD/JacobiSVD.h \
    Libs/Eigen/src/SVD/JacobiSVD_MKL.h \
    Libs/Eigen/src/SVD/UpperBidiagonalization.h \
    Libs/Eigen/src/UmfPackSupport/UmfPackSupport.h \
    Libs/Eigen/Array \
    Libs/Eigen/Cholesky \
    Libs/Eigen/CholmodSupport \
    Libs/Eigen/Core \
    Libs/Eigen/Dense \
    Libs/Eigen/Eigen \
    Libs/Eigen/Eigen2Support \
    Libs/Eigen/Eigenvalues \
    Libs/Eigen/Geometry \
    Libs/Eigen/Householder \
    Libs/Eigen/IterativeLinearSolvers \
    Libs/Eigen/Jacobi \
    Libs/Eigen/LeastSquares \
    Libs/Eigen/LU \
    Libs/Eigen/MetisSupport \
    Libs/Eigen/OrderingMethods \
    Libs/Eigen/PardisoSupport \
    Libs/Eigen/PaStiXSupport \
    Libs/Eigen/QR \
    Libs/Eigen/QtAlignedMalloc \
    Libs/Eigen/Sparse \
    Libs/Eigen/SparseCholesky \
    Libs/Eigen/SparseCore \
    Libs/Eigen/SparseLU \
    Libs/Eigen/SparseQR \
    Libs/Eigen/SPQRSupport \
    Libs/Eigen/StdDeque \
    Libs/Eigen/StdList \
    Libs/Eigen/StdVector \
    Libs/Eigen/SuperLUSupport \
    Libs/Eigen/SVD \
    Libs/Eigen/UmfPackSupport \
    Libs/QCustomPlot/qcustomplot.h \
    Tasks/Continuous/c_van_der_pol_gauss.h \
    Tasks/Continuous/c_van_der_pol_linear.h \
    Tasks/Continuous/continuous_task.h \
    Tasks/ContinuousDiscrete/cd_landing_gauss.h \
    Tasks/ContinuousDiscrete/cd_landing_linear.h \
    Tasks/ContinuousDiscrete/cd_van_der_pol_gauss.h \
    Tasks/ContinuousDiscrete/cd_van_der_pol_linear.h \
    Tasks/ContinuousDiscrete/continuous_discrete_task.h \
    Tasks/Discrete/d_landing_gauss.h \
    Tasks/Discrete/d_landing_linear.h \
    Tasks/Discrete/d_van_der_pol_gauss.h \
    Tasks/Discrete/d_van_der_pol_linear.h \
    Tasks/Discrete/discrete_task.h \
    Tasks/specific_parameters.h \
    Tasks/task.h \
    Tasks/tasks.h \
    Filters/Discrete/d_fos.h \
    Filters/function_time.h \
    Tasks/Continuous/c_landing_linear.h \
    Tasks/Continuous/c_landing_gauss.h

SOURCES += \
    Core/bvp.cc \
    Core/linear_algebra.cc \
    Core/prng.cc \
    Core/stochastic.cc \
    Filters/Continuous/c_aof.cc \
    Filters/Continuous/c_fos.cc \
    Filters/Continuous/continuous_filter.cc \
    Filters/ContinuousDiscrete/cd_aof.cc \
    Filters/ContinuousDiscrete/cd_dfos.cc \
    Filters/ContinuousDiscrete/cd_dfosbo.cc \
    Filters/ContinuousDiscrete/cd_fos.cc \
    Filters/ContinuousDiscrete/continuous_discrete_filter.cc \
    Filters/Discrete/discrete_filter.cc \
    Filters/filter.cc \
    Filters/filter_factory.cc \
    Filters/filter_parameters.cc \
    Gui/filter_parameters_widget.cc \
    Gui/filter_start_buttons_box.cc \
    Gui/font_manager.cc \
    Gui/graph_sheet.cc \
    Gui/graph_window.cc \
    Gui/main_window.cc \
    Gui/ranges_dialog.cc \
    Gui/specific_parameters_window.cc \
    Gui/task_widget.cc \
    Libs/QCustomPlot/qcustomplot.cc \
    Tasks/Continuous/c_van_der_pol_gauss.cc \
    Tasks/Continuous/c_van_der_pol_linear.cc \
    Tasks/ContinuousDiscrete/cd_landing_gauss.cc \
    Tasks/ContinuousDiscrete/cd_landing_linear.cc \
    Tasks/ContinuousDiscrete/cd_van_der_pol_gauss.cc \
    Tasks/ContinuousDiscrete/cd_van_der_pol_linear.cc \
    Tasks/Discrete/d_landing_gauss.cc \
    Tasks/Discrete/d_landing_linear.cc \
    Tasks/Discrete/d_van_der_pol_gauss.cc \
    Tasks/Discrete/d_van_der_pol_linear.cc \
    Tasks/specific_parameters.cc \
    Tasks/task.cc \
    main.cc \
    Filters/Discrete/d_fos.cc \
    Filters/function_time.cc \
    Tasks/Continuous/continuouse_task.cc \
    Tasks/Continuous/c_landing_linear.cc \
    Tasks/Continuous/c_landing_gauss.cc
