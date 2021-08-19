/************************************
 *   added:     22.07.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_DOCU_MAINPAGE_H
#define D_DOCU_MAINPAGE_H

//link to other docus
#include <d_docu_plugin_megafocitracker.h>

//mainpage for documentation (doxygen)
/*!
 * \mainpage Welcome to ImageD
 * \section intro_sec Introduction
 *
 * ImageD is an image processing software.
 *
 * What ImageD is intended to do/be:
 *      - Graphical user interface
 *      - Easy to handle for beginner users
 *      - Lots of parametric functions for advanced users
 *      - Multidimensional images and videos (up to 6D)
 *      - Rapid prototyping
 *      - Dynamic image processing chains
 *      - Interactive image analysis
 *      - Volumetric rendering of 3D data
 *      - Lots of plugins for biophysics applications at GSI Darmstadt
 *
 * What ImageD is not intended to do/be:
 *      - Industrial applications like quality control
 *      - High speed optimization
 *
 * \section istall_sec Installation
 *
 * ImageD is published as OpenSource under the <a href="https://www.gnu.org/licenses/gpl-3.0.de.html">GPL3</a> licence.
 * Its github repository can be found <a href="https://github.com/DavidEilenstein/ImageD">here</a>.
 *
 * Installation:
 *      1. Go to <a href="https://github.com/DavidEilenstein/ImageD/releases">https://github.com/DavidEilenstein/ImageD/releases</a>
 *      2. Select the version you want to dowload (click on the blue headline with v<number> in it. You can see the current version number at the top of this page)
 *      3. Download the "ImageD_v<number>.zip"
 *      4. Unzip it in a folder of your choice
 *      5. Double click the ImageD.exe to run the program
 *
 * \section plugin_sec Plugins
 *
 * ImageD includes a lot of plugins for specific tasks, mostly in the field of biophysics:
 *      - Cytoplasmatic dsDNA detection in fluorescence microscopy images
 *      - Mitochondria analysis in flim images
 *      - Cell colony size distribution measurement
 *      - Tracking nuclear foci over time (by Manon Nickler)
 *      - Measuring intensity profiles of ion tracks in crystals
 *      - Multipage TIF image visualizer (false color and basic processing)
 *      - DNA fibre thickness estimation (see below)
 *      - Radon decay curve fitting
 *      - Cerebral organoids size distribution estimation
 *      - Tracking microspheres on cilia cells (master thesis)
 *      - Air drag measuring from videos of falling objects (uni project)
 *      - \ref docu_megafocitracker_main "Nuclear foci tracking in timely resoluted mosaic images and cell pedigree estimation (WIP)"
 *      - Huang rank order filter visualization (uni project, see below)
 *      - Softmax classifier visualization (uni project, see below)
 *
 * \section doc_sec Documentation
 *
 * There are four types of documentation:
 *      1. Code:        The documentation of the code is done on this webpage. Just navigate with the panels on the left and on the top or use the serach function.
 *      2. Manuals:     There are user manual PDFs for each modul of the program. They are not public yet. Please contact me for more information.
 *      3. Theory:      My bachelor thesis about the concepts of ImageD and my master thesis about microsphere tracking on cilia in videos. Both not published yet. Please contact me for more information.
 *      4. Tutorials:   YouTube "how to" videos. See next section for direct links.
 *
 * \section links_sec Weblinks
 *
 * Some YouTube-Tutorials can be found here:
 *      - <a href="https://youtu.be/j_3wfKGABgQ">Huang rank order filtering explanantion and visualization</a> (german)
 *      - <a href="https://youtu.be/thr8br8_YJs">kNN classifier</a> (german)
 *      - <a href="https://youtu.be/vHl2Vqof2p0">Softmax classifier</a> (german)
 *      - <a href="https://youtu.be/OQ3y6DO9kbU">Selfmade watershed transform implementation</a> (german)
 *      - <a href="https://youtu.be/2OATSGe2Oks">How diescrete fourier transformation works</a> (german)
 *      - <a href="https://youtu.be/5YFlQxvubiA">Michelson interferometer simulation</a> (german)
 *
 * \subsection links_sec_projects Projects
 *
 * ImageD is used mainly in the field of <a href="https://www.gsi.de/en/work/research/biophysics.htm">biophysics</a> at <a href="https://www.gsi.de/en/start/news.htm">GSI Darmstadt</a>.
 *
 * List of projects, where ImageD was used:
 *      - Estimating DNA fiber thickness: <a href="https://pubmed.ncbi.nlm.nih.gov/32168789/">Correlative Light and Electron Microscopy (CLEM) Analysis of Nuclear Reorganization Induced by Clustered DNA Damage Upon Charged Particle Irradiation</a>
 *      - Quantification of immune cells in tumor slices: <a href="https://www.sciencedirect.com/science/article/pii/S0360301620343431?via%3Dihub">Reduction of lung metastases in a mouse osteosarcoma model treated with carbon ions and immune checkpoint inhibitors</a>
 *      - More projects will be added soon. Permissions needed to publish links here.
 *
 * \subsection links_sec_3rdPartySoftware Third Party Software
 *
 * To develop, document and distribute ImageD these tools where used:
 *      - The main programming language is <a href="https://en.cppreference.com/w/">C++</a>
 *      - As IDE <a href="https://www.qt.io/product/development-tools">Qt Creator</a> is used
 *      - For the graphical user interface and some usefull classes the <a href="https://doc.qt.io/qt-5/">Qt Framework</a> is used
 *      - The base image container and some image processing methods come from <a href="https://docs.opencv.org/master/">OpenCV</a>
 *      - This documentation is created by <a href="https://www.doxygen.nl/index.html">doxygen</a>
 *      - The distribution and website hosting is done by <a href="https://github.com/">git hub</a> and <a href="https://pages.github.com/">git hub pages</a>
 *
 *
 * \section other_sec Other
 *
 * \subsection other_sec_thanks Thanks
 *
 * Special thanks goes to:
 *      - My former supervisor at <a href="https://www.gsi.de/en/start/news.htm">GSI</a> <a href="https://www.gsi.de/work/forschung/biophysik/team_details.htm?no_cache=1&name=scholz&vorname=michael">Dr. Michael Scholz</a> who gives me a lot of freedom in developing ImageD and who trusts my skills
 *      - The professors in <a href="https://fbmn.h-da.de/index.php/Studienangebote/OBV">Machine Vision and Photonics</a> at <a href="https://h-da.de/">Hochschule Darmstadt</a> who always take time for my crazy questions. In particular <a href="https://www.fbmn.h-da.de/~ohser/">Prof. Dr. Joachim Ohser</a>, <a href="https://fbmn.h-da.de/~netzsch/">Prof. Dr. Thomas Netzsch</a> and <a href="https://www.fbmn.h-da.de/~heckenkamp/">Prof. Dr. Christoph Heckenkamp</a>
 *      - My fellow students Chiara, <a href="https://github.com/schnaader">Christian</a> and <a href="https://github.com/B-LechCode">Simon</a> who are always good discussion partners with clever ideas
 *
 * \subsection other_sec_dev Developer
 *
 * Information about the developer:
 *      - Name: David Eilenstein
 *      - Contact: D.Eilenstein@gsi.de
 *      - Degree: Bachelor and Master of Science in <a href="https://fbmn.h-da.de/index.php/Studienangebote/OBV">Machine Vision and Photonics</a> at <a href="https://h-da.de/">Hochschule Darmstadt</a>
 *      - Job: Writing ImageD and plugins for specialized solutions in the <a href="https://www.gsi.de/en/work/research/biophysics.htm">biophysics</a> department at <a href="https://www.gsi.de/en/start/news.htm">GSI Darmstadt</a>
 *      - Other: <a href="https://youtu.be/n-_fRfmTA1M">The species of athletic nerds actually exist :-P</a>
 *
 */

#endif // D_DOCU_MAINPAGE_H
