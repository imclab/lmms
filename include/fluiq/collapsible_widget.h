/*
 * collapsible_widget.h - header file for FLUIQ::CollapsibleWidget
 *
 * Copyright (c) 2008 Tobias Doerffel <tobydox/at/users.sourceforge.net>
 * 
 * This file is part of Linux MultiMedia Studio - http://lmms.sourceforge.net
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 */

#ifndef _FLUIQ_COLLAPSIBLE_WIDGET_H
#define _FLUIQ_COLLAPSIBLE_WIDGET_H

#include <QtGui/QBoxLayout>

#include "fluiq/widget.h"


namespace FLUIQ
{

class CollapsibleWidget;

class CollapsibleWidgetHeader : public Widget
{
	Q_OBJECT
public:
	CollapsibleWidgetHeader( CollapsibleWidget * _parent );
	virtual ~CollapsibleWidgetHeader();


	inline bool isCollapsed( void ) const
	{
		return m_collapsed;
	}

	void setCollapsed( bool _c );

	virtual QSize sizeHint( void ) const;


protected:
	virtual void enterEvent( QEvent * _ev );
	virtual void leaveEvent( QEvent * _ev );
	virtual void mousePressEvent( QMouseEvent * _ev );
	virtual void mouseMoveEvent( QMouseEvent * _event );
	virtual void mouseReleaseEvent( QMouseEvent * _ev );
	virtual void paintEvent( QPaintEvent * _ev );


private:
	CollapsibleWidget * m_parent;
	bool m_hovered;
	bool m_pressed;
	bool m_collapsed;
	bool m_moved;
	QPoint m_origMousePos;

	QPixmap m_arrowCollapsed;
	QPixmap m_arrowExpanded;


signals:
	void expanded( void );
	void collapsed( void );

} ;



class CollapsibleWidget : public Widget
{
	Q_OBJECT
public:
	CollapsibleWidget( Qt::Orientation _or, Widget * _parent = NULL );
	virtual ~CollapsibleWidget();

	void addWidget( QWidget * _w );
	void insertWidget( int _idx, QWidget * _w );

	inline QString labelText( void ) const
	{
		return m_header->windowTitle();
	}

	inline void setLabelText( const QString & _text )
	{
		m_header->setWindowTitle( _text );
	}

	inline Qt::Orientation orientation( void ) const
	{
		return m_orientation;
	}


public slots:
	void expand( void );
	void collapse( void );


private:
	Qt::Orientation m_orientation;

	QBoxLayout * m_masterLayout;
	CollapsibleWidgetHeader * m_header;

} ;


}

#endif