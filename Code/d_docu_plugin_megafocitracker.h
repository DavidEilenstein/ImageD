/************************************
 *   added:     22.07.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/


#ifndef D_DOCU_PLUGIN_MEGAFOCITRACKER_H
#define D_DOCU_PLUGIN_MEGAFOCITRACKER_H

/*!
 * \page docu_megafocitracker_main documentation - mega foci tracker
 * \section sec_abstract abstract
 * This plugin analyses timly resolved mosaic images of living cells before and after irradiation.
 * This is done in a concept consisting of six steps, that are executed successively:
 *      1. Images are loaded and nuclei and foci are detected automatically. These detections and basic stitched overview mosaics are saved.
 *      2. Automatic detections from step 1 are edited manually to increase accuracy.
 *      3. Corrected detections from step 2 and input images from step 0/1 are loaded. Detected foci are assigned to corrected nuclei and statistics about value distribution in nuclei are done and saved. Additional mosaics with information about foci detection counts, shape and value distribution statistics are saved.
 *      4. Based on output from step 3, the cell pedigree is reconstructed automatically.
 *      5. Automatically calculated cell pedigree from step 3 is corrected manually to increase accuracy.
 *      6. Various statistics, plots and graphics can be calculated and saved.
 *
 */

#endif // D_DOCU_PLUGIN_MEGAFOCITRACKER_H
