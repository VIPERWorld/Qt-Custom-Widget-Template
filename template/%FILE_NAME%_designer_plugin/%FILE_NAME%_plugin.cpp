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
#include "%FILE_NAME%_plugin.hpp"
#include "%FILE_NAME%.hpp"

%CLASS_NAME%_Plugin::%CLASS_NAME%_Plugin(QObject *parent) :
    QObject(parent), initialized(false)
{
}

void %CLASS_NAME%_Plugin::initialize(QDesignerFormEditorInterface *)
{
    initialized = true;
}

bool %CLASS_NAME%_Plugin::isInitialized() const
{
    return initialized;
}

QWidget *%CLASS_NAME%_Plugin::createWidget(QWidget *parent)
{
    return new %CLASS_NAME%(parent);
}

QString %CLASS_NAME%_Plugin::name() const
{
    return "%CLASS_NAME%";
}

QString %CLASS_NAME%_Plugin::group() const
{
    return "Input Widgets"; ///\todo Group
}

QIcon %CLASS_NAME%_Plugin::icon() const
{
    return QIcon(); ///\todo Icon
}

QString %CLASS_NAME%_Plugin::toolTip() const
{
    return "%HUMAN_READABLE%"; ///\todo Tooltip
}

QString %CLASS_NAME%_Plugin::whatsThis() const
{
    return "%HUMAN_READABLE%"; ///\todo whats this 
}

bool %CLASS_NAME%_Plugin::isContainer() const
{
    return false;
}

QString %CLASS_NAME%_Plugin::domXml() const
{
    return "<ui language=\"c++\">\n"
           " <widget class=\"%CLASS_NAME%\" name=\"%FILE_NAME%\">\n"
           " </widget>\n"
           "</ui>\n";
}

QString %CLASS_NAME%_Plugin::includeFile() const
{
    return "%FILE_NAME%.hpp";
}


