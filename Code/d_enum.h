/************************************
 *   added:     04.12.2018          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_ENUM_H
#define D_ENUM_H

#include <QStringList>
#include <QString>
#include <complex>
#include <vector>

const QString           D_QS_State    = "release";
const QString           D_QS_Version  = "v2_1_6";
const QString           D_QS_Release  = "26.10.2021";
const QString           D_QS_Author   = "David Eilenstein";
const QString           D_QS_Facility = "GSI Darmstadt";

enum D_PLUGINS {
    c_PL_FOCI_CYTO_NUCLEI,
    c_PL_MITOCHONDRIA,
    c_PL_EILENSTEIN,
    c_PL_CELL_COLONIES,
    c_PL_FOCI_TRACKING,
    c_PL_ION_TRACKS,
    c_PL_TIF_VISUALIZER,
    c_PL_OSTEOCLASTS,
    c_PL_DNA_FIBERS,
    c_PL_RADON_CURVE_FITTING,
    c_PL_SEGMENTATION_ASSISTANT,
    c_PL_CEREBRAL_ORGANOIDS,
    c_PL_MANUEL_SEGMANTATION,
    c_PL_CILIA_SPHERE_TRACKER,
    c_PL_FOURIER_TRANSFORMATOR,
    c_PL_AIR_DRAG_DETECT,
    c_PL_MEGA_FOCI,
    c_PL_HUANG_VIS,
    c_PL_SOFTMAX,
    c_PL_NUMBER_OF
};
const QStringList QSL_Plugins = {
    "Cytoplasmatic dsDNA detection",
    "Mitochondria NADH/NADPH Ratio",
    "Eilenstein filter",
    "Cell colony size",
    "Nuclear foci tracking",
    "Ion tracks intensity profiles",
    "Multipaged TIF visualizer",
    "Osteoclasts semiautomatic segmentation (WIP)",
    "DNA fiber thickness",
    "Radon decay curve fitting",
    "Segmentation assistant (WIP)",
    "Cerebral organoids size distribution",
    "Manuel Segmentation",
    "Cilia Microsphere Tracker",
    "Fourier Transformator (WIP)",
    "Air Drag Detect",
    "Mega Foci tracker (WIP)",
    "Huang rank order filter visualization",
    "Softmax Classifier Visualization"
};

//default dir indices
enum default_dirs
{
    dir_DEFAULT,
    dir_LOAD,
    dir_SAVE,
    dir_M_DSDNA,
    dir_M_MITO,
    dir_M_EILEN,
    dir_EXAMPLE,
    dir_STEPS,
    dir_M_CELLCOL,
    dir_M_FOCITIME,
    dir_ANALYZER,
    dir_TEST,
    dir_M_TRACKS,
    dir_M_VIS,
    dir_M_OSTEO,
    dir_M_DNAFIBER,
    dir_M_RADONFIT,
    dir_M_SEGASSI,
    dir_M_CEREB,
    dir_M_MANSEG,
    dir_M_CILTRACK,
    dir_M_FOURIER,
    dir_M_AIRDRAG,
    dir_M_MEGAFOCI_IMG,
    dir_M_HUANG,
    dir_M_SOFTMAX,
    dir_M_MEGAFOCI_RES,
    dir_NUMBER_OF
};

enum D_NUMBER_TYPE {
    c_NUMBER_TYPE_UCHAR,
    c_NUMBER_TYPE_CHAR,
    c_NUMBER_TYPE_USHORT,
    c_NUMBER_TYPE_SHORT,
    c_NUMBER_TYPE_UINT,
    c_NUMBER_TYPE_INT,
    c_NUMBER_TYPE_FLOAT,
    c_NUMBER_TYPE_DOUBLE,
    c_NUMBER_TYPE_NUMBER_OF
};
const QStringList QSL_Number_Type = {
    "uchar",
    "char",
    "ushort",
    "short",
    "uint",
    "int",
    "float",
    "double"
};

enum D_STEP_WINDOW_DEFAULTS {
    c_SD_AUTOUPDATE_ON_SETTINGS,
    c_SD_AUTOUPDATE_SKIP,
    c_SD_CONNECT_PLANE,
    c_SD_CONNECT_ZOOM,
    c_SD_VIEWER_TRANSFORMATION_SMOOTH,
    c_SD_VIEWER_ASPECT_KEEP,
    c_SD_NUMBER_OF
};

enum D_ERROR_ENUM {
    ER_okay,
    ER_other,
    ER_empty,
    ER_type_bad,
    ER_type_missmatch,
    ER_bitdepth_bad,
    ER_bitdepth_missmatch,
    ER_size_bad,
    ER_size_missmatch,
    ER_parameter_bad,
    ER_parameter_missmatch,
    ER_channel_bad,
    ER_channel_missmatch,
    ER_index_out_of_range,
    ER_dim_out_of_range,
    ER_dim_missmatch,
    ER_dim_X_out_of_range,
    ER_dim_X_missmatch,
    ER_dim_Y_out_of_range,
    ER_dim_Y_missmatch,
    ER_dim_Z_out_of_range,
    ER_dim_Z_missmatch,
    ER_dim_T_out_of_range,
    ER_dim_T_missmatch,
    ER_dim_S_out_of_range,
    ER_dim_S_missmatch,
    ER_dim_P_out_of_range,
    ER_dim_P_missmatch,
    ER_file_not_exist,
    ER_list_empty,
    ER_dim_1D_only,
    ER_dim_2D_only,
    ER_dim_3D_only,
    ER_VideoCaptureClosed,
    ER_StitcherFail,
    ER_SpecialDimPartOfProcPlane,
    ER_MatrixNotInvertable,
    ER_SizeUnknown,
    ER_PoitsUnknown,
    ER_KeypoitsUnknown,
    ER_DescriptorsUnkown,
    ER_StreamNotOpen,
    ER_NumericProblem,
    ER_UiAllreadyInit,
    ER_UiNotInit,
    ER_UiPutInFail,
    ER_ThreadIssue,
    ER_MemSizeToBig,
    ER_number_of
};
const QStringList QSL_Errors = {
    "okay",
    "other",
    "data empty",
    "type not suported",
    "types missmatch",
    "bitdepth not supported",
    "bitdepth missmatch",
    "size not supported",
    "sizes missmatch",
    "parameter not supported",
    "parameter missmatch",
    "channels not supported",
    "channels missmatch",
    "index out of range",
    "dimension index out of range",
    "dimension missmatch",
    "X index out of range",
    "X dimensions missmatch",
    "Y index out of range",
    "Y dimensions missmatch",
    "Z index out of range",
    "Z dimensions missmatch",
    "T index out of range",
    "T dimensions missmatch",
    "S index out of range",
    "S dimensions missmatch",
    "P index out of range",
    "P dimensions missmatch",
    "file does not exist",
    "list empty",
    "only supported for 1D processing",
    "only supported for 2D processing",
    "only supported for 3D processing",
    "video capture not open",
    "stitcher failed",
    "dimension with special role can not be part of processing plane",
    "Matrix is not invertable",
    "Size unknwon",
    "Points unknown",
    "Keypoints unknwon",
    "Descriptors unknown",
    "Stream not open",
    "Numerical problem (+/-inf or nan)",
    "Ui is allready initialized",
    "Ui is not initialized",
    "Failed to put element in ui",
    "Thread issue",
    "Too much memory needed for object"
};

enum D_DIM_INDICES {
    c_DIM_X,
    c_DIM_Y,
    c_DIM_Z,
    c_DIM_T,
    c_DIM_S,
    c_DIM_P,
    c_DIM_NUMBER_OF
};
const QStringList QSL_DimNames = {
    "Colum",
    "Row",
    "Plane",
    "Time",
    "Set",
    "Page"
};
const QStringList QSL_DimIndices = {
    "X",
    "Y",
    "Z",
    "T",
    "S",
    "P"
};

enum D_SLICE {
    c_SLICE_1D_X,
    c_SLICE_1D_Y,
    c_SLICE_1D_Z,
    c_SLICE_1D_T,
    c_SLICE_1D_S,
    c_SLICE_1D_P,
    c_SLICE_2D_XY,
    c_SLICE_2D_XZ,
    c_SLICE_2D_YZ,
    c_SLICE_3D_XYZ,
    c_SLICE_3D_XYT,
    c_SLICE_4D_XYZT,
    c_SLICE_6D_ALL,
    c_SLICE_NUMBER_OF
};
const QStringList QSL_Slicing = {
    "1D X",
    "1D Y",
    "1D Z",
    "1D T",
    "1D S",
    "1D P",
    "2D XY",
    "2D XZ",
    "2D YZ",
    "3D XYZ",
    "3D XYT",
    "4D XYZT",
    "6D All"
};

enum D_PLANES {
    c_PLANE_XY,
    c_PLANE_XZ,
    c_PLANE_XT,
    c_PLANE_XS,
    c_PLANE_XP,
    c_PLANE_YZ,
    c_PLANE_YT,
    c_PLANE_YS,
    c_PLANE_YP,
    c_PLANE_ZT,
    c_PLANE_ZS,
    c_PLANE_ZP,
    c_PLANE_TS,
    c_PLANE_TP,
    c_PLANE_SP,
    c_PLANE_NUMBER_OF
};
const QStringList QSL_Planes {
    "XY",
    "XZ",
    "XT",
    "XS",
    "XP",
    "YZ",
    "YT",
    "YS",
    "YP",
    "ZT",
    "ZS",
    "ZP",
    "TS",
    "TP",
    "SP",
};

enum D_VOLUMES {
    c_VOLUME_XYZ,
    c_VOLUME_XYT,
    c_VOLUME_XYS,
    c_VOLUME_XYP,
    c_VOLUME_XZT,
    c_VOLUME_XZS,
    c_VOLUME_XZP,
    c_VOLUME_XTS,
    c_VOLUME_XTP,
    c_VOLUME_XSP,
    c_VOLUME_YZT,
    c_VOLUME_YZS,
    c_VOLUME_YZP,
    c_VOLUME_YTS,
    c_VOLUME_YTP,
    c_VOLUME_YSP,
    c_VOLUME_ZTS,
    c_VOLUME_ZTP,
    c_VOLUME_ZSP,
    c_VOLUME_TSP,
    c_VOLUME_NUMBER_OF
};
const QStringList QSL_Volumes = {
    "XYZ",
    "XYT",
    "XYS",
    "XYP",
    "XZT",
    "XZS",
    "XZP",
    "XTS",
    "XTP",
    "XSP",
    "YZT",
    "YZS",
    "YZP",
    "YTS",
    "YTP",
    "YSP",
    "ZTS",
    "ZTP",
    "ZSP",
    "TSP"
};

enum D_VIEWER_MODE {
    c_VIEWER_MODE_IMG,
    c_VIEWER_MODE_PLOT,
    c_VIEWER_MODE_NUMBER_OF
};
const QStringList QSL_ViewerMode = {
    "Image",
    "Plot"
};

enum D_PLOT_SIMPLE {
    c_PLOT_SIMPLE_POINT,
    c_PLOT_SIMPLE_LINE,
    c_PLOT_SIMPLE_LINE_POINT,
    c_PLOT_SIMPLE_SPLINE,
    c_PLOT_SIMPLE_SPLINE_POINT,
    c_PLOT_SIMPLE_NUMBER_OF
};
const QStringList QSL_PLOT_SIMPLE = {
    "Points",
    "Lines",
    "Lines and Points",
    "Splines",
    "Splines and Points"
};


enum D_VIEWER_PLOT_3D_MODE {
    c_VIEWER_PLOT_3D_MODE_SCATTER,
    c_VIEWER_PLOT_3D_MODE_HEIGHTMAP,
    //c_VIEWER_PLOT_3D_MODE_BAR,
    //c_VIEWER_PLOT_3D_MODE_MESH,
    c_VIEWER_PLOT_3D_MODE_NUMBER_OF
};
const QStringList QSL_Viewer3D_Mode = {
    "Scatter",
    "Heightmap"//,
    //"Bar",
    //"Mesh"
};

enum D_VIEWER_PLOT_3D_CONDITION {
    c_VIEWER_PLOT_3D_CONDITION_ALL,
    c_VIEWER_PLOT_3D_CONDITION_NOT_ZERO,
    c_VIEWER_PLOT_3D_CONDITION_NUMBER_OF
};
const QStringList QSL_Viewer3D_Condition = {
    "All",
    "!=0"
};

enum D_VIEWER_PLOT_3D_VALUE_HANDLING {
    c_VIEWER_PLOT_3D_VALUE_HANDLING_MONO,
    c_VIEWER_PLOT_3D_VALUE_HANDLING_GRAY,
    c_VIEWER_PLOT_3D_VALUE_HANDLING_HUE,
    c_VIEWER_PLOT_3D_VALUE_HANDLING_NUMBER_OF
};
const QStringList QSL_Viewer3D_ValueHandling = {
    "Mono",
    "Gray",
    "Heat"
};

enum D_VIEWER_PLOT_3D_AXIS {
    c_VIEWER_PLOT_3D_AXIS_EMPTY,
    c_VIEWER_PLOT_3D_AXIS_IMG_X,
    c_VIEWER_PLOT_3D_AXIS_IMG_Y,
    c_VIEWER_PLOT_3D_AXIS_IMG_Z,
    c_VIEWER_PLOT_3D_AXIS_IMG_T,
    c_VIEWER_PLOT_3D_AXIS_IMG_S,
    c_VIEWER_PLOT_3D_AXIS_IMG_P,
    c_VIEWER_PLOT_3D_AXIS_CHANNEL_0,
    c_VIEWER_PLOT_3D_AXIS_CHANNEL_1,
    c_VIEWER_PLOT_3D_AXIS_CHANNEL_2,
    c_VIEWER_PLOT_3D_AXIS_CHANNEL_3,
    c_VIEWER_PLOT_3D_AXIS_COLOR_GRAY,
    c_VIEWER_PLOT_3D_AXIS_COLOR_BLUE,
    c_VIEWER_PLOT_3D_AXIS_COLOR_GREEN,
    c_VIEWER_PLOT_3D_AXIS_COLOR_RED,
    c_VIEWER_PLOT_3D_AXIS_COLOR_HUE,
    c_VIEWER_PLOT_3D_AXIS_COLOR_SATURATION,
    c_VIEWER_PLOT_3D_AXIS_COLOR_VALUE,
    c_VIEWER_PLOT_3D_AXIS_INDEX,
    c_VIEWER_PLOT_3D_AXIS_NUMBER_OF
};
const QStringList QSL_Viewer3D_Axis = {
    "-",
    "X",
    "Y",
    "Z",
    "T",
    "S",
    "P",
    "Ch0",
    "Ch1",
    "Ch2",
    "Ch3",
    "Gray",
    "Blue",
    "Green",
    "Red",
    "Hue",
    "Saturation",
    "Value",
    "Index"
};

enum D_VIEWER_3D_ALPHA {
    c_VIEWER_3D_ALPHA_MAX,
    c_VIEWER_3D_ALPHA_CHANNEL_0,
    c_VIEWER_3D_ALPHA_CHANNEL_1,
    c_VIEWER_3D_ALPHA_CHANNEL_2,
    c_VIEWER_3D_ALPHA_CHANNEL_3,
    c_VIEWER_3D_ALPHA_CHANNEL_MIN,
    c_VIEWER_3D_ALPHA_CHANNEL_MAX,
    c_VIEWER_3D_ALPHA_CHANNEL_MEAN,
    c_VIEWER_3D_ALPHA_CHANNEL_SQUARE_MEAN,
    c_VIEWER_3D_ALPHA_NUMBER_OF
};
const QStringList QSL_Viewer3D_Alpha = {
    "Opac",
    "Channel 0",
    "Channel 1",
    "Channel 2",
    "Channel 3",
    "Channel Min",
    "Channel Max",
    "Channel Mean",
    "Ch. Square Mean"
};

enum D_VIEWER_PLOT_3D_TEXTURE {
    c_VIEWER_PLOT_3D_TEXTURE_MONO,
    c_VIEWER_PLOT_3D_TEXTURE_IMAGE,
    c_VIEWER_PLOT_3D_TEXTURE_GRAY,
    c_VIEWER_PLOT_3D_TEXTURE_HUE,
    c_VIEWER_PLOT_3D_TEXTURE_NUMBER_OF
};
const QStringList QSL_Viewer3D_Texture = {
    "Mono",
    "Image",
    "Gray",
    "Heat"
};

enum D_VIEWER_PLOT_3D_SURFACE_MODE {
    c_VIEWER_PLOT_3D_SURFACE_MODE_SINGLE,
    c_VIEWER_PLOT_3D_SURFACE_MODE_CHANNELS,
    c_VIEWER_PLOT_3D_SURFACE_MODE_DIMENSION,
    c_VIEWER_PLOT_3D_SURFACE_MODE_NUMBER_OF
};
const QStringList QSL_Viewer_3D_SurfaceMode = {
    "Single",
    "Channels",
    "Dimension"
};

enum D_VIEWER_PLOT_3D_MARKER_3D {
    c_VIEWER_PLOT_3D_MARKER_POINT,
    c_VIEWER_PLOT_3D_MARKER_MINIMAL,
    c_VIEWER_PLOT_3D_MARKER_PYRAMID,
    c_VIEWER_PLOT_3D_MARKER_CUBE,
    c_VIEWER_PLOT_3D_MARKER_CYLINDER,
    c_VIEWER_PLOT_3D_MARKER_SPHERE,
    c_VIEWER_PLOT_3D_MARKER_ARROW,
    c_VIEWER_PLOT_3D_MARKER_NUMBER_OF
};
const QStringList QSL_Marker_3D = {
    "Point",
    "Minimal",
    "Pyramid",
    "Cube",
    "Cylinder",
    "Sphere",
    "Arrow"
};

enum D_VIEWER_PLOT_3D_SHADOW_3D {
    c_VIEWER_PLOT_3D_SHADOW_NONE,
    c_VIEWER_PLOT_3D_SHADOW_LOW,
    c_VIEWER_PLOT_3D_SHADOW_MEDIUM,
    c_VIEWER_PLOT_3D_SHADOW_HIGH,
    c_VIEWER_PLOT_3D_SHADOW_SOFT_LOW,
    c_VIEWER_PLOT_3D_SHADOW_SOFT_MEDIUM,
    c_VIEWER_PLOT_3D_SHADOW_SOFT_HIGH,
    c_VIEWER_PLOT_3D_SHADOW_NUMBER_OF
};
const QStringList QSL_ShadowQuality_3D = {
    "None",
    "Low",
    "Medium",
    "High",
    "Soft Low",
    "Soft Medium",
    "Soft High"
};
const QStringList QSL_ShadowQuality_3D_ShadowInName = {
    "Shaodw None",
    "Shaodw Low",
    "Shaodw Medium",
    "Shaodw High",
    "Shaodw Soft Low",
    "Shaodw Soft Medium",
    "Shaodw Soft High"
};

enum D_LOAD_MODE {
    c_LOAD_MODE_FILE_IMAGE,
    c_LOAD_MODE_FILE_IMAGE_PAGED,
    c_LOAD_MODE_FILE_VIDEO,
    c_LOAD_MODE_FILELIST_IMAGE,
    c_LOAD_MODE_FILELIST_IMAGE_PAGED,
    c_LOAD_MODE_FILE_VISDAT,
    c_LOAD_MODE_NUMBER_OF
};
const QStringList QSL_LoadMode = {
    "File Image",
    "File Image Paged",
    "File Video",
    "Filelist Image",
    "Filelist Image Paged",
    "File .visdat"
};

enum D_WATERSHED_FILL {
    c_WATERSHED_FILL_MASK_DIST_INV,
    c_WATERSHED_FILL_MASK_DIST,
    c_WATERSHED_FILL_MASK_COPY,
    c_WATERSHED_FILL_SOURCE_COPY,
    c_WATERSHED_FILL_SOURCE_INV,
    c_WATERSHED_FILL_SOURCE_LOG,
    c_WATERSHED_FILL_SOURCE_MORPH_GRAD,
    c_WATERSHED_FILL_NUMBER_OF
};
const QStringList QSL_WatershedFill = {
    "Mask: Distance Invers",
    "Mask: Distance",
    "Mask: Unmodified",
    "Source: Unmodified",
    "Source: Inverted",
    "Source: Laplace of Gaussian",
    "Source: Morphological Gradient",
};

enum D_WATERSHED_MARKER {
    c_WATERSHED_MARKER_FILL_LOC_MIN,
    c_WATERSHED_MARKER_SOURCE_COPY,
    c_WATERSHED_MARKER_SOURCE_LABELED,
    c_WATERSHED_MARKER_SOURCE_LABELED_INV,
    c_WATERSHED_MARKER_NUMBER_OF
};
const QStringList QSL_WatershedMarker = {
    "Fill: Local Minima",
    "Source: Unmodified",
    "Source: Labeled",
    "Source: Inverted Labeled"
};

enum D_WATERSHED_MASK {
    c_WATERSHED_MASK_SOURCE_COPY,
    c_WATERSHED_MASK_SOURCE_BINARY_OTSU,
    c_WATERSHED_MASK_SOURCE_BINARY_THRES,
    c_WATERSHED_MASK_FILL_BINARY_OTSU,
    c_WATERSHED_MASK_FILL_BINARY_THRES,
    c_WATERSHED_MASK_NUMBER_OF
};
const QStringList QSL_WatershedMask = {
    "Source: Unmodified",
    "Source: Binary Otsu",
    "Source: Binary Thres",
    "Fill: Binary Otsu",
    "Fill: Binary Thres"
};

enum D_COLOR2MONO {
    c_COL2MONO_GRAY,
    c_COL2MONO_BLUE,
    c_COL2MONO_GREEN,
    c_COL2MONO_RED,
    c_COL2MONO_X,
    c_COL2MONO_Y,
    c_COL2MONO_Z,
    c_COL2MONO_BRIGHTNESS,
    c_COL2MONO_BLUE_YELLOW,
    c_COL2MONO_RED_GREEN,
    c_COL2MONO_HUE,
    c_COL2MONO_SATURATION,
    c_COL2MONO_VALUE,
    c_COL2MONO_LUMINANZ,
    c_COL2MONO_NUMBER_OF
};
const QStringList QSL_Color2Mono = {
    "Gray",
    "Blue",
    "Green",
    "Red",
    "X",
    "Y",
    "Z",
    "Brightness",
    "Blue/Yellow",
    "Red/Green",
    "Hue",
    "Saturation",
    "Value",
    "Luminanz"
};



enum D_VIS_TRAFO_CROP {
    c_VIS_TRAFO_CROP_DYNAMIC,
    c_VIS_TRAFO_CROP_FIXED,
    c_VIS_TRAFO_CROP_NUMBER_OF
};
const QStringList QSL_VisTrafo_Crop = {
    "Dynamic",
    "Fixed Values"
};

enum D_VIS_TRAFO {
    c_VIS_TRAFO_LINEAR,
    c_VIS_TRAFO_GAMMA,
    c_VIS_TRAFO_LOG,
    c_VIS_TRAFO_NUMBER_OF
};
const QStringList QSL_VisTrafo = {
    "Linear",
    "Gamma",
    "Logarithmic"
};

enum D_VIS_TRAFO_ANCHOR {
    c_VIS_TRAFO_ANCHOR_DYNAMIC,
    c_VIS_TRAFO_ANCHOR_CENTER,
    c_VIS_TRAFO_ANCHOR_BLACK,
    c_VIS_TRAFO_ANCHOR_WHITE,
    c_VIS_TRAFO_ANCHOR_NUMBER_OF
};
const QStringList QSL_VisTrafo_Anchor = {
    "Dynamic",
    "Center Value",
    "Black Value",
    "White Value"
};

enum D_VIS_TRAFO_RANGE {
    c_VIS_TRAFO_RANGE_DYNAMIC,
    c_VIS_TRAFO_RANGE_FIXED,
    c_VIS_TRAFO_RANGE_NUMBER_OF
};
const QStringList QSL_VisTrafo_Range = {
    "Dynamic",
    "Fixed"
};



enum D_STATISTIC_ENUM {
    c_STAT_COUNT,
    c_STAT_SUM,
    c_STAT_SUM_OF_ABS,
    c_STAT_SUM_OF_SQUARES,
    c_STAT_MEAN_ARITMETIC,
    c_STAT_MEAN_ARITMETIC_OF_ABS,
    c_STAT_MEAN_ARITMETIC_OF_NON_ZERO,
    c_STAT_VARIANCE_TOTAL,
    c_STAT_VARIANCE_SAMPLE,
    c_STAT_SKEWNESS_TOTAL,
    c_STAT_SKEWNESS_SAMPLE,
    c_STAT_KURTOSIS_TOTAL,
    c_STAT_KURTOSIS_SAMPLE,
    c_STAT_STAN_DEV_TOTAL,
    c_STAT_STAN_DEV_SAMPLE,
    c_STAT_VAR_COEF_TOTAL,
    c_STAT_VAR_COEF_SAMPLE,
    c_STAT_MINIMUM,
    c_STAT_QUANTIL_05,
    c_STAT_QUANTIL_10,
    c_STAT_QUANTIL_15,
    c_STAT_QUANTIL_20,
    c_STAT_QUARTIL_LOW,
    c_STAT_QUANTIL_30,
    c_STAT_QUANTIL_35,
    c_STAT_QUANTIL_40,
    c_STAT_QUANTIL_45,
    c_STAT_MEDIAN,
    c_STAT_QUANTIL_55,
    c_STAT_QUANTIL_60,
    c_STAT_QUANTIL_65,
    c_STAT_QUANTIL_70,
    c_STAT_QUARTIL_UP,
    c_STAT_QUANTIL_80,
    c_STAT_QUANTIL_85,
    c_STAT_QUANTIL_90,
    c_STAT_QUANTIL_95,
    c_STAT_MAXIMUM,
    c_STAT_ABS_DEV_MED,
    c_STAT_DIST_10_0_PRZ,
    c_STAT_DIST_20_0_PRZ,
    c_STAT_DIST_30_0_PRZ,
    c_STAT_DIST_40_0_PRZ,
    c_STAT_DIST_QUARTIL,
    c_STAT_DIST_60_0_PRZ,
    c_STAT_DIST_68_3_PRZ,
    c_STAT_DIST_70_0_PRZ,
    c_STAT_DIST_80_0_PRZ,
    c_STAT_DIST_90_0_PRZ,
    c_STAT_DIST_95_4_PRZ,
    c_STAT_DIST_99_7_PRZ,
    c_STAT_SPAN,
    c_STAT_SEM_ABS_TOTAL,
    c_STAT_SEM_ABS_SAMPLE,
    c_STAT_SEM_REL_TOTAL,
    c_STAT_SEM_REL_SAMPLE,
    c_STAT_CONST_0,
    c_STAT_CONST_1,
    c_STAT_NUMBER_OF_STATS
};
const QStringList QSL_StatList = {
    "Count",
    "Sum",
    "Sum of Absolutes",
    "Sum of Squares",
    "Arithmetic Mean",
    "Arithmetic Mean of absolutes",
    "Arithmetic Mean of non zero",
    "Variance total",
    "Variance sample",
    "Skewness total",
    "Skewness sample",
    "Kurtosis total",
    "Kurtosis sample",
    "Stan. Dev. total",
    "Stan. Dev. sample",
    "Var. Coeff. total",
    "Var. Coeff. sample",
    "Minimum",
    "Quantil 05%",
    "Quantil 10%",
    "Quantil 15%",
    "Quantil 20%",
    "Quartil Low",
    "Quantil 30%",
    "Quantil 35%",
    "Quantil 40%",
    "Quantil 45%",
    "Median",
    "Quantil 55%",
    "Quantil 60%",
    "Quantil 65%",
    "Quantil 70%",
    "Quartil Up",
    "Quantil 80%",
    "Quantil 85%",
    "Quantil 90%",
    "Quantil 95%",
    "Maximum",
    "Abs. Dev. Med.",
    "Distance 10%",
    "Distance 20%",
    "Distance 30%",
    "Distance 40%",
    "Distance Quartils",
    "Distance 60%",
    "Distance 68.3%",
    "Distance 70%",
    "Distance 80%",
    "Distance 90%",
    "Distance 95.4%",
    "Distance 99.7%",
    "Span",
    "SEM abs (total)",
    "SEM abs (sample)",
    "SEM rel (total)",
    "SEM rel (sample)",
    "Constant 0",
    "Constant 1"
};

enum D_STATISTIC_2D_ENUM
{
    c_STAT_2D_DIFF_SUM_ABS,
    c_STAT_2D_DIFF_SQUARE_SUM,
    c_STAT_2D_DIFF_ABS_MEAN,
    c_STAT_2D_DIFF_REL_MEAN,
    c_STAT_2D_LINEAR_FIT_SLOPE,
    c_STAT_2D_LINEAR_FIT_Y_AXIS_SECTION,
    c_STAT_2D_COVARIANCE_TOTAL,
    c_STAT_2D_COVARIANCE_SAMPLE,
    c_STAT_2D_CORRELATION_TOTAL,
    c_STAT_2D_CORRELATION_SAMPLE,
    c_STAT_2D_R_SQUARE_TOTAL,
    c_STAT_2D_R_SQUARE_SAMPLE,
    c_STAT_2D_NUMBER_OF
};
const QStringList QSL_StatList2D =
{
    "Sum of absolute differences",
    "Sum of squared differences",
    "Mean absolute differences",
    "Mean relative differences",
    "Linear fit slope",
    "Linear fit y axis section",
    "Covariance total",
    "Covariance sample",
    "Correlation total",
    "Correlation sample",
    "R^2 total",
    "R^2 sample"
};

enum D_STATISTIC_CIRC_ENUM
{
    c_STAT_CIRC_COUNT,
    c_STAT_CIRC_MEAN_SIN,
    c_STAT_CIRC_MEAN_COS,
    c_STAT_CIRC_MEAN_ANG,
    c_STAT_CIRC_UNBALANCE,
    c_STAT_CIRC_BALANCE,
    c_STAT_CIRC_BALANCE_PI_OR_180,
    c_STAT_CIRC_BALANCE_PI_OR_180_1SIGMA,
    c_STAT_CIRC_BALANCE_PI_OR_180_2SIGMA,
    c_STAT_CIRC_BALANCE_PI_OR_180_3SIGMA,
    c_STAT_CIRC_BALANCE_PI_OR_180_4SIGMA,
    c_STAT_CIRC_BALANCE_PI_OR_180_5SIGMA,
    c_STAT_CIRC_BALANCE_PI_OR_180_6SIGMA,
    c_STAT_CIRC_BALANCE_PI_OR_180_7SIGMA,
    c_STAT_CIRC_VARIANCE_TOTAL,
    c_STAT_CIRC_VARIANCE_SAMPLE,
    c_STAT_CIRC_SKEWNESS_TOTAL,
    c_STAT_CIRC_SKEWNESS_SAMPLE,
    c_STAT_CIRC_KURTOSIS_TOTAL,
    c_STAT_CIRC_KURTOSIS_SAMPLE,
    c_STAT_CIRC_STAN_DEV_TOTAL,
    c_STAT_CIRC_STAN_DEV_SAMPLE,
    c_STAT_CIRC_SEM_TOTAL,
    c_STAT_CIRC_SEM_SAMPLE,
    c_STAT_CIRC_CONST_0,
    c_STAT_CIRC_CONST_1,
    c_STAT_CIRC_CONST_PI,
    c_STAT_CIRC_NUMBER_OF
};
const QStringList QSL_StatListCirc =
{
    "Count",
    "Mean Sine",
    "Mean Cosine",
    "Mean",
    "Unbalance",
    "Balance",
    "Balace rel 180 or PI",
    "Balace rel 180 or PI 1 Sigma",
    "Balace rel 180 or PI 2 Sigma",
    "Balace rel 180 or PI 3 Sigma",
    "Balace rel 180 or PI 4 Sigma",
    "Balace rel 180 or PI 5 Sigma",
    "Balace rel 180 or PI 6 Sigma",
    "Balace rel 180 or PI 7 Sigma",
    "Variance total",
    "Variance sample",
    "Skewness total",
    "Skewness sample",
    "Kurtosis total",
    "Kurtosis sample",
    "Stan. Dev. total",
    "Stan. Dev. sample",
    "SEM total",
    "SEM sample",
    "Constant 0",
    "Constant 1",
    "Constant 180 or Pi"
};

enum D_OPTIMIZE_1D
{
    c_OPT_1D_MINIMUM,
    c_OPT_1D_MINIMUM_ABS,
    c_OPT_1D_MAXIMUM,
    c_OPT_1D_MAXIMUM_ABS,
    c_OPT_1D_NUMBER_OF
};
const QStringList QSL_Optimize_1D =
{
    "Minimize",
    "Minimize Absolute",
    "Maximize",
    "Maximize Absolute"
};

enum D_COMPLEX2REAL
{
    c_COMPLEX2REAL_REAL,
    c_COMPLEX2REAL_IMAG,
    c_COMPLEX2REAL_PHASE,
    c_COMPLEX2REAL_ABS,
    c_COMPLEX2REAL_ABS_SQUARE,
    c_COMPLEX2REAL_RE_IM,
    c_COMPLEX2REAL_HUE_VAL,
    c_COMPLEX2REAL_HUE_SAT,
    c_COMPLEX2REAL_NUMBER_OF
};
const QStringList QSL_Complex2Real =
{
    "Real Grey",
    "Imaginary Grey",
    "Phase Grey",
    "Absolute Grey",
    "Absolute Squared Grey",
    "Real Blue - Imaginary Green",
    "Phase Hue - Absolute Value",
    "Phase Hue - Absolute Saturation"
};
const QStringList QSL_Complex2Real_Short =
{
    "Gr Real",
    "Gr Imag",
    "Gr Phase",
    "Gr Abs",
    "Gr Abs^2",
    "BG Re Im",
    "HV Ph Abs",
    "HS Ph Abs"
};

enum D_MATH_1D_TO_1D
{
    c_MATH_1D_TO_1D_X,
    c_MATH_1D_TO_1D_X_power_2,
    c_MATH_1D_TO_1D_A_times_X,
    c_MATH_1D_TO_1D_X_FACULTY,
    c_MATH_1D_TO_1D_BINOMIAL_X_OUTOF_D,
    c_MATH_1D_TO_1D_GAMMA,
    c_MATH_1D_TO_1D_LOG_CENTERED,
    c_MATH_1D_TO_1D_NUMBER_OF
};
const QStringList QSL_Math_1D_to_1D =
{
    "x",
    "x²",
    "ax",
    "x!",
    "d over ax+b",
    "Gamma (x normed to b=0 and c=1)^d",
    "Log centered sign(x+b)*log(abs(x+b)+1)"
};


enum D_MATH_2D_TO_1D
{
    c_MATH_2D_TO_1D_const_E,
    c_MATH_2D_TO_1D_X,
    c_MATH_2D_TO_1D_Y,
    c_MATH_2D_TO_1D_X_plus_Y,
    c_MATH_2D_TO_1D_X_minus_Y,
    c_MATH_2D_TO_1D_X_minus_Y_abs,
    c_MATH_2D_TO_1D_X_times_Y,
    c_MATH_2D_TO_1D_X_divby_Y,
    c_MATH_2D_TO_1D_Y_divby_X,
    c_MATH_2D_TO_1D_X_equals_Y,
    c_MATH_2D_TO_1D_X_greater_Y,
    c_MATH_2D_TO_1D_X_smaller_Y,
    c_MATH_2D_TO_1D_X_difference_Y_equal_E,
    c_MATH_2D_TO_1D_X_difference_Y_greater_E,
    c_MATH_2D_TO_1D_X_difference_Y_smaller_E,
    c_MATH_2D_TO_1D_X_difference_Y_smaller_F_greater_E,
    c_MATH_2D_TO_1D_X_difference_Y_equal_E_abs,
    c_MATH_2D_TO_1D_X_difference_Y_greater_E_abs,
    c_MATH_2D_TO_1D_X_difference_Y_smaller_E_abs,
    c_MATH_2D_TO_1D_X_difference_Y_smaller_F_greater_E_abs,
    c_MATH_2D_TO_1D_X_Y_norm,
    c_MATH_2D_TO_1D_X_Y_atan2,
    c_MATH_2D_TO_1D_SIN_X_Y,
    c_MATH_2D_TO_1D_SIN_X_Y_PI,
    c_MATH_2D_TO_1D_SINC_ABS_X_Y,
    c_MATH_2D_TO_1D_GAUSS,
    c_MATH_2D_TO_1D_LN_GAUSS,
    c_MATH_2D_TO_1D_2SPHERES,
    c_MATH_2D_TO_1D_FOURIER_MATRIX_COSINUS,
    c_MATH_2D_TO_1D_FOURIER_MATRIX_SINUS,
    c_MATH_2D_TO_1D_BINOMIAL_XoutofE_times_YoutofF,
    c_MATH_2D_TO_1D_BINOMIAL_XoutofE_times_YoutofF_normed,
    c_MATH_2D_TO_1D_ECHELETTI_GRID,
    c_MATH_2D_TO_1D_STRIPES_RECT_X_Y,
    c_MATH_2D_TO_1D_ELLIPSE,
    c_MATH_2D_TO_1D_ZERNIKE_NM,
    c_MATH_2D_TO_1D_ZERNIKE_J,
    c_MATH_2D_TO_1D_NUMBER_OF
};
const QStringList QSL_Math_2D_to_1D =
{
    "const e",
    "(ax+b)",
    "(cy+d)",
    "(ax+b) + (cy+d)",
    "(ax+b) - (cy+d)",
    "|(ax+b) - (cy+d)|",
    "(ax+b) * (cy+d)",
    "(ax+b) / (cy+d)",
    "(cy+d) / (ax+b)",
    "(ax+b) == (cy+d) + e",
    "(ax+b) > (cy+d) + e",
    "(ax+b) < (cy+d) + e",
    "(ax+b) - (cy+d) == e",
    "(ax+b) - (cy+d) > e",
    "(ax+b) - (cy+d) < e",
    "e < (ax+b) - (cy+d) < f",
    "|(ax+b) - (cy+d)| == e",
    "|(ax+b) - (cy+d)| > e",
    "|(ax+b) - (cy+d)| < e",
    "e < |(ax+b) - (cy+d)| < f",
    "norm((ax+b), (cy+d))",
    "atan2((ax+b), (cy+d))",
    "e * SIN(ax+cy+d) + f",
    "e * SIN(2Pi((ax/b)+(cy/d)+f))",
    "e * SINC(NORM(ax+b, cy+d)) + f",
    "e * EXP(-(a(x+b)² + f((x+b)*(y+d))² + c(y+d)²))",
    "e * (-(a(x+b)² + f((x+b)*(y+d))² + c(y+d)²))",
    "Two Spheres: abc=center1, d=pahse, e=center2z, f=k",
    "Fourier-Cosinus-Matrix: e * cos((2PI * (ax+b) * (cy+d)) / f)",
    "Fourier-Sinus-Matrix: e * sin((2PI * (ax+b) * (cy+d)) / f)",
    "Binomial Coefficient (ax+b) out of e times (cy+d) out of f",
    "Binomial Coefficient (ax+b) out of e times (cy+d) out of f (normed)",
    "Echeletti-Grid (e * (sin(ax+b)-sin(cy+d)))/f (degree)",
    "Stripes Rect: a=shift, b=space, c=width, d=offset, e=amplitude, f=angle",
    "Ellipse: a=r_x, b=s_x, c=r_y, d=s_y, e=amplitude, f=angle",
    "Zernike: a=r, b=n, c=m",
    "Zernike: a=r, b=j"
};

enum D_MATH_2D_TO_1D_COMPLEX
{
    c_MATH_2D_TO_1D_COMPLEX_CONST_E_iF,
    c_MATH_2D_TO_1D_COMPLEX_X_iY,
    c_MATH_2D_TO_1D_COMPLEX_X_PLUS_Y,
    c_MATH_2D_TO_1D_COMPLEX_X_MINUS_Y,
    c_MATH_2D_TO_1D_COMPLEX_X_TIMES_Y,
    c_MATH_2D_TO_1D_COMPLEX_X_DIV_Y,
    c_MATH_2D_TO_1D_COMPLEX_X_POW_Y,
    c_MATH_2D_TO_1D_COMPLEX_LOGISTIC_MAP_SIMPLE,
    c_MATH_2D_TO_1D_COMPLEX_LOGISTIC_MAP,
    c_MATH_2D_TO_1D_COMPLEX_NUMBER_OF
};
const QStringList QSL_Math_2D_to_1D_Complex =
{
    "const (e + if)",
    "complex plane (x + iy)",
    "x+y",
    "x-y",
    "x*y",
    "x/y",
    "x^y",
    "x^a + b",
    "logistic map ax(1-x)",
    "logistic map (ax+b)(cx+d)"
};

enum D_MATH_6D_TO_1D
{
    c_MATH_6D_TO_1D_const_E,
    c_MATH_6D_TO_1D_PRODUCT,
    c_MATH_6D_TO_1D_CUBOID_3D,
    c_MATH_6D_TO_1D_CYLINDER_3D,
    c_MATH_6D_TO_1D_ASM_REAL,
    c_MATH_6D_TO_1D_ASM_IMAG,
    c_MATH_6D_TO_1D_TEST_3D_CHESS,
    c_MATH_6D_TO_1D_TEST_3D_Z_LAYERS,
    c_MATH_6D_TO_1D_NUMBER_OF
};
const QStringList QSL_Math_6D_to_1D =
{
    "Const e",
    "Product x * y * z * t * s * p",
    "Cuboid 3D, a=value, b=hx, c=hy, d=hz, e=rot_z, f=rot_y",
    "Ellipic Cylinder 3D a=value, b=rx, c=ry, d=h, e=rot_z, f=rot_y",
    "ASM, Phase Factor, REAL, a=k, b=lambda, e=rot_z, f=rot_y",
    "ASM, Phase Factor, IMAG, a=k, b=lambda, e=rot_z, f=rot_y",
    "Testing 3D chess board",
    "Testing 3D z layers"
};

enum D_MATH_ND_TO_1D
{
    c_MATH_ND_TO_1D_SUM,
    c_MATH_ND_TO_1D_COUNT,
    c_MATH_ND_TO_1D_MEAN,
    c_MATH_ND_TO_1D_VARIANCE,
    c_MATH_ND_TO_1D_STAN_DEV,
    c_MATH_ND_TO_1D_VAR_COEFF,
    c_MATH_ND_TO_1D_MINIMUM,
    c_MATH_ND_TO_1D_QUARTIL_LOW,
    c_MATH_ND_TO_1D_MEDIAN,
    c_MATH_ND_TO_1D_QUARTIL_UP,
    c_MATH_ND_TO_1D_MAXIMUM,
    c_MATH_ND_TO_1D_NUMBER_OF
};
const QStringList QSL_Math_ND_to_1D =
{
    "sum",
    "count",
    "mean",
    "variance",
    "standard deviation",
    "coefficient of variance",
    "minimum",
    "lower quartil",
    "median",
    "upper quartil",
    "maximum"
};

enum D_RANDOM
{
    c_RAND_NORMAL,
    c_RAND_NUMBER_OF
};
const QStringList QSL_Random =
{
    "Normal Distribution mu=a, sigma=b"
};

enum D_COND_2D
{
    c_COND_EQUAL,
    c_COND_SMALLER,
    c_COND_SMALLER_EQUAL,
    c_COND_GREATER,
    c_COND_GREATER_EQUAL,
    c_COND_NOT_EQUAL,
    c_COND_INTERVALS_IN_EXCL_AND,
    c_COND_INTERVALS_IN_INCL_AND,
    c_COND_INTERVALS_IN_EXCL_OR,
    c_COND_INTERVALS_IN_INCL_OR,
    c_COND_INTERVALS_IN_EXCL_XOR,
    c_COND_INTERVALS_IN_INCL_XOR,
    c_COND_NUMBER_OF
};
const QStringList QSL_Conditions = {
    "(ax+b) == (cy+d)",
    "(ax+b) < (cy+d)",
    "(ax+b) <= (cy+d)",
    "(ax+b) > (cy+d)",
    "(ax+b) >= (cy+d)",
    "(ax+b) != (cy+d)",
    "[e < (ax+b) < f] & [g < (cy+d) < h]",
    "[e <= (ax+b) <= f] & [g <= (cy+d) <= h]",
    "[e < (ax+b) < f] | [g < (cy+d) < h]",
    "[e <= (ax+b) <= f] | [g <= (cy+d) <= h]",
    "[e < (ax+b) < f] != [g < (cy+d) < h]",
    "[e <= (ax+b) <= f] != [g <= (cy+d) <= h]"
};

enum D_STEREO
{
    c_STEREO_ALBEDO,
    c_STEREO_NORMAL,
    c_STEREO_NUMBER_OF
};
const QStringList QSL_StereoOutput =
{
    "Albedo",
    "Normal Vector"
};

enum D_CONNECT_POINTS
{
    c_CONNECT_CLOSEST,
    c_CONNECT_IN_RANGE,
    c_CONNECT_NUMBER_OF
};
const QStringList QSL_ConnectPoints =
{
    "Closest",
    "All in Range"
};

enum D_CURVE_ARRAY
{
    c_CURVE_ARRAY_POLYNOM_DG_5,
    c_CURVE_ARRAY_RADON_MONSTER_DGL,
    c_CURVE_ARRAY_NUMBER_OF
};
const QStringList QSL_CurveArray =
{
    "ax^5 + bx^4 + cx^3 + dx^2 + ex + f",
    "Franzi's Radon Monster (a=d1, b=w1, c=d2, d=w2)"
};

enum D_FIT_TYPE
{
    c_FIT_TYPE_LEAST_SUM_OF_SQUARED_RESIDUALS,
    c_FIT_TYPE_NUMBER_OF
};
const QStringList QSL_FitType =
{
    "Least sum of squared residuals"
};

/*
enum D_DIMENSION_REDUCE
{
    c_DIMENSION_REDUCE_AREA_XY,
    c_DIMENSION_REDUCE_STACK_Z,
    c_DIMENSION_REDUCE_NUMBER_OF
};
const QStringList QSL_DimensionReduce =
{
    "Area (XY)",
    "Stack (Z)"
};
*/

