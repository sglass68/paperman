/***************************************************************************
                          qoptionscrollview.cpp  -  description
                             -------------------
    begin                : Thu Jul 20 2000
    copyright            : (C) 2000 by M. Herder
    email                : crapsite@gmx.net
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License version 2 as     *
 *   published by the Free Software Foundation.                            *
 *                                                                         *
 ***************************************************************************/

#include "err.h"
#include "qoptionscrollview.h"
#include <qsizepolicy.h>
#include <qwidget.h>
#include <qlayout.h>
#include <QResizeEvent>
#include <QLabel>

QOptionScrollView::QOptionScrollView(QWidget * parent, const char * name,Qt::WFlags f)
                  :QScrollArea(parent)
{
  UNUSED (f);
  setObjectName (name);
//  setHScrollBarMode(AlwaysOff);
  setHorizontalScrollBarPolicy (Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy (Qt::ScrollBarAlwaysOn);
#if 0
  QPalette palette;
  palette.setBrush(viewport()->backgroundRole(), QPalette::Background);
  viewport()->setPalette(palette);
  viewport()->setBackgroundMode(QPalette::Background);
#endif
  mpMainWidget = new QWidget(/*viewport()*/);
  mpMainLayout = new QBoxLayout(QBoxLayout::TopToBottom, mpMainWidget);
//   QLabel *label = new QLabel ("hello there");
//   mpMainLayout->addWidget (label);
//  addChild(mpMainWidget);
  setWidget (mpMainWidget);
//   mpMainWidget->setLayout (mpMainLayout);
//   setLayout (mpMainLayout);
//   setWidgetResizable (true);
//   mpMainWidget->setFixedWidth(150);
//   mpMainWidget->setFixedHeight(150);
}
QOptionScrollView::~QOptionScrollView()
{
}

#if 0
/**  */
void QOptionScrollView::viewportResizeEvent(QResizeEvent* qre)
{
  Q3ScrollView::viewportResizeEvent(qre);
  if((mpMainWidget->sizeHint().isValid()==TRUE)&&(visibleWidth()>0))
  {
    mpMainWidget->setFixedWidth(visibleWidth());//,m_pMemberBox->height());
  }
}
#endif


/**  */
void QOptionScrollView::resizeEvent(QResizeEvent* qre)
{
   // resize the scrollview to take full advantage of the width available
  QScrollArea::resizeEvent(qre);
  mpMainWidget->resize (geometry ().width (), mpMainWidget->geometry ().height ());
}

void QOptionScrollView::addWidget(QWidget* qw,int stretch)
{
  mpMainLayout->addWidget(qw,stretch);
//   mpMainWidget->updateGeometry ();
//   mpMainWidget->setMinimumSize(mpMainLayout->minimumSize ());
}
