#-------------------------------------------------
#
# Project created by QtCreator 2018-09-11T09:00:36
#
#-------------------------------------------------

QT       += core gui
QT       += charts
QT       += multimedia
QT       += multimediawidgets
QT       += datavisualization
#QT       += winextras

#CONFIG+= static

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImageD
TEMPLATE = app

INCLUDEPATH += C:/opencv/build/include
INCLUDEPATH += D:/opencv/build/include
LIBS += -LC:\opencv\build\x64\vc15\lib
LIBS += -LD:\opencv\build\x64\vc15\lib
LIBS += -lopencv_world343
LIBS += -lopencv_world343d

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    d_bio_attribute_filter.cpp \
    d_bio_focus.cpp \
    d_bio_nucleusblob.cpp \
    d_bio_nucleusimage.cpp \
    d_bio_nucleuslife.cpp \
    d_bio_nucleuspedigree.cpp \
    d_contour.cpp \
    d_datavolume_3d.cpp \
    d_featureset.cpp \
    d_finishtimeprognosis.cpp \
    d_geo_line_2d.cpp \
    d_geo_line_3d.cpp \
    d_geo_lineset_2d.cpp \
    d_geo_plane_3d.cpp \
    d_geo_point_2d.cpp \
    d_geo_point_3d.cpp \
    d_geo_pointset_2d.cpp \
    d_imagerewardsystem.cpp \
    d_job_manager.cpp \
    d_makro_airdragtrack.cpp \
    d_makro_ciliaspheretracker.cpp \
    d_makro_focicounter.cpp \
    d_makro_fouriertransformator.cpp \
    d_makro_megafoci.cpp \
    d_makro_softmaxvisualization.cpp \
    d_multidimloop.cpp \
    d_pdf_writer.cpp \
    d_physics.cpp \
    d_popup_feedbackrequest.cpp \
    d_popup_listedit_numbers.cpp \
    d_popup_rangeselector.cpp \
    d_videoslicer.cpp \
    d_videowriter.cpp \
    d_viewer_3d.cpp \
    d_viewer_plot_3d.cpp \
    d_visdat_header.cpp \
        main.cpp \
        d_mainwindow.cpp \
    d_stepwindow.cpp \
    scenemousetrack.cpp \
    d_storage.cpp \
    d_img_proc.cpp \
    d_plot.cpp \
    d_makro_corefoci.cpp \
    d_makro_mitochondrien.cpp \
    d_stat.cpp \
    d_stat_tester.cpp \
    d_viewer.cpp \
    d_makro_eilenstein.cpp \
    d_error_handler.cpp \
    d_makro_cellcolonies.cpp \
    m_makro_foci.cpp \
    d_component.cpp \
    d_component_list.cpp \
    d_value_distribution_list.cpp \
    d_analysiswindow.cpp \
    d_table.cpp \
    d_makro_iontracks.cpp \
    d_makro_visualization.cpp \
    d_math.cpp \
    d_viewer_plot.cpp \
    d_makro_osteoclasts.cpp \
    d_visdat_proc.cpp \
    d_visdat_dim.cpp \
    d_visdat_slicing.cpp \
    d_visdat_obj.cpp \
    d_visdat_range.cpp \
    d_img_proc_2dfactory.cpp \
    d_visdat_slice_nd.cpp \
    d_visdat_slice_2d.cpp \
    d_visdat_slice_1d.cpp \
    d_visdat_slice_3d.cpp \
    d_img_proc_3d.cpp \
    d_img_proc_3dfactory.cpp \
    d_makro_dnafiber.cpp \
    d_makro_curvefitting.cpp \
    d_makro_segmentationassistant.cpp \
    d_component_list_context.cpp \
    d_component_analysis.cpp \
    d_popup_listedit.cpp \
    d_popup_plot.cpp \
    d_makro_cerebralorganoids.cpp \
    d_popup_listselect.cpp \
    d_makro_manuelsegmentation.cpp \
    d_makro_huangvisualization.cpp