enum D_FEATURE_ENUM {

    c_FEAT_LABEL,

    c_FEAT_HOLES,

    c_FEAT_CURL,
    c_FEAT_SOLIDITY,
    c_FEAT_COMPACTNESS,
    C_FEAT_CONVEXITY,
    c_FEAT_ROUNDNESS,
    c_FEAT_SPHERICITY,
    c_FEAT_RECTANGULARITY,
    c_FEAT_RECT_AXEPAR_ASPECT_RATIO,
    c_FEAT_EXCENTRICITY,
    c_FEAT_ELONGATION_RECT,
    c_FEAT_ELONGATION_ROT,

    c_FEAT_CURL_INV,
    c_FEAT_SOLIDITY_INV,
    c_FEAT_COMPACTNESS_INV,
    c_FEAT_CONVEXITY_INV,
    c_FEAT_ROUNDNESS_INV,
    c_FEAT_SPHERICITY_INV,
    c_FEAT_RECTANGULARITY_INV,
    c_FEAT_RECT_AXEPAR_ASPECT_RATIO_INV,
    c_FEAT_EXCENTRICITY_INV,
    c_FEAT_ELONGATION_RECT_INV,
    c_FEAT_ELONGATION_ROT_INV,

    c_FEAT_RECT_ROTATE_ANGLE,
    c_FEAT_ELLIPSE_FIT_ANGLE,
    c_FEAT_DIRECTION,

