/************************************
 *   added:     02.06.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#ifndef D_IMAGEREWARDSYSTEM_H
#define D_IMAGEREWARDSYSTEM_H

//Qt
#include <QObject>
#include <QPixmap>
#include <QStringList>
#include <QString>
#include <QDebug>
#include <QLabel>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QByteArray>

//namespaces
using namespace std;

/*!
 * \brief The D_ImageRewardSystem class shows a <a href="https://thisxdoesnotexist.com/">random generated</a> image as a reward for the user for perfomring some action)
 * \details uses an online GAN. All credit for this belongs to the awesome <a href="https://thisxdoesnotexist.com/">https://thisxdoesnotexist.com/</a>. Requires a network connection.
 */
class D_ImageRewardSystem : public QObject
{
    Q_OBJECT

public:
    D_ImageRewardSystem();

    void set_target_label(QLabel *label);

public slots:
    bool get_reward();
    void set_mode_cat()     {mode_img = MODE_CAT;}
    void set_mode_horse()   {mode_img = MODE_HORSE;}
    void set_mode_person()  {mode_img = MODE_PERSON;}

private slots:
    void show_img(QNetworkReply* net_reply);

private:
    QLabel* label_target;
    bool state_label_set = false;

    QNetworkAccessManager* net_access;

    size_t mode_img = 0;
    enum MODI {
        MODE_CAT,
        MODE_HORSE,
        MODE_PERSON,
        MODE_NUMBER_OF
    };
    const QStringList QSl_WebUrls = {
        "https://thiscatdoesnotexist.com/",
        "https://thishorsedoesnotexist.com/",
        "https://thispersondoesnotexist.com/"
    };
};

#endif // D_IMAGEREWARDSYSTEM_H
