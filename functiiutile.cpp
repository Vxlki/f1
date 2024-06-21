#include "functiiutile.h"

FunctiiUtile::FunctiiUtile() {}

void FunctiiUtile::setBlankSpaceToUnderline(QString& str)
{
    for(int i=0;i<str.size();i++)
    {
        if(str[i]==' ')
            str[i]='_';
    }
}

void FunctiiUtile::setUnderlinetoBlankSpace(QString& str)
{
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='_')
            str[i]=' ';
    }
}