    c_FEAT_COUNT_PIXEL,
    c_FEAT_AREA,
    c_FEAT_CONVEX_AREA,
    c_FEAT_RECT_AXEPAR_AREA,
    c_FEAT_RECT_ROTATE_AREA,
    c_FEAT_CIRC_INSCRIB_AREA,
    c_FEAT_CIRC_INCLOSE_AREA,
    c_FEAT_CIRC_EQUIVAL_AREA,
    c_FEAT_CIRC_ENCLOSE_AREA,
    c_FEAT_CIRC_CIRCUMS_AREA,
    c_FEAT_ELLIPSE_FIT_AREA,

    c_FEAT_COUNT_CONTOUR,
    c_FEAT_PERIMETER,
    c_FEAT_CONVEX_PERIMETER,
    c_FEAT_RECT_AXEPAR_PERIMETER,
    c_FEAT_RECT_ROTATE_PERIMETER,
    c_FEAT_CIRC_INSCRIB_PERIMETER,
    c_FEAT_CIRC_INCLOSE_PERIMETER,
    c_FEAT_CIRC_EQUIVAL_PERIMETER,
    c_FEAT_CIRC_ENCLOSE_PERIMETER,
    c_FEAT_CIRC_CIRCUMS_PERIMETER,
    c_FEAT_ELLIPSE_FIT_PERIMETER,

