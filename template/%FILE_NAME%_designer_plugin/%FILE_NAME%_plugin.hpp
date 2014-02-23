/**

@author Mattia Basaglia

@section License

    Copyright (C) %COPY_YEARS% Mattia Basaglia

    This is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This software is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this software.  If not, see <http://www.gnu.org/licenses/>.

*/
#ifndef %HEADER_GUARD%_PLUGIN_HPP
#define %HEADER_GUARD%_PLUGIN_HPP

#include <QObject>
#include <QDesignerCustomWidgetInterface>

class %CLASS_NAME%_Plugin : public QObject, public QDesignerCustomWidgetInterface
{
    Q_OBJECT
    Q_INTERFACES(QDesignerCustomWidgetInterface)

public:
    %CLASS_NAME%_Plugin(QObject *parent = 0);

    void initialize(QDesignerFormEditorInterface *core);
    bool isInitialized() const;

    QWidget *createWidget(QWidget *parent);

    QString name() const;
    QString group() const;
    QIcon icon() const;
    QString toolTip() const;
    QString whatsThis() const;
    bool isContainer() const;

    QString domXml() const;

    QString includeFile() const;

private:
    bool initialized;
};


#endif // %HEADER_GUARD%_PLUGIN_HPP