HEADERS += \
    d_bio_attribute_filter.h \
    d_bio_enum.h \
    d_bio_enum.h \
    d_bio_focus.h \
    d_bio_nucleusblob.h \
    d_bio_nucleusimage.h \
    d_bio_nucleuslife.h \
    d_bio_nucleuspedigree.h \
    d_contour.h \
    d_datavolume_3d.h \
    d_docu_mainpage.h \
    d_docu_plugin_megafocitracker.h \
    d_featureset.h \
    d_finishtimeprognosis.h \
    d_geo_line_2d.h \
    d_geo_line_3d.h \
    d_geo_lineset_2d.h \
    d_geo_plane_3d.h \
    d_geo_point_2d.h \
    d_geo_point_3d.h \
    d_geo_pointset_2d.h \
    d_imagerewardsystem.h \
    d_job_manager.h \
        d_mainwindow.h \
    d_makro_airdragtrack.h \
    d_makro_ciliaspheretracker.h \
    d_makro_focicounter.h \
    d_makro_fouriertransformator.h \
    d_makro_megafoci.h \
    d_makro_softmaxvisualization.h \
    d_multidimloop.h \
    d_opencv_typedefs.h \
    d_pdf_writer.h \
    d_physics.h \
    d_popup_feedbackrequest.h \
    d_popup_listedit_numbers.h \
    d_popup_rangeselector.h \
    d_stepwindow.h \
    d_videoslicer.h \
    d_videowriter.h \
    d_viewer_3d.h \
    d_viewer_plot_3d.h \
    d_visdat_header.h \
    scenemousetrack.h \
    d_storage.h \
    d_img_proc.h \
    d_plot.h \
    d_makro_corefoci.h \
    d_makro_mitochondrien.h \
    d_stat.h \
    d_stat_tester.h \
    d_viewer.h \
    d_makro_eilenstein.h \
    d_error_handler.h \
    d_makro_cellcolonies.h \
    m_makro_foci.h \
    d_component.h \
    d_component_list.h \
    d_enum.h \
    d_value_distribution_list.h \
    d_analysiswindow.h \
    d_table.h \
    d_makro_iontracks.h \
    d_makro_visualization.h \
    d_math.h \
    d_viewer_plot.h \
    d_makro_osteoclasts.h \
    d_visdat_proc.h \
    d_visdat_dim.h \
    d_visdat_slicing.h \
    d_visdat_obj.h \
    d_visdat_range.h \
    d_img_proc_2dfactory.h \
    d_visdat_slice_nd.h \
    d_visdat_slice_2d.h \
    d_visdat_slice_1d.h \
    d_visdat_slice_3d.h \
    d_img_proc_3d.h \
    d_img_proc_3dfactory.h \
    d_makro_dnafiber.h \
    d_makro_curvefitting.h \
    d_makro_segmentationassistant.h \
    d_component_list_context.h \
    d_component_analysis.h \
    d_popup_listedit.h \
    d_popup_plot.h \
    d_makro_cerebralorganoids.h \
    d_popup_listselect.h \
    d_makro_manuelsegmentation.h \
    d_makro_huangvisualization.h

FORMS += \
        d_mainwindow.ui \
    d_makro_airdragtrack.ui \
    d_makro_ciliaspheretracker.ui \
    d_makro_focicounter.ui \
    d_makro_fouriertransformator.ui \
    d_makro_megafoci.ui \
    d_makro_softmaxvisualization.ui \
    d_popup_feedbackrequest.ui \
    d_popup_listedit_numbers.ui \
    d_popup_rangeselector.ui \
    d_stepwindow.ui \
    d_makro_corefoci.ui \
    d_makro_mitochondrien.ui \
    d_stat_tester.ui \
    d_makro_eilenstein.ui \
    d_makro_cellcolonies.ui \
    m_makro_foci.ui \
    d_analysiswindow.ui \
    d_makro_iontracks.ui \
    d_makro_visualization.ui \
    d_makro_osteoclasts.ui \
    d_makro_dnafiber.ui \
    d_makro_curvefitting.ui \
    d_makro_segmentationassistant.ui \
    d_popup_listedit.ui \
    d_popup_plot.ui \
    d_makro_cerebralorganoids.ui \
    d_popup_listselect.ui \
    d_makro_manuelsegmentation.ui \
    d_makro_huangvisualization.ui

RESOURCES += \
    img/images.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