    c_FEAT_RECT_AXEPAR_WIDTH,
    c_FEAT_RECT_AXEPAR_SIDE_LONG,
    c_FEAT_RECT_ROTATE_WIDTH,
    c_FEAT_RECT_ROTATE_SIDE_LONG,
    c_FEAT_ELLIPSE_FIT_MAJOR_AXIS,
    c_FEAT_MAJOR_AXIS,
    c_FEAT_FIBRE_LENGTH,

    c_FEAT_RECT_AXEPAR_HEIGHT,
    c_FEAT_RECT_AXEPAR_SIDE_SHORT,
    c_FEAT_RECT_ROTATE_HEIGHT,
    c_FEAT_RECT_ROTATE_SIDE_SHORT,
    c_FEAT_ELLIPSE_FIT_MINOR_AXIS,
    c_FEAT_MINOR_AXIS,
    c_FEAT_FIBRE_WIDTH,

    c_FEAT_CIRC_INSCRIB_RADIUS,
    c_FEAT_CIRC_INCLOSE_RADIUS,
    c_FEAT_CIRC_EQUIVAL_RADIUS,
    c_FEAT_CIRC_ENCLOSE_RADIUS,
    c_FEAT_CIRC_CIRCUMS_RADIUS,

    c_FEAT_CIRC_INSCRIB_DIAMETER,
    c_FEAT_CIRC_INCLOSE_DIAMETER,
    c_FEAT_CIRC_EQUIVAL_DIAMETER,
    c_FEAT_CIRC_ENCLOSE_DIAMETER,
    c_FEAT_CIRC_CIRCUMS_DIAMETER,

