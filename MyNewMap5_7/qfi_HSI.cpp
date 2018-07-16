/***************************************************************************//**
 * @file qfi_HSI.cpp
 * @author  Marek M. Cel <marekcel@marekcel.pl>
 *
 * @section LICENSE
 *
 * Copyright (C) 2013 Marek M. Cel
 *
 * This file is part of QFlightInstruments. You can redistribute and modify it
 * under the terms of GNU General Public License as published by the Free
 * Software Foundation; either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.
 * 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * Further information about the GNU General Public License can also be found
 * on the world wide web at http://www.gnu.org.
 *
 * ---
 *
 * Copyright (C) 2013 Marek M. Cel
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 ******************************************************************************/
#ifndef QFI_HSI_CPP
#define QFI_HSI_CPP
#endif

////////////////////////////////////////////////////////////////////////////////

#ifdef WIN32
#include <float.h>
#endif

#include <math.h>
#include <QDebug>
#include "qfi_HSI.h"
#include <QTimer>
////////////////////////////////////////////////////////////////////////////////

qfi_HSI::qfi_HSI( QWidget *parent ) :
    QGraphicsView ( parent ),

    m_scene ( 0 ),

    m_itemFace ( 0 ),

    m_heading ( 0.0f ),

    m_scaleX ( 1.0f ),
    m_scaleY ( 1.0f ),

    m_faceZ ( 9 )
{
    reset();
    m_scene = new QGraphicsScene( this );
    setScene( m_scene );
    m_scene->clear();

}
void qfi_HSI::setOrignalSizeAndCoordinate(int height,int width,float x,float y)
{
    m_originalHeight = height;
    m_originalWidth = width;
    m_originalHsiCtr.setX(x);
    m_originalHsiCtr.setY(y);
    m_scene->setSceneRect(0,0,height+5,width+5);
}

////////////////////////////////////////////////////////////////////////////////

qfi_HSI::~qfi_HSI()
{
    if ( m_scene )
    {
        m_scene->clear();
        delete m_scene;
        m_scene = 0;
    }

    reset();
}

////////////////////////////////////////////////////////////////////////////////

void qfi_HSI::reinit()
{
    if ( m_scene )
    {
        m_scene->clear();

        init();
    }
}

////////////////////////////////////////////////////////////////////////////////

void qfi_HSI::update()
{
    updateView();
}

////////////////////////////////////////////////////////////////////////////////

void qfi_HSI::setHeading( float heading,int x,int y )
{
    m_itemFace->setPos(x*m_scaleX,y*m_scaleY);
    m_heading = heading;
    updateView();
}

////////////////////////////////////////////////////////////////////////////////

void qfi_HSI::resizeEvent( QResizeEvent *event )
{
    ////////////////////////////////////
    QGraphicsView::resizeEvent( event );
    ////////////////////////////////////

    reinit();
}

////////////////////////////////////////////////////////////////////////////////
void qfi_HSI::addItem(QString path)
{
    itemPath = path;
    init();
}
void qfi_HSI::init()
{
    m_scaleX = (float)width()  / (float)m_originalWidth;
    m_scaleY = (float)height() / (float)m_originalHeight;

    reset();

    m_itemFace = new QGraphicsSvgItem( itemPath );
    m_itemFace->setCacheMode( QGraphicsItem::NoCache );
    m_itemFace->setZValue( m_faceZ );   //设置item的堆叠顺序,数值越小代表靠前
    m_itemFace->setTransform( QTransform::fromScale( m_scaleX, m_scaleY ), true );

    m_itemFace->setTransformOriginPoint( m_originalHsiCtr );//设置变换原点,此变换远点必须为原图大小的中心点，并不是变化后的
    m_scene->addItem( m_itemFace );

    centerOn( width() / 2.0f , height() / 2.0f );

    updateView();
}

////////////////////////////////////////////////////////////////////////////////

void qfi_HSI::reset()
{
    m_itemFace = 0;
}

////////////////////////////////////////////////////////////////////////////////

void qfi_HSI::updateView()
{
    m_itemFace->setRotation(  m_heading );

    m_scene->update();
}


