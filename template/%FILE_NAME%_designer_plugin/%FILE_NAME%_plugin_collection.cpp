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
#include "%FILE_NAME%_plugin_collection.hpp"
#include "%FILE_NAME%_plugin.hpp"

%CLASS_NAME%_Plugin_Collection::%CLASS_NAME%_Plugin_Collection(QObject *parent) :
    QObject(parent)
{
    widgets.push_back(new %CLASS_NAME%_Plugin(this));
}

QList<QDesignerCustomWidgetInterface *> %CLASS_NAME%_Plugin_Collection::customWidgets() const
{
    return widgets;
}