    c_FEAT_MASS_CENTER_X,
    c_FEAT_RECT_AXEPAR_CENTER_X,
    c_FEAT_RECT_ROTATE_CENTER_X,
    c_FEAT_CIRC_INCLOSE_CENTER_X,
    c_FEAT_CIRC_ENCLOSE_CENTER_X,
    c_FEAT_ELLIPSE_FIT_CENTER_X,
    c_FEAT_RECT_AXEPAR_LEFT,
    c_FEAT_RECT_AXEPAR_RIGHT,

    c_FEAT_MASS_CENTER_Y,
    c_FEAT_RECT_AXEPAR_CENTER_Y,
    c_FEAT_RECT_ROTATE_CENTER_Y,
    c_FEAT_CIRC_INCLOSE_CENTER_Y,
    c_FEAT_CIRC_ENCLOSE_CENTER_Y,
    c_FEAT_ELLIPSE_FIT_CENTER_Y,
    c_FEAT_RECT_AXEPAR_TOP,
    c_FEAT_RECT_AXEPAR_BOTTOM,

    c_FEAT_MOMENT_SPATIAL_m00,
    c_FEAT_MOMENT_SPATIAL_m10,
    c_FEAT_MOMENT_SPATIAL_m01,
    c_FEAT_MOMENT_SPATIAL_m20,
    c_FEAT_MOMENT_SPATIAL_m11,
    c_FEAT_MOMENT_SPATIAL_m02,
    c_FEAT_MOMENT_SPATIAL_m30,
    c_FEAT_MOMENT_SPATIAL_m21,
    c_FEAT_MOMENT_SPATIAL_m12,
    c_FEAT_MOMENT_SPATIAL_m03,

    c_FEAT_MOMENT_CENTRAL_mu20,
    c_FEAT_MOMENT_CENTRAL_mu11,
    c_FEAT_MOMENT_CENTRAL_mu02,
    c_FEAT_MOMENT_CENTRAL_mu30,
    c_FEAT_MOMENT_CENTRAL_mu21,
    c_FEAT_MOMENT_CENTRAL_mu12,
    c_FEAT_MOMENT_CENTRAL_mu03,

    c_FEAT_MOMENT_CENTRAL_NORM_nu20,
    c_FEAT_MOMENT_CENTRAL_NORM_nu11,
    c_FEAT_MOMENT_CENTRAL_NORM_nu02,
    c_FEAT_MOMENT_CENTRAL_NORM_nu30,
    c_FEAT_MOMENT_CENTRAL_NORM_nu21,
    c_FEAT_MOMENT_CENTRAL_NORM_nu12,
    c_FEAT_MOMENT_CENTRAL_NORM_nu03,

    c_FEAT_MOMENT_INVARIANT_hu0,
    c_FEAT_MOMENT_INVARIANT_hu1,
    c_FEAT_MOMENT_INVARIANT_hu2,
    c_FEAT_MOMENT_INVARIANT_hu3,
    c_FEAT_MOMENT_INVARIANT_hu4,
    c_FEAT_MOMENT_INVARIANT_hu5,
    c_FEAT_MOMENT_INVARIANT_hu6,

    c_FEAT_DIST_CENTROID_2_CONTOUR,

    c_FEAT_SPHERE_EQUIV_VOL,

    c_FEAT_NUMBER_OF_FEATS
};
const QStringList QSL_FeatureList = {

    "Label Number",

    "Holes Count",

    "Curl",
    "Solidity",
    "Compactness",
    "Convexity",
    "Roundness",
    "Sphericity",
    "Rectangularity",
    "Apect Ratio Rect AxeParallel",
    "Excentricity",
    "Elongation Rect AxeParallel",
    "Elongation Rect Rotate",

    "Inv Curl",
    "Inv Solidity",
    "Inv Compactness",
    "Inv Convexity",
    "Inv Roundness",
    "Inv Sphericity",
    "Inv Rectangularity",
    "Inv Apect Ratio Rect AxeParallel",
    "Inv Excentricity",
    "Inv Elongation Rect AxeParallel",
    "Inv Elongation Rect Rotate",

    "Angle Rect Rotate",
    "Angle Ellipse Fitted",
    "Direction",

    "Area Pixel Count",
    "Area",
    "Area Convex Hull",
    "Area Rect AxeParallel",
    "Area Rect Rotate",
    "Area Circle Inscribing",
    "Area Circle Inclosing",
    "Area Circle Equivalent",
    "Area Circle Enclosing",
    "Area Circle Circumscribing",
    "Area Ellipse Fitted",

    "Perimeter Pixel Count",
    "Perimeter",
    "Perimeter Convex Hull",
    "Perimeter Rect AxeParallel",
    "Perimeter Rect Rotate",
    "Perimeter Circle Inscribing",
    "Perimeter Circle Inclosing",
    "Perimeter Circle Equivalent",
    "Perimeter Circle Enclosing",
    "Perimeter Circle Circumscribing",
    "Perimeter Ellipse Fitted",

    "Width Rect AxeParallel",
    "Side Long Rect AxeParallel",
    "Width Rect Rotate",
    "Side Long Rect Rotate",
    "Major Semiaxis Ellipse Fitted",
    "Major Axis",
    "Length Fibre",

    "Height Rect AxeParallel",
    "Side Short Rect AxeParallel",
    "Height Rect Rotate",
    "Side Short Rect Rotate",
    "Minor Semiaxis Ellipse Fitted",
    "Minor Axis",
    "Width Fibre",

    "Radius Circle Inscribing",
    "Radius Circle Inclosing",
    "Radius Circle Equivalent",
    "Radius Circle Enclosing",
    "Radius Circle Circumscribing",

    "Diameter Circle Inscribing",
    "Diameter Circle Inclosing",
    "Diameter Circle Equivalent",
    "Diameter Circle Enclosing",
    "Diameter Circle Circumscribing",

    "Center X Mass",
    "Center X Rect AxeParallel",
    "Center X Rect Rotate",
    "Center X Circle Inclosing",
    "Center X Circle Enclosing",
    "Center X Ellipse Fitted",
    "Extreme Left Rect AxeParallel",
    "Extreme Right Rect AxeParallel",

    "Center Y Mass",
    "Center Y Rect AxeParallel",
    "Center Y Rect Rotate",
    "Center Y Circle Inclosing",
    "Center Y Circle Enclosing",
    "Center Y Ellipse Fitted",
    "Extreme Top Rect AxeParallel",
    "Extreme Bottom Rect AxeParallel",

    "Spatial Moment 00 Area",
    "Spatial Moment 10 Sum X",
    "Spatial Moment 01 Sum Y",
    "Spatial Moment 20",
    "Spatial Moment 11",
    "Spatial Moment 02",
    "Spatial Moment 30",
    "Spatial Moment 21",
    "Spatial Moment 12",
    "Spatial Moment 03",

    "Central Moment 20 Spread Rows",
    "Central Moment 11 Spread",
    "Central Moment 02 Spread Columns",
    "Central Moment 30",
    "Central Moment 21",
    "Central Moment 12",
    "Central Moment 03",

    "Central Moment Normed 20",
    "Central Moment Normed 11",
    "Central Moment Normed 02",
    "Central Moment Normed 30",
    "Central Moment Normed 21",
    "Central Moment Normed 12",
    "Central Moment Normed 03",

    "Moment Invariant 0 Inertia",
    "Moment Invariant 1 Isotropic",
    "Moment Invariant 2 ",
    "Moment Invariant 3",
    "Moment Invariant 4",
    "Moment Invariant 5",
    "Moment Invariant 6",

    "Distance Centroid to Contour",
    "Volume Sphere Equivalent"
};

