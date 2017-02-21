/***************************************************************************
                          checklistitemext.cpp  -  description
                             -------------------
    begin                : Thu Jan 24 2002
    copyright            : (C) 2002 by Michael Herder
    email                : crapsite@gmx.net
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "checklistitemext.h"

#include <qpainter.h>
#include <qpen.h>
#include <qpixmap.h>

CheckListItemExt::CheckListItemExt(QListWidget* parent,const QString& text)
                :QListWidgetItem(text,parent)
{
  mBgColor = qRgb(0,0,0);
  mFgColor = qRgb(255,255,255);
  mNumber = 0;
  updatePixmap();
}
CheckListItemExt::CheckListItemExt(QListWidget* parent,const QString& text,
                                   const QPixmap& p)
                :QListWidgetItem(QIcon(p), text,parent)
{
  mBgColor = qRgb(0,0,0);
  mFgColor = qRgb(255,255,255);
  mNumber = 0;
  updatePixmap();
}

CheckListItemExt::CheckListItemExt(QListWidgetItem*parent,const QString& text)
                :QListWidgetItem(*parent)
{
  setText(text);
  mBgColor = qRgb(0,0,0);
  mFgColor = qRgb(255,255,255);
  mNumber = 0;
  updatePixmap();
}
CheckListItemExt::CheckListItemExt(QListWidgetItem* parent,const QString& text,
                                   const QPixmap& p)
                :QListWidgetItem(*parent)
{
  setText(text);
  setIcon(QIcon(p));
  mBgColor = qRgb(0,0,0);
  mFgColor = qRgb(255,255,255);
  mNumber = 0;
  updatePixmap();
}
CheckListItemExt::~CheckListItemExt()
{
}
/** No descriptions */
void CheckListItemExt::setBgColor(QRgb bg_color)
{
  mBgColor = bg_color;
  updatePixmap();
}
/** No descriptions */
QRgb CheckListItemExt::bgColor()
{
  return mBgColor;
}
/** No descriptions */
void CheckListItemExt::setFgColor(QRgb fg_color)
{
  mFgColor = fg_color;
  updatePixmap();
}
/** No descriptions */
QRgb CheckListItemExt::fgColor()
{
  return mFgColor;
}
/** No descriptions */
void CheckListItemExt::updatePixmap()
{
  QPixmap pix(14,14);
  pix.fill(QColor(mBgColor));
  QPainter p;
  p.begin(&pix);
  p.setPen(QColor(mFgColor));
  p.setBrush(QColor(mFgColor));
  p.drawRect(3,3,8,8);
  p.end();
  setIcon(QIcon(pix));
}
/** No descriptions */
void CheckListItemExt::setNumber(int i)
{
  mNumber = i;
}
/** No descriptions */
int CheckListItemExt::number()
{
  return mNumber;
}
