/****************************************************************************
**
** This file is part of the LibreCAD project, a 2D CAD program
**
** Copyright (C) 2010 R. van Twisk (librecad@rvt.dds.nl)
** Copyright (C) 2001-2003 RibbonSoft. All rights reserved.
**
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file gpl-2.0.txt included in the
** packaging of this file.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
**
** This copyright notice MUST APPEAR in all copies of the script!
**
**********************************************************************/
#ifndef QG_CADTOOLBARINFO_H
#define QG_CADTOOLBARINFO_H

class QG_CadToolBar;

#include "qg_actionhandler.h"
#include "lc_cadtoolbarinterface.h"

class QG_CadToolBarInfo : public LC_CadToolBarInterface
{
    Q_OBJECT

public:
	QG_CadToolBarInfo(QG_CadToolBar* parent = 0, Qt::WindowFlags fl = 0);
	~QG_CadToolBarInfo() = default;
    //restore action from checked button
	virtual void restoreAction();
	RS2::ToolBarId rtti() const
	{
		return RS2::ToolBarInfo;
	}
	virtual void addSubActions(const std::vector<QAction*>& actions, bool addGroup=true);


public slots:
    virtual void resetToolBar();
    virtual void showCadToolBar(RS2::ActionType actionType);

private slots:
    void on_bBack_clicked();
private:
	QAction *bDist=nullptr, *bDist2=nullptr, *bAngle=nullptr, *bTotalLength=nullptr, *bArea=nullptr;
};

#endif // QG_CADTOOLBARINFO_H