/* WORK IN PROGRESS
const std::vector<size_t> vFeatInvariant_Shift = {
    //c_FEAT_LABEL,

    c_FEAT_HOLES,

    c_FEAT_CURL,
    c_FEAT_SOLIDITY,
    c_FEAT_COMPACTNESS,
    C_FEAT_CONVEXITY,
    c_FEAT_ROUNDNESS,
    c_FEAT_SPHERICITY,
    c_FEAT_RECTANGULARITY,
    c_FEAT_RECT_AXEPAR_ASPECT_RATIO,
    c_FEAT_EXCENTRICITY,
    c_FEAT_ELONGATION_RECT,
    c_FEAT_ELONGATION_ROT,

    c_FEAT_CURL_INV,
    c_FEAT_SOLIDITY_INV,
    c_FEAT_COMPACTNESS_INV,
    c_FEAT_CONVEXITY_INV,
    c_FEAT_ROUNDNESS_INV,
    c_FEAT_SPHERICITY_INV,
    c_FEAT_RECTANGULARITY_INV,
    c_FEAT_RECT_AXEPAR_ASPECT_RATIO_INV,
    c_FEAT_EXCENTRICITY_INV,
    c_FEAT_ELONGATION_RECT_INV,
    c_FEAT_ELONGATION_ROT_INV,

    c_FEAT_RECT_ROTATE_ANGLE,
    c_FEAT_ELLIPSE_FIT_ANGLE,
    c_FEAT_DIRECTION,

    c_FEAT_COUNT_PIXEL,
    c_FEAT_AREA,
    c_FEAT_CONVEX_AREA,
    c_FEAT_RECT_AXEPAR_AREA,
    c_FEAT_RECT_ROTATE_AREA,
    c_FEAT_CIRC_INSCRIB_AREA,
    c_FEAT_CIRC_INCLOSE_AREA,
    c_FEAT_CIRC_EQUIVAL_AREA,
    c_FEAT_CIRC_ENCLOSE_AREA,
    c_FEAT_CIRC_CIRCUMS_AREA,
    c_FEAT_ELLIPSE_FIT_AREA,

    c_FEAT_COUNT_CONTOUR,
    c_FEAT_PERIMETER,
    c_FEAT_CONVEX_PERIMETER,
    c_FEAT_RECT_AXEPAR_PERIMETER,
    c_FEAT_RECT_ROTATE_PERIMETER,
    c_FEAT_CIRC_INSCRIB_PERIMETER,
    c_FEAT_CIRC_INCLOSE_PERIMETER,
    c_FEAT_CIRC_EQUIVAL_PERIMETER,
    c_FEAT_CIRC_ENCLOSE_PERIMETER,
    c_FEAT_CIRC_CIRCUMS_PERIMETER,
    c_FEAT_ELLIPSE_FIT_PERIMETER,

    c_FEAT_RECT_AXEPAR_WIDTH,
    c_FEAT_RECT_AXEPAR_SIDE_LONG,
    c_FEAT_RECT_ROTATE_WIDTH,
    c_FEAT_RECT_ROTATE_SIDE_LONG,
    c_FEAT_ELLIPSE_FIT_MAJOR_AXIS,
    c_FEAT_MAJOR_AXIS,
    c_FEAT_FIBRE_LENGTH,

    c_FEAT_RECT_AXEPAR_HEIGHT,
    c_FEAT_RECT_AXEPAR_SIDE_SHORT,
    c_FEAT_RECT_ROTATE_HEIGHT,
    c_FEAT_RECT_ROTATE_SIDE_SHORT,
    c_FEAT_ELLIPSE_FIT_MINOR_AXIS,
    c_FEAT_MINOR_AXIS,
    c_FEAT_FIBRE_WIDTH,

    c_FEAT_CIRC_INSCRIB_RADIUS,
    c_FEAT_CIRC_INCLOSE_RADIUS,
    c_FEAT_CIRC_EQUIVAL_RADIUS,
    c_FEAT_CIRC_ENCLOSE_RADIUS,
    c_FEAT_CIRC_CIRCUMS_RADIUS,

    c_FEAT_CIRC_INSCRIB_DIAMETER,
    c_FEAT_CIRC_INCLOSE_DIAMETER,
    c_FEAT_CIRC_EQUIVAL_DIAMETER,
    c_FEAT_CIRC_ENCLOSE_DIAMETER,
    c_FEAT_CIRC_CIRCUMS_DIAMETER,

    c_FEAT_MASS_CENTER_X,
    c_FEAT_RECT_AXEPAR_CENTER_X,
    c_FEAT_RECT_ROTATE_CENTER_X,
    c_FEAT_CIRC_INCLOSE_CENTER_X,
    c_FEAT_CIRC_ENCLOSE_CENTER_X,
    c_FEAT_ELLIPSE_FIT_CENTER_X,
    c_FEAT_RECT_AXEPAR_LEFT,
    c_FEAT_RECT_AXEPAR_RIGHT,

    c_FEAT_MASS_CENTER_Y,
    c_FEAT_RECT_AXEPAR_CENTER_Y,
    c_FEAT_RECT_ROTATE_CENTER_Y,
    c_FEAT_CIRC_INCLOSE_CENTER_Y,
    c_FEAT_CIRC_ENCLOSE_CENTER_Y,
    c_FEAT_ELLIPSE_FIT_CENTER_Y,
    c_FEAT_RECT_AXEPAR_TOP,
    c_FEAT_RECT_AXEPAR_BOTTOM,

    c_FEAT_MOMENT_SPATIAL_m00,
    c_FEAT_MOMENT_SPATIAL_m10,
    c_FEAT_MOMENT_SPATIAL_m01,
    c_FEAT_MOMENT_SPATIAL_m20,
    c_FEAT_MOMENT_SPATIAL_m11,
    c_FEAT_MOMENT_SPATIAL_m02,
    c_FEAT_MOMENT_SPATIAL_m30,
    c_FEAT_MOMENT_SPATIAL_m21,
    c_FEAT_MOMENT_SPATIAL_m12,
    c_FEAT_MOMENT_SPATIAL_m03,

    c_FEAT_MOMENT_CENTRAL_mu20,
    c_FEAT_MOMENT_CENTRAL_mu11,
    c_FEAT_MOMENT_CENTRAL_mu02,
    c_FEAT_MOMENT_CENTRAL_mu30,
    c_FEAT_MOMENT_CENTRAL_mu21,
    c_FEAT_MOMENT_CENTRAL_mu12,
    c_FEAT_MOMENT_CENTRAL_mu03,

    c_FEAT_MOMENT_CENTRAL_NORM_nu20,
    c_FEAT_MOMENT_CENTRAL_NORM_nu11,
    c_FEAT_MOMENT_CENTRAL_NORM_nu02,
    c_FEAT_MOMENT_CENTRAL_NORM_nu30,
    c_FEAT_MOMENT_CENTRAL_NORM_nu21,
    c_FEAT_MOMENT_CENTRAL_NORM_nu12,
    c_FEAT_MOMENT_CENTRAL_NORM_nu03,

    c_FEAT_MOMENT_INVARIANT_hu0,
    c_FEAT_MOMENT_INVARIANT_hu1,
    c_FEAT_MOMENT_INVARIANT_hu2,
    c_FEAT_MOMENT_INVARIANT_hu3,
    c_FEAT_MOMENT_INVARIANT_hu4,
    c_FEAT_MOMENT_INVARIANT_hu5,
    c_FEAT_MOMENT_INVARIANT_hu6,

    c_FEAT_DIST_CENTROID_2_CONTOUR,

    c_FEAT_SPHERE_EQUIV_VOL,

    c_FEAT_NUMBER_OF_FEATS
};
const std::vector<size_t> vFeatInvariant_Scale = {
    //c_FEAT_LABEL,

    c_FEAT_HOLES,

    c_FEAT_CURL,
    c_FEAT_SOLIDITY,
    c_FEAT_COMPACTNESS,
    C_FEAT_CONVEXITY,
    c_FEAT_ROUNDNESS,
    c_FEAT_SPHERICITY,
    c_FEAT_RECTANGULARITY,
    c_FEAT_RECT_AXEPAR_ASPECT_RATIO,
    c_FEAT_EXCENTRICITY,
    c_FEAT_ELONGATION_RECT,
    c_FEAT_ELONGATION_ROT,

    c_FEAT_CURL_INV,
    c_FEAT_SOLIDITY_INV,
    c_FEAT_COMPACTNESS_INV,
    c_FEAT_CONVEXITY_INV,
    c_FEAT_ROUNDNESS_INV,
    c_FEAT_SPHERICITY_INV,
    c_FEAT_RECTANGULARITY_INV,
    c_FEAT_RECT_AXEPAR_ASPECT_RATIO_INV,
    c_FEAT_EXCENTRICITY_INV,
    c_FEAT_ELONGATION_RECT_INV,
    c_FEAT_ELONGATION_ROT_INV,

    c_FEAT_RECT_ROTATE_ANGLE,
    c_FEAT_ELLIPSE_FIT_ANGLE,
    c_FEAT_DIRECTION,

    //c_FEAT_COUNT_PIXEL,
    //c_FEAT_AREA,
    //c_FEAT_CONVEX_AREA,
    //c_FEAT_RECT_AXEPAR_AREA,
    //c_FEAT_RECT_ROTATE_AREA,
    //c_FEAT_CIRC_INSCRIB_AREA,
    //c_FEAT_CIRC_INCLOSE_AREA,
    //c_FEAT_CIRC_EQUIVAL_AREA,
    //c_FEAT_CIRC_ENCLOSE_AREA,
    //c_FEAT_CIRC_CIRCUMS_AREA,
    //c_FEAT_ELLIPSE_FIT_AREA,

    c_FEAT_COUNT_CONTOUR,
    c_FEAT_PERIMETER,
    c_FEAT_CONVEX_PERIMETER,
    c_FEAT_RECT_AXEPAR_PERIMETER,
    c_FEAT_RECT_ROTATE_PERIMETER,
    c_FEAT_CIRC_INSCRIB_PERIMETER,
    c_FEAT_CIRC_INCLOSE_PERIMETER,
    c_FEAT_CIRC_EQUIVAL_PERIMETER,
    c_FEAT_CIRC_ENCLOSE_PERIMETER,
    c_FEAT_CIRC_CIRCUMS_PERIMETER,
    c_FEAT_ELLIPSE_FIT_PERIMETER,

    c_FEAT_RECT_AXEPAR_WIDTH,
    c_FEAT_RECT_AXEPAR_SIDE_LONG,
    c_FEAT_RECT_ROTATE_WIDTH,
    c_FEAT_RECT_ROTATE_SIDE_LONG,
    c_FEAT_ELLIPSE_FIT_MAJOR_AXIS,
    c_FEAT_MAJOR_AXIS,
    c_FEAT_FIBRE_LENGTH,

    c_FEAT_RECT_AXEPAR_HEIGHT,
    c_FEAT_RECT_AXEPAR_SIDE_SHORT,
    c_FEAT_RECT_ROTATE_HEIGHT,
    c_FEAT_RECT_ROTATE_SIDE_SHORT,
    c_FEAT_ELLIPSE_FIT_MINOR_AXIS,
    c_FEAT_MINOR_AXIS,
    c_FEAT_FIBRE_WIDTH,

    c_FEAT_CIRC_INSCRIB_RADIUS,
    c_FEAT_CIRC_INCLOSE_RADIUS,
    c_FEAT_CIRC_EQUIVAL_RADIUS,
    c_FEAT_CIRC_ENCLOSE_RADIUS,
    c_FEAT_CIRC_CIRCUMS_RADIUS,

    c_FEAT_CIRC_INSCRIB_DIAMETER,
    c_FEAT_CIRC_INCLOSE_DIAMETER,
    c_FEAT_CIRC_EQUIVAL_DIAMETER,
    c_FEAT_CIRC_ENCLOSE_DIAMETER,
    c_FEAT_CIRC_CIRCUMS_DIAMETER,

    c_FEAT_MASS_CENTER_X,
    c_FEAT_RECT_AXEPAR_CENTER_X,
    c_FEAT_RECT_ROTATE_CENTER_X,
    c_FEAT_CIRC_INCLOSE_CENTER_X,
    c_FEAT_CIRC_ENCLOSE_CENTER_X,
    c_FEAT_ELLIPSE_FIT_CENTER_X,
    c_FEAT_RECT_AXEPAR_LEFT,
    c_FEAT_RECT_AXEPAR_RIGHT,

    c_FEAT_MASS_CENTER_Y,
    c_FEAT_RECT_AXEPAR_CENTER_Y,
    c_FEAT_RECT_ROTATE_CENTER_Y,
    c_FEAT_CIRC_INCLOSE_CENTER_Y,
    c_FEAT_CIRC_ENCLOSE_CENTER_Y,
    c_FEAT_ELLIPSE_FIT_CENTER_Y,
    c_FEAT_RECT_AXEPAR_TOP,
    c_FEAT_RECT_AXEPAR_BOTTOM,

    c_FEAT_MOMENT_SPATIAL_m00,
    c_FEAT_MOMENT_SPATIAL_m10,
    c_FEAT_MOMENT_SPATIAL_m01,
    c_FEAT_MOMENT_SPATIAL_m20,
    c_FEAT_MOMENT_SPATIAL_m11,
    c_FEAT_MOMENT_SPATIAL_m02,
    c_FEAT_MOMENT_SPATIAL_m30,
    c_FEAT_MOMENT_SPATIAL_m21,
    c_FEAT_MOMENT_SPATIAL_m12,
    c_FEAT_MOMENT_SPATIAL_m03,

    c_FEAT_MOMENT_CENTRAL_mu20,
    c_FEAT_MOMENT_CENTRAL_mu11,
    c_FEAT_MOMENT_CENTRAL_mu02,
    c_FEAT_MOMENT_CENTRAL_mu30,
    c_FEAT_MOMENT_CENTRAL_mu21,
    c_FEAT_MOMENT_CENTRAL_mu12,
    c_FEAT_MOMENT_CENTRAL_mu03,

    c_FEAT_MOMENT_CENTRAL_NORM_nu20,
    c_FEAT_MOMENT_CENTRAL_NORM_nu11,
    c_FEAT_MOMENT_CENTRAL_NORM_nu02,
    c_FEAT_MOMENT_CENTRAL_NORM_nu30,
    c_FEAT_MOMENT_CENTRAL_NORM_nu21,
    c_FEAT_MOMENT_CENTRAL_NORM_nu12,
    c_FEAT_MOMENT_CENTRAL_NORM_nu03,

    c_FEAT_MOMENT_INVARIANT_hu0,
    c_FEAT_MOMENT_INVARIANT_hu1,
    c_FEAT_MOMENT_INVARIANT_hu2,
    c_FEAT_MOMENT_INVARIANT_hu3,
    c_FEAT_MOMENT_INVARIANT_hu4,
    c_FEAT_MOMENT_INVARIANT_hu5,
    c_FEAT_MOMENT_INVARIANT_hu6,

    c_FEAT_DIST_CENTROID_2_CONTOUR,

    c_FEAT_SPHERE_EQUIV_VOL,

    c_FEAT_NUMBER_OF_FEATS
};
const std::vector<size_t> vFeatInvariant_Rotation = {
    //c_FEAT_LABEL,

    c_FEAT_HOLES,

    c_FEAT_CURL,
    c_FEAT_SOLIDITY,
    c_FEAT_COMPACTNESS,
    C_FEAT_CONVEXITY,
    c_FEAT_ROUNDNESS,
    c_FEAT_SPHERICITY,
    c_FEAT_RECTANGULARITY,
    //c_FEAT_RECT_AXEPAR_ASPECT_RATIO,
    c_FEAT_EXCENTRICITY,
    //c_FEAT_ELONGATION_RECT,
    c_FEAT_ELONGATION_ROT,

    c_FEAT_CURL_INV,
    c_FEAT_SOLIDITY_INV,
    c_FEAT_COMPACTNESS_INV,
    c_FEAT_CONVEXITY_INV,
    c_FEAT_ROUNDNESS_INV,
    c_FEAT_SPHERICITY_INV,
    c_FEAT_RECTANGULARITY_INV,
    //c_FEAT_RECT_AXEPAR_ASPECT_RATIO_INV,
    c_FEAT_EXCENTRICITY_INV,
    //c_FEAT_ELONGATION_RECT_INV,
    c_FEAT_ELONGATION_ROT_INV,

    //c_FEAT_RECT_ROTATE_ANGLE,
    //c_FEAT_ELLIPSE_FIT_ANGLE,
    //c_FEAT_DIRECTION,

    c_FEAT_COUNT_PIXEL,
    c_FEAT_AREA,
    c_FEAT_CONVEX_AREA,
    c_FEAT_RECT_AXEPAR_AREA,
    c_FEAT_RECT_ROTATE_AREA,
    c_FEAT_CIRC_INSCRIB_AREA,
    c_FEAT_CIRC_INCLOSE_AREA,
    c_FEAT_CIRC_EQUIVAL_AREA,
    c_FEAT_CIRC_ENCLOSE_AREA,
    c_FEAT_CIRC_CIRCUMS_AREA,
    c_FEAT_ELLIPSE_FIT_AREA,

    c_FEAT_COUNT_CONTOUR,
    c_FEAT_PERIMETER,
    c_FEAT_CONVEX_PERIMETER,
    c_FEAT_RECT_AXEPAR_PERIMETER,
    c_FEAT_RECT_ROTATE_PERIMETER,
    c_FEAT_CIRC_INSCRIB_PERIMETER,
    c_FEAT_CIRC_INCLOSE_PERIMETER,
    c_FEAT_CIRC_EQUIVAL_PERIMETER,
    c_FEAT_CIRC_ENCLOSE_PERIMETER,
    c_FEAT_CIRC_CIRCUMS_PERIMETER,
    c_FEAT_ELLIPSE_FIT_PERIMETER,

    c_FEAT_RECT_AXEPAR_WIDTH,
    c_FEAT_RECT_AXEPAR_SIDE_LONG,
    c_FEAT_RECT_ROTATE_WIDTH,
    c_FEAT_RECT_ROTATE_SIDE_LONG,
    c_FEAT_ELLIPSE_FIT_MAJOR_AXIS,
    c_FEAT_MAJOR_AXIS,
    c_FEAT_FIBRE_LENGTH,

    c_FEAT_RECT_AXEPAR_HEIGHT,
    c_FEAT_RECT_AXEPAR_SIDE_SHORT,
    c_FEAT_RECT_ROTATE_HEIGHT,
    c_FEAT_RECT_ROTATE_SIDE_SHORT,
    c_FEAT_ELLIPSE_FIT_MINOR_AXIS,
    c_FEAT_MINOR_AXIS,
    c_FEAT_FIBRE_WIDTH,

    c_FEAT_CIRC_INSCRIB_RADIUS,
    c_FEAT_CIRC_INCLOSE_RADIUS,
    c_FEAT_CIRC_EQUIVAL_RADIUS,
    c_FEAT_CIRC_ENCLOSE_RADIUS,
    c_FEAT_CIRC_CIRCUMS_RADIUS,

    c_FEAT_CIRC_INSCRIB_DIAMETER,
    c_FEAT_CIRC_INCLOSE_DIAMETER,
    c_FEAT_CIRC_EQUIVAL_DIAMETER,
    c_FEAT_CIRC_ENCLOSE_DIAMETER,
    c_FEAT_CIRC_CIRCUMS_DIAMETER,

    c_FEAT_MASS_CENTER_X,
    c_FEAT_RECT_AXEPAR_CENTER_X,
    c_FEAT_RECT_ROTATE_CENTER_X,
    c_FEAT_CIRC_INCLOSE_CENTER_X,
    c_FEAT_CIRC_ENCLOSE_CENTER_X,
    c_FEAT_ELLIPSE_FIT_CENTER_X,
    c_FEAT_RECT_AXEPAR_LEFT,
    c_FEAT_RECT_AXEPAR_RIGHT,

    c_FEAT_MASS_CENTER_Y,
    c_FEAT_RECT_AXEPAR_CENTER_Y,
    c_FEAT_RECT_ROTATE_CENTER_Y,
    c_FEAT_CIRC_INCLOSE_CENTER_Y,
    c_FEAT_CIRC_ENCLOSE_CENTER_Y,
    c_FEAT_ELLIPSE_FIT_CENTER_Y,
    c_FEAT_RECT_AXEPAR_TOP,
    c_FEAT_RECT_AXEPAR_BOTTOM,

    c_FEAT_MOMENT_SPATIAL_m00,
    c_FEAT_MOMENT_SPATIAL_m10,
    c_FEAT_MOMENT_SPATIAL_m01,
    c_FEAT_MOMENT_SPATIAL_m20,
    c_FEAT_MOMENT_SPATIAL_m11,
    c_FEAT_MOMENT_SPATIAL_m02,
    c_FEAT_MOMENT_SPATIAL_m30,
    c_FEAT_MOMENT_SPATIAL_m21,
    c_FEAT_MOMENT_SPATIAL_m12,
    c_FEAT_MOMENT_SPATIAL_m03,

    c_FEAT_MOMENT_CENTRAL_mu20,
    c_FEAT_MOMENT_CENTRAL_mu11,
    c_FEAT_MOMENT_CENTRAL_mu02,
    c_FEAT_MOMENT_CENTRAL_mu30,
    c_FEAT_MOMENT_CENTRAL_mu21,
    c_FEAT_MOMENT_CENTRAL_mu12,
    c_FEAT_MOMENT_CENTRAL_mu03,

    c_FEAT_MOMENT_CENTRAL_NORM_nu20,
    c_FEAT_MOMENT_CENTRAL_NORM_nu11,
    c_FEAT_MOMENT_CENTRAL_NORM_nu02,
    c_FEAT_MOMENT_CENTRAL_NORM_nu30,
    c_FEAT_MOMENT_CENTRAL_NORM_nu21,
    c_FEAT_MOMENT_CENTRAL_NORM_nu12,
    c_FEAT_MOMENT_CENTRAL_NORM_nu03,

    c_FEAT_MOMENT_INVARIANT_hu0,
    c_FEAT_MOMENT_INVARIANT_hu1,
    c_FEAT_MOMENT_INVARIANT_hu2,
    c_FEAT_MOMENT_INVARIANT_hu3,
    c_FEAT_MOMENT_INVARIANT_hu4,
    c_FEAT_MOMENT_INVARIANT_hu5,
    c_FEAT_MOMENT_INVARIANT_hu6,

    c_FEAT_DIST_CENTROID_2_CONTOUR,

    c_FEAT_SPHERE_EQUIV_VOL,

    c_FEAT_NUMBER_OF_FEATS
};*/

