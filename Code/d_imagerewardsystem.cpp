/************************************
 *   added:     02.06.2021          *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  GSI Darmstadt, Ger  *
 ************************************/

#include "d_imagerewardsystem.h"


D_ImageRewardSystem::D_ImageRewardSystem()
{
    //create instance of net access manager
    net_access = new QNetworkAccessManager();

    //make "show_img" respond to net requests when they are finihsed (async)
    connect(net_access, SIGNAL(finished(QNetworkReply*)), this, SLOT(show_img(QNetworkReply*)));
}

void D_ImageRewardSystem::set_target_label(QLabel *label)
{
    label_target = label;
    state_label_set = true;
}

bool D_ImageRewardSystem::get_reward()
{
    if(!state_label_set)
        return false;

    //get url and request
    QUrl url(QSl_WebUrls[mode_img]);
    QNetworkRequest request(url);

    //get reply (proecessed async when reply has finished)
    net_access->get(request);

    return true;
}

void D_ImageRewardSystem::show_img(QNetworkReply *net_reply)
{
    if(!state_label_set)
    {
        qDebug() << "D_ImageRewardSystem::show_img" << "target label not set";
        return;
    }

    if(net_reply->error())
    {
        qDebug() << "D_ImageRewardSystem::show_img" << "net reply error";
        return;
    }

    //read data to buffer (should be img data)
    QByteArray data_buffer = net_reply->readAll();

    //put data in pixmap (cast to img)
    QPixmap PX_img;
    PX_img.loadFromData(data_buffer);
    if(PX_img.isNull())
    {
        qDebug() << "D_ImageRewardSystem::show_img" << "pixmap empty";
        return;
    }

    //scale PX to label and show it
    PX_img = PX_img.scaled(
                max(1, label_target->width() - 2),
                max(1, label_target->height() - 2),
                Qt::KeepAspectRatio,
                Qt::FastTransformation);
    label_target->setPixmap(PX_img);

    //delete reply
    net_reply->deleteLater();
}
