/*
QWebSockets implements the WebSocket protocol as defined in RFC 6455.
Copyright (C) 2013 Kurt Pattyn (pattyn.kurt@gmail.com)

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef QWEBSOCKETHANDSHAKEREQUEST_P_H
#define QWEBSOCKETHANDSHAKEREQUEST_P_H
//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QObject>
#include <QMap>
#include <QString>
#include <QUrl>

#include "qwebsocketprotocol.h"

QT_BEGIN_NAMESPACE

class QTextStream;

class Q_AUTOTEST_EXPORT QWebSocketHandshakeRequest
{
    Q_DISABLE_COPY(QWebSocketHandshakeRequest)

public:
    QWebSocketHandshakeRequest(int port, bool isSecure);
    virtual ~QWebSocketHandshakeRequest();

    void clear();

    int port() const;
    bool isSecure() const;
    bool isValid() const;
    QMap<QString, QString> headers() const;
    QList<QWebSocketProtocol::Version> versions() const;
    QString key() const;
    QString origin() const;
    QList<QString> protocols() const;
    QList<QString> extensions() const;
    QUrl requestUrl() const;
    QString resourceName() const;
    QString host() const;

private:
    QTextStream &readFromStream(QTextStream &textStream);
    friend QTextStream &operator >>(QTextStream &stream, QWebSocketHandshakeRequest &request);

    int m_port;
    bool m_isSecure;
    bool m_isValid;
    QMap<QString, QString> m_headers;
    QList<QWebSocketProtocol::Version> m_versions;
    QString m_key;
    QString m_origin;
    QList<QString> m_protocols;
    QList<QString> m_extensions;
    QUrl m_requestUrl;
};

QTextStream & Q_AUTOTEST_EXPORT operator >>(QTextStream &stream, QWebSocketHandshakeRequest &request);

QT_END_NAMESPACE

#endif // QWEBSOCKETHANDSHAKEREQUEST_P_H
