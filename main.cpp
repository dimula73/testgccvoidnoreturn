/*
 *  Copyright (c) 2017 Dmitry Kazakov <dimula73@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include <QLinearGradient>

struct GradientHandle {
    enum Type {
        None,
        LinearStart,
        LinearEnd,
        RadialCenter,
        RadialRadius,
        RadialFocalPoint
    };

    GradientHandle() : type(None) {}
    GradientHandle(Type t, const QPointF &p) : type(t), pos(p) {}

    Type type;
    QPointF pos;
};

struct ShapeGradientHandles {
    ShapeGradientHandles()
    {
    }

    QVector<GradientHandle> handles() const {
        QVector<GradientHandle> result;

        const QGradient *g = gradient();
        if (!g) return result;

        switch (g->type()) {
        case QGradient::LinearGradient: {
            const QLinearGradient *lgradient = static_cast<const QLinearGradient*>(g);
            result << GradientHandle(GradientHandle::LinearStart, lgradient->start());
            result << GradientHandle(GradientHandle::LinearEnd, lgradient->finalStop());
            break;
        }
        case QGradient::RadialGradient: {
            break;
        }
        case QGradient::ConicalGradient:
            // not supported
            break;
        case QGradient::NoGradient:
            // not supported
            break;
        }

        // XXX: why the hell it compiles!?????????
        //return result;
    }

private:
    const QGradient* gradient() const {
        QLinearGradient *g = new QLinearGradient();


        return g;
    }
};

int main(int argc, char *argv[])
{
    ShapeGradientHandles b;
    QVector<GradientHandle> h = b.handles();

    return 0;
}