enum D_MARKER_SYMBOL {
    c_MARKER_SYMBOL_CIRCLE,
    c_MARKER_SYMBOL_DOT,
    c_MARKER_SYMBOL_RECT,
    c_MARKER_SYMBOL_PLUS,
    c_MARKER_SYMBOL_MINUS,
    c_MARKER_SYMBOL_CROSS,
    c_MARKER_SYMBOL_3CIRCLES,
    c_MARKER_SYMBOL_3DOTS,
    c_MARKER_SYMBOL_TICK,
    c_MARKER_SYMBOL_NUMBER_OF
};

enum D_GEO_ENUM {
    c_GEO_OFFSET,
    c_GEO_CENTROID,
    //c_GEO_AXIS_MAJOR,
    //c_GEO_AXIS_MINOR,
    c_GEO_CONTOUR,
    c_GEO_OUTLINE,
    c_GEO_CONVEX_HULL,
    c_GEO_CONVEX_DEFICIT,
    c_GEO_RECT_AXEPAR,
    c_GEO_RECT_ROTATE,
    c_GEO_CIRCLE_INSCRIB,
    c_GEO_CIRCLE_INCLOSE,
    c_GEO_CIRCLE_EQUIVAL,
    c_GEO_CIRCLE_ENCLOSE,
    c_GEO_CIRCLE_CIRCUMS,
    c_GEO_ELLIPSE_FIT,
    c_GEO_NUMBER_OF
};

