#ifndef ITOJSON_H
#define ITOJSON_H
#include <QJsonObject>

class IToJson
{
public:
    virtual QJsonObject toJson() const = 0;
};

#endif // ITOJSON_H
