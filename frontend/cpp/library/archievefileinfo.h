#ifndef ARCHIEVEFILEINFO_H
#define ARCHIEVEFILEINFO_H

#include "gamefileinfo.h"
#include "systemdatabase.h"

#include "quazip.h"

namespace Library {

    class ArchieveFileInfo : public GameFileInfo {
    public:

        ArchieveFileInfo( const QString &file );
        ArchieveFileInfo( GameFileInfo &gameInfo );

        bool firstFile();
        bool nextFile();
        bool isValid() const;
        bool open( QuaZip::Mode mode );


        void close();

        QString nextFileName() const;
        static QString delimiter();

    private:
         QStringList mChecksums;
         QuaZip *mZipFile;
         QSqlQuery mQuery;
         bool mIsValid;

         void update();


    };

}

#endif // ARCHIEVEFILEINFO_H