static QStringList QSL_GeometricsList = {
    "Offset",
    "Centroid",
    //"Axis Major",
    //"Axis Minor",
    "Countour",
    "Outline",
    "Convex Hull",
    "Convex Deficit",
    "Rect AxeParallel",
    "Rect Rotated",
    "Circle Inscribing",
    "Circle Inclosing",
    "Circle Equivalent",
    "Circle Enclosing",
    "Cirlce Circumscribing",
    "Ellipse Fitted"
};

enum D_COMPDIST {
    c_COMPDIST_CONTOUR,
    c_COMPDIST_CONVEX_HULL,
    c_COMPDIST_OFFSET,
    c_COMPDIST_CENTER_MASS,
    c_COMPDIST_CENTER_RECT_AXEPAR,
    c_COMPDIST_CENTER_RECT_ROTATE,
    c_COMPDIST_CENTER_CIRC_INCLOSE,
    c_COMPDIST_CENTER_CIRC_ENCLOSE,
    c_COMPDIST_CENTER_ELLIPSE_FIT,
    c_COMPDIST_NUMBER_OF
};
const QStringList QSL_CompDist = {
    "Contour",
    "Convex Hull",
    "Offset",
    "Center Mass",
    "Center Rect Axe Parallel",
    "Center Rect Rotate",
    "Center Circle Inclosing",
    "Center Cirlce Enclosing",
    "Center"
    "ipse Fitted"
};

enum D_DIR2D {
    c_DIR2D_R,
    c_DIR2D_DR,
    c_DIR2D_D,
    c_DIR2D_DL,
    c_DIR2D_L,
    c_DIR2D_UL,
    c_DIR2D_U,
    c_DIR2D_UR,
    c_DIR2D_NUMBER_OF
};
const QStringList QSL_Direction = {
    "Right",
    "Down Right",
    "Down",
    "Down Left",
    "Left",
    "Up Left",
    "Up",
    "Up Right"
};

enum D_TIME_ENUM {
    c_TIME_IMG_PROC         = 0,
    c_TIME_IMG_CONV         = 1,
    c_TIME_IMG_SHOW         = 2,
    c_TIME_HIST             = 3,
    c_TIME_SOURCE_VIEW      = 4
};

enum D_AXE_ENUM {
    c_AXE_CARTESIAN_X       = 0,
    c_AXE_CARTESIAN_Y       = 1,
    c_AXE_POLAR_RADIUS      = 2,
    c_AXE_POLAR_ANGLE       = 3,
    c_AXE_NUMBER_OF         = 4
};

const QStringList QSL_Axe = {
    "Cartesian X Axis",
    "Cartesian Y Axis",
    "Polar Radius",
    "Polar Angle"
};

enum D_AXE_TRANS_ENUM {
    c_AXE_TRANS_LIN,
    c_AXE_TRANS_LOG_2,
    c_AXE_TRANS_LOG_E,
    c_AXE_TRANS_LOG_10,
    c_AXE_TRANS_1pX,
    c_AXE_TRANS_1pXX,
    c_AXE_TRANS_NUMBER_OF
};
const QStringList QSL_AxeTrans_x = {
    "x",
    "log_2(x)",
    "log_e(x)",
    "log_10(x)",
    "1/x",
    "1/x²"
};
const QStringList QSL_AxeTrans_y = {
    "y",
    "log_2(y)",
    "log_e(y)",
    "log_10(y)",
    "1/y",
    "1/y²"
};
const QStringList QSL_AxeTrans_Prefix = {
    "",
    "log_2(",
    "log_e(",
    "log_10(",
    "1/(",
    "1/("
};
const QStringList QSL_AxeTrans_Suffix = {
    "",
    ")",
    ")",
    ")",
    ")",
    ")²"
};

enum D_PLOT_X1D_Y1D {
    c_PLOT_X1D_Y1D_LINE,
    c_PLOT_X1D_Y1D_SCATTER
};
const QStringList QSL_Plot_X1D_Y1D = {
    "Line",
    "Scatter"
};

const QStringList QSl_AlphabetSmall {
    "a",
    "b",
    "c",
    "d",
    "e",
    "f",
    "g",
    "h",
    "i",
    "j",
    "k",
    "l",
    "m",
    "n",
    "o",
    "p",
    "q",
    "r",
    "s",
    "t",
    "u",
    "v",
    "w",
    "x",
    "y",
    "z"
};
const QStringList QSl_AlphabetBig {
    "A",
    "B",
    "C",
    "D",
    "E",
    "F",
    "G",
    "H",
    "I",
    "J",
    "K",
    "L",
    "M",
    "N",
    "O",
    "P",
    "Q",
    "R",
    "S",
    "T",
    "U",
    "V",
    "W",
    "X",
    "Y",
    "Z"
};
const QStringList QSl_AlphabetAll {
    "a",
    "b",
    "c",
    "d",
    "e",
    "f",
    "g",
    "h",
    "i",
    "j",
    "k",
    "l",
    "m",
    "n",
    "o",
    "p",
    "q",
    "r",
    "s",
    "t",
    "u",
    "v",
    "w",
    "x",
    "y",
    "z",
    "A",
    "B",
    "C",
    "D",
    "E",
    "F",
    "G",
    "H",
    "I",
    "J",
    "K",
    "L",
    "M",
    "N",
    "O",
    "P",
    "Q",
    "R",
    "S",
    "T",
    "U",
    "V",
    "W",
    "X",
    "Y",
    "Z"
};

const QStringList QSL_Counties = {
    "Afghanistan",
    "Albania",
    "Algeria",
    "Andorra",
    "Angola",
    "Antigua and Barbuda",
    "Argentina",
    "Armenia",
    "Australia",
    "Austria",
    "Azerbaijan",
    "Bahamas",
    "Bahrain",
    "Bangladesh",
    "Barbados",
    "Belarus",
    "Belgium",
    "Belize",
    "Benin",
    "Bhutan",
    "Bolivia",
    "Bosnia and Herzegovina",
    "Botswana",
    "Brazil",
    "Brunei",
    "Bulgaria",
    "Burkina Faso",
    "Burundi",
    "Côte d'Ivoire",
    "Cabo Verde",
    "Cambodia",
    "Cameroon",
    "Canada",
    "Central African Republic",
    "Chad",
    "Chile",
    "China",
    "Colombia",
    "Comoros",
    "Congo (Congo-Brazzaville)",
    "Costa Rica",
    "Croatia",
    "Cuba",
    "Cyprus",
    "Czechia (Czech Republic)",
    "Democratic Republic of the Congo",
    "Denmark",
    "Djibouti",
    "Dominica",
    "Dominican Republic",
    "Ecuador",
    "Egypt",
    "El Salvador",
    "Equatorial Guinea",
    "Eritrea",
    "Estonia",
    "Eswatini (fmr. 'Swaziland')",
    "Ethiopia",
    "Fiji",
    "Finland",
    "France",
    "Gabon",
    "Gambia",
    "Georgia",
    "Germany",
    "Ghana",
    "Greece",
    "Grenada",
    "Guatemala",
    "Guinea",
    "Guinea-Bissau",
    "Guyana",
    "Haiti",
    "Holy See",
    "Honduras",
    "Hungary",
    "Iceland",
    "India",
    "Indonesia",
    "Iran",
    "Iraq",
    "Ireland",
    "Israel",
    "Italy",
    "Jamaica",
    "Japan",
    "Jordan",
    "Kazakhstan",
    "Kenya",
    "Kiribati",
    "Kuwait",
    "Kyrgyzstan",
    "Laos",
    "Latvia",
    "Lebanon",
    "Lesotho",
    "Liberia",
    "Libya",
    "Liechtenstein",
    "Lithuania",
    "Luxembourg",
    "Madagascar",
    "Malawi",
    "Malaysia",
    "Maldives",
    "Mali",
    "Malta",
    "Marshall Islands",
    "Mauritania",
    "Mauritius",
    "Mexico",
    "Micronesia",
    "Moldova",
    "Monaco",
    "Mongolia",
    "Montenegro",
    "Morocco",
    "Mozambique",
    "Myanmar (formerly Burma)",
    "Namibia",
    "Nauru",
    "Nepal",
    "Netherlands",
    "New Zealand",
    "Nicaragua",
    "Niger",
    "Nigeria",
    "North Korea",
    "North Macedonia",
    "Norway",
    "Oman",
    "Pakistan",
    "Palau",
    "Palestine State",
    "Panama",
    "Papua New Guinea",
    "Paraguay",
    "Peru",
    "Philippines",
    "Poland",
    "Portugal",
    "Qatar",
    "Romania",
    "Russia",
    "Rwanda",
    "Saint Kitts and Nevis",
    "Saint Lucia",
    "Saint Vincent and the Grenadines",
    "Samoa",
    "San Marino",
    "Sao Tome and Principe",
    "Saudi Arabia",
    "Senegal",
    "Serbia",
    "Seychelles",
    "Sierra Leone",
    "Singapore",
    "Slovakia",
    "Slovenia",
    "Solomon Islands",
    "Somalia",
    "South Africa",
    "South Korea",
    "South Sudan",
    "Spain",
    "Sri Lanka",
    "Sudan",
    "Suriname",
    "Sweden",
    "Switzerland",
    "Syria",
    "Tajikistan",
    "Tanzania",
    "Thailand",
    "Timor-Leste",
    "Togo",
    "Tonga",
    "Trinidad and Tobago",
    "Tunisia",
    "Turkey",
    "Turkmenistan",
    "Tuvalu",
    "Uganda",
    "Ukraine",
    "United Arab Emirates",
    "United Kingdom",
    "United States of America",
    "Uruguay",
    "Uzbekistan",
    "Vanuatu",
    "Venezuela",
    "Vietnam",
    "Yemen",
    "Zambia",
    "Zimbabwe"
};

const QString QS_Fun_TableFlip = "(┛ಠ_ಠ)┛彡┻━┻";
const QString QS_Fun_Confused = "ಠಿ_ಠ";
const QString QS_Fun_IDontKnow = "¯\(◉‿◉)/¯";
const QString QS_Fun_Sad = "( ͡ಠ ʖ̯ ͡ಠ)";
const QString QS_Fun_Happy = "(✿◠‿◠)";
const QString QS_Fun_Cat = "(₌♥ᆽ♥₌)";

//Plot
const int
AXE_TICK_COUNT_DEFAULT  = 10;

//Angles
const double
PI                      = 3.1415926535897932384626433832795028841971693993751058209749445923078164062;
const double
PI_4_0                  = 4.0 * PI,
PI_2_0                  = 2.0 * PI,
PI_0_5                  = PI / 2.0,
PI_0_25                 = PI / 4.0;
const double
Rad2Grad                = 180.0 / PI,
Grad2Rad                = PI / 180.0;
const double c_E        = 2.71828182846;

static const std::complex<double> c_I = std::complex<double>(0.0, 1.0);

const double
SIGMA1_PROB             = 0.682689492,
SIGMA2_PROB             = 0.954499736,
SIGMA3_PROB             = 0.997300204,
SIGMA4_PROB             = 0.99993666,
SIGMA5_PROB             = 0.999999426697,
SIGMA6_PROB             = 0.999999998027,
SIGMA7_PROB             = 0.999999999997440;

const double
PH_g_earth              = 9.80665;

#endif // D_ENUM_H
